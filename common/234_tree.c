/**
 * 234_tree.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/27 下午3:22
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <234_tree.h>
#include <print.h>

static _234_tree_t _234_tree_node_new(int val, _234_tree_t parent) {
    _234_tree_t t = calloc(1, sizeof(struct _234_TreeNode));
    t->val[0] = val, t->count = 2, t->parent = parent, t->children = calloc(4, sizeof(_234_tree_t));
    return t;
}
static int _234_tree_find_index(_234_tree_t tree, int val) {
    int index = 0;
    for (; index < tree->count - 1 && val > tree->val[index]; ++index) {}
    return index;
}
static void _234_tree_node_destroy(_234_tree_t *tree) {
    free((*tree)->children);
    free(*tree);
    *tree = NULL;
}

_234_tree_t _234_tree_create_size(const int arr[], size_t len) {
    _234_tree_t t = NULL;
    for (int i = 0; i < len; ++i) {
        _234_tree_add(&t, arr[i]);
    }
    return t;
}

bool _234_tree_add(_234_tree_t *tree, int val) {
    _234_tree_t cur = *tree;
    if (!cur) {
        *tree = _234_tree_node_new(val, NULL);
        return true;
    }

    int index = 0;
    for (_234_tree_t next = cur; next; next = cur->children[index]) {
        if (cur = next, cur->count == 4) { // 将4节点拆分为两个个2节点
            _234_tree_t parent = cur->parent, brother = _234_tree_node_new(cur->val[2], parent);

            cur->count = 2;
            memcpy(brother->children, &cur->children[2], 2 * sizeof(_234_tree_t));
            for (int i = 0; i < brother->count; ++i) {
                if (!brother->children[i]) break;
                brother->children[i]->parent = brother;
            }

            if (parent) {
                index = _234_tree_find_index(cur->parent, cur->val[1]);
                memmove(&parent->val[index + 1], &parent->val[index], (parent->count - index - 1) * sizeof(int));
                memmove(&parent->children[index + 2], &parent->children[index + 1],
                        (parent->count - index - 1) * sizeof(_234_tree_t));
                parent->count += 1, parent->val[index] = cur->val[1], parent->children[index + 1] = brother;
            } else {
                parent              = _234_tree_node_new(cur->val[1], NULL);
                parent->children[0] = cur, parent->children[1] = brother;
                *tree = cur->parent = brother->parent = parent;
            }
            cur = cur->parent;
        }
        if (index = _234_tree_find_index(cur, val), val == cur->val[index]) return false;
    }

    memmove(&cur->val[index + 1], &cur->val[index], (cur->count - index - 1) * sizeof(int));
    cur->count += 1, cur->val[index] = val;

    return true;
}

bool _234_tree_del(_234_tree_t *tree, int val) {
    _234_tree_t cur = *tree;
    if (!cur) return false;

    // 保证孩子至少有一个不是2节点
    if (cur->count == 2 && cur->children[0] && cur->children[0]->count == 2 && cur->children[1]->count == 2) {
        struct _234_TreeNode node = (struct _234_TreeNode) {
            .count    = 4,
            .val      = { cur->children[0]->val[0], cur->val[0], cur->children[1]->val[0] },
            .children = (_234_tree_t[]) { cur->children[0]->children[0], cur->children[0]->children[1],
                                          cur->children[1]->children[0], cur->children[1]->children[1] }
        };
        _234_tree_node_destroy(&cur->children[0]), _234_tree_node_destroy(&cur->children[1]);
        if (node.children[0]) {
            for (int i = 0; i < node.count; node.children[i++]->parent = cur) {}
        }
        memcpy(cur->val, node.val, 3 * sizeof(int));
        memcpy(cur->children, node.children, (cur->count = node.count) * sizeof(_234_tree_t));
    }

    int index;
    for (_234_tree_t child = NULL;; cur = child) {
        child = cur->children[index = _234_tree_find_index(cur, val)];

        // 找到叶子节点了，执行删除逻辑
        if (!child) {
            if (index + 1 == cur->count || val != cur->val[index]) return false;
            if (cur->count -= 1, cur->count < 2) { // 只有根节点会是2节点
                _234_tree_node_destroy(tree);
            } else {
                memmove(&cur->val[index], &cur->val[index + 1], (cur->count - index - 1) * sizeof(int));
            }
            break;
        }

        // 待查找节点不在叶子节点上，交换
        if (index + 1 < cur->count && val == cur->val[index]) {
            _234_tree_t swap = child = cur->children[++index];
            for (; swap->children[0]; swap = swap->children[0]) {}
            val = cur->val[index - 1] = swap->val[0];
        }

        // 后驱不是2节点，不必处理
        if (child->count != 2) continue;

        // 向父兄节点请求帮助，保证后驱不是2节点
        _234_tree_t brother = cur->children[index ? index - 1 : 1];
        if (brother->count == 2) { // 兄弟也是2节点？合并为4节点
            if (index) {           // 兄弟在左侧
                child->val[2] = child->val[0], child->val[1] = cur->val[index - 1], child->val[0] = brother->val[0];
                memmove(&cur->val[index - 1], &cur->val[index], (cur->count - index - 1) * sizeof(int));
                memmove(&cur->children[index - 1], &cur->children[index], (cur->count - index) * sizeof(_234_tree_t));
                if (child->children[0]) {
                    brother->children[0]->parent = brother->children[1]->parent = child;
                    memmove(&child->children[2], &child->children[0], child->count * sizeof(_234_tree_t));
                    memcpy(&child->children[0], &brother->children[0], brother->count * sizeof(_234_tree_t));
                }
            } else { // 兄弟在右侧
                child->val[1] = cur->val[0], child->val[2] = brother->val[0];
                memmove(&cur->val[0], &cur->val[1], (cur->count - 2) * sizeof(int));
                memmove(&cur->children[1], &cur->children[2], (cur->count - 2) * sizeof(_234_tree_t));
                if (child->children[0]) {
                    brother->children[0]->parent = brother->children[1]->parent = child;
                    memcpy(&child->children[2], &brother->children[0], brother->count * sizeof(_234_tree_t));
                }
            }
            child->count = 4, cur->count -= 1;
            _234_tree_node_destroy(&brother);
        } else {         // 兄弟不是2节点？合并为3节点
            if (index) { // 兄弟在左侧
                child->val[1] = child->val[0], child->val[0] = cur->val[index - 1],
                cur->val[index - 1] = brother->val[brother->count - 2];
                if (child->children[0]) {
                    memmove(&child->children[1], &child->children[0], child->count * sizeof(_234_tree_t));
                    child->children[0] = brother->children[brother->count - 1], child->children[0]->parent = child;
                }
            } else { // 兄弟在右侧
                child->val[1] = cur->val[0], cur->val[0] = brother->val[0];
                memmove(&brother->val[0], &brother->val[1], (brother->count - 2) * sizeof(int));
                if (child->children[0]) {
                    child->children[2] = brother->children[0], child->children[2]->parent = child;
                    memmove(&brother->children[0], &brother->children[1], (brother->count - 1) * sizeof(_234_tree_t));
                }
            }
            child->count = 3, brother->count -= 1;
        }
    }

    return true;
}

void _234_tree_free(_234_tree_t t) {
    if (!t) return;
    for (int i = 0; i < t->count; ++i) {
        _234_tree_free(t->children[i]);
    }
    _234_tree_node_destroy(&t);
}

bool _234_tree_equal(_234_tree_t t1, _234_tree_t t2) {
    if (t1 == t2) return true;
    if (!t1 || !t2) return false;

    if (t1->count != t2->count) return false;
    if (t1->val[0] != t2->val[0]) return false;
    if (t1->val[t1->count - 2] != t2->val[t2->count - 2]) return false;
    for (int i = 0; i < t1->count - 1; ++i) {
        if (t1->val[i] != t2->val[i]) return false;
    }
    for (int i = 0; i < t1->count; ++i) {
        if (!_234_tree_equal(t1->children[i], t2->children[i])) return false;
    }
    return true;
}

_234_tree_t _234_tree_find(_234_tree_t t, int val) {
    if (!t) return NULL;
    for (int i = 0; i < t->count - 1; ++i) {
        if (val < t->val[i]) return _234_tree_find(t->children[i], val);
        if (val == t->val[i]) return t;
    }
    return _234_tree_find(t->children[t->count - 1], val);
}

static void _234_tree_node_print(void *tree) {
    _234_tree_t t = tree;

    for (int i = 0; i < t->count - 1; ++i) {
        printf("%d", t->val[i]);
        if (i + 2 < t->count) printf(", ");
    }
    if (t->parent) {
        printf(" -> %d", t->parent->val[0]);
    } else {
        printf(" -> INF");
    }
}
void _234_tree_print(_234_tree_t t) {
    int count_offset = offsetof(struct _234_TreeNode, count);
    int point_offset = offsetof(struct _234_TreeNode, children);
    print_dynamic_tree(t, count_offset, point_offset, 0x1000, _234_tree_node_print);
}