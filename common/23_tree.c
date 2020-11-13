/**
 * 23_tree.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/14 下午3:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <23_tree.h>
#include <print.h>

static int max(int a, int b) {
    return a > b ? a : b;
}
static int min(int a, int b) {
    return a < b ? a : b;
}
static _23_tree_t _23_tree_node_new(int val, _23_tree_t parent) {
    _23_tree_t t = calloc(1, sizeof(struct _23_TreeNode));
    t->val[0] = val, t->count = 2, t->parent = parent;
    return t;
}
static void _23_tree_node_destroy(_23_tree_t *tree) {
    free(*tree);
    *tree = NULL;
}

_23_tree_t _23_tree_create_size(const int arr[], size_t len) {
    _23_tree_t t = NULL;
    for (int i = 0; i < len; ++i) {
        _23_tree_add(&t, arr[i]);
    }
    return t;
}

bool _23_tree_add(_23_tree_t *tree, int val) {
    _23_tree_t cur = *tree;
    if (!cur) {
        *tree = _23_tree_node_new(val, NULL);
        return true;
    }

    // 找到待插入位置
    for (_23_tree_t next = cur; next;) {
        cur = next;
        if (val == cur->val[0] || val == cur->val[cur->count - 2]) return false;
        if (val < cur->val[0]) {
            next = cur->children[0];
        } else if (val > cur->val[cur->count - 2]) {
            next = cur->children[cur->count - 1];
        } else {
            next = cur->children[1];
        }
    }

    _23_tree_t child = NULL;
    for (_23_tree_t new = NULL; cur->count > 2; cur = cur->parent, child = new) {
        int a = min(val, cur->val[0]), c = max(val, cur->val[1]);
        int b = min(max(val, cur->val[0]), cur->val[1]);

        cur->count = 2, cur->val[0] = a;
        new = _23_tree_node_new(c, cur->parent);
        memcpy(new->children, &cur->children[1], 2 * sizeof(_23_tree_t));

        if (val == cur->val[0]) {
            cur->children[1] = child;
        } else if (val == new->val[0]) {
            new->children[0] = cur->children[2];
            new->children[1] = child;
        } else {
            new->children[0] = child;
        }
        val = b;
        for (int i = 0; i < new->count; ++i) {
            if (!new->children[i]) break;
            new->children[i]->parent = new;
        }

        // 回溯到根节点
        if (!cur->parent) {
            *tree       = _23_tree_node_new(val, NULL);
            cur->parent = new->parent = *tree;
            cur->parent->children[0] = cur, cur->parent->children[1] = new;
            return true;
        }
    }

    cur->count = 3;
    if (val > cur->val[0]) {
        cur->val[1] = val, cur->children[2] = child;
    } else {
        cur->val[1] = cur->val[0], cur->children[2] = cur->children[1];
        cur->val[0] = val, cur->children[1] = child;
    }
    return true;
}

bool _23_tree_del(_23_tree_t *tree, int val) {
    _23_tree_t cur = _23_tree_find(*tree, val);
    if (!cur) return false;

    // 保证待删除节点是叶子节点
    if (cur->children[0]) {
        _23_tree_t next = cur->children[1 + (val != cur->val[0])];
        for (; next->children[0]; next = next->children[0]) {}
        cur->val[val != cur->val[0]] = next->val[0], next->val[0] = val, cur = next;
    }

    // 3节点直接删除
    if (cur->count == 3) {
        cur->count -= 1;
        if (cur->val[0] == val) cur->val[0] = cur->val[1];
        return true;
    }

    // 2节点分情况处理
    for (_23_tree_t parent, child = NULL, brother; cur->count == 2; cur = parent, child = brother) {
        // 根节点
        if (!(parent = cur->parent)) {
            *tree = child;
            if (child) child->parent = NULL;
            _23_tree_node_destroy(&cur);
            break;
        }

        // 尽可能找到一个3节点的兄弟
        brother = NULL;
        for (int i = 0; i < parent->count; ++i) {
            if (parent->children[i] == cur) continue;
            brother = parent->children[i];
            if (brother->count == 3) break;
        }

        if (brother->count == 3) {                // 兄弟是3节点
            if (cur->val[0] < brother->val[0]) {  // 兄弟节点在右侧
                if (cur == parent->children[0]) { // 当前节点是左孩子
                    cur->val[0] = parent->val[0], parent->val[0] = parent->children[1]->val[0];
                    cur->children[0] = child, cur->children[1] = parent->children[1]->children[0];
                    if (parent->children[1] != brother) { // 中孩子不是给出的兄弟节点，说明中孩子也是2节点
                        parent->children[1]->val[0] = parent->val[1], parent->val[1] = brother->val[0];
                        parent->children[1]->children[0] = parent->children[1]->children[1];
                        parent->children[1]->children[1] = brother->children[0];
                        if (brother->children[0]) brother->children[0]->parent = parent->children[1];
                    }
                    brother->children[0] = brother->children[1], brother->children[1] = brother->children[2];
                } else { // 当前节点只能是中孩子
                    cur->val[0] = parent->val[1], parent->val[1] = brother->val[0];
                    cur->children[0] = child, cur->children[1] = brother->children[0];
                    brother->children[0] = brother->children[1], brother->children[1] = brother->children[2];
                }
                brother->count -= 1, brother->val[0] = brother->val[1];
            } else {                      // 兄弟节点在左侧
                if (parent->count == 2) { // 父亲是2节点
                    cur->val[0] = parent->val[0], parent->val[0] = brother->val[1];
                    cur->children[1] = child, cur->children[0] = brother->children[2];
                } else if (cur == parent->children[2]) { // 父亲是3节点，当前节点是右孩子
                    cur->val[0]      = parent->val[1];
                    cur->children[1] = child;
                    if (parent->children[1]->count == 3) { // 如果中孩子也是3节点，把中孩子作为兄弟节点进行即可
                        brother = parent->children[1], parent->val[1] = brother->val[1];
                        cur->children[0] = brother->children[2];
                    } else { // 兄弟节点是左孩子，且中孩子也是2节点
                        parent->val[1]              = parent->children[1]->val[0];
                        parent->children[1]->val[0] = parent->val[0];
                        parent->val[0]              = brother->val[1];
                        if (child) {
                            cur->children[0]                 = parent->children[1]->children[1];
                            parent->children[1]->children[1] = parent->children[1]->children[0];
                            parent->children[1]->children[0] = brother->children[2];
                            brother->children[2]->parent     = parent->children[1];
                        }
                    }
                } else { // 父亲是3节点，当前节点是中孩子
                    cur->val[0] = parent->val[0], parent->val[0] = brother->val[1];
                    cur->children[0] = brother->children[2], cur->children[1] = child;
                }
                brother->count -= 1;
            }
            for (int i = 0; i < cur->count; ++i) {
                if (cur->children[i]) cur->children[i]->parent = cur;
            }
            break;
        }

        if (parent->count == 3) {             // 兄弟都是2节点，父亲是3节点
            if (cur == parent->children[2]) { // 当前是右孩子
                parent->children[1]->val[1] = parent->val[1];
                if (child) parent->children[1]->children[2] = child, child->parent = parent->children[1];
            } else if (cur == parent->children[1]) { // 当前是中孩子
                cur->val[0] = parent->val[1];
                cur->val[1] = parent->children[2]->val[0];
                if (child) {
                    cur->children[0] = child;
                    cur->children[1] = parent->children[2]->children[0];
                    cur->children[2] = parent->children[2]->children[1];
                    for (int i = 0; i < 3; ++i) {
                        cur->children[i]->parent = cur;
                    }
                }
            } else { // 当前是左孩子
                cur->val[0] = parent->val[0], parent->val[0] = parent->children[1]->val[0];
                parent->children[1]->val[0] = parent->val[1];
                parent->children[1]->val[1] = parent->children[2]->val[0];
                if (child) {
                    cur->children[0] = child, child->parent = cur;
                    cur->children[1] = parent->children[1]->children[0], parent->children[1]->children[0]->parent = cur;
                    parent->children[1]->children[0] = parent->children[1]->children[1];
                    parent->children[1]->children[1] = parent->children[2]->children[0];
                    parent->children[1]->children[2] = parent->children[2]->children[1];
                    for (int i = 0; i < 3; ++i) {
                        parent->children[1]->children[i]->parent = parent->children[1];
                    }
                }
            }
            parent->count = 2, parent->children[1]->count = 3;
            _23_tree_node_destroy(&parent->children[2]);
            break;
        }

        // 只剩下父兄均为2节点的可能，此时合并父兄节点到兄弟，然后向上回溯删除父亲节点
        brother->count = 3;
        if (child) child->parent = brother;
        if (brother->val[0] < parent->val[0]) {
            brother->val[1]      = parent->val[0];
            brother->children[2] = child;
        } else {
            brother->val[1]      = brother->val[0];
            brother->val[0]      = parent->val[0];
            brother->children[2] = brother->children[1];
            brother->children[1] = brother->children[0];
            brother->children[0] = child;
        }
        _23_tree_node_destroy(&cur);
    }

    return true;
}

void _23_tree_free(_23_tree_t t) {
    if (!t) return;
    for (int i = 0; i < t->count; ++i) {
        _23_tree_free(t->children[i]);
    }
    _23_tree_node_destroy(&t);
}

bool _23_tree_equal(_23_tree_t t1, _23_tree_t t2) {
    if (t1 == t2) return true;
    if (!t1 || !t2) return false;

    if (t1->count != t2->count) return false;
    if (t1->val[0] != t2->val[0]) return false;
    if (t1->val[t1->count - 2] != t2->val[t2->count - 2]) return false;
    for (int i = 0; i < t1->count; ++i) {
        if (!_23_tree_equal(t1->children[i], t2->children[i])) return false;
    }
    return true;
}

_23_tree_t _23_tree_find(_23_tree_t t, int val) {
    if (!t) return NULL;
    for (int i = 0; i < t->count - 1; ++i) {
        if (t->val[i] == val) return t;
    }
    if (val < t->val[0]) return _23_tree_find(t->children[0], val);
    if (val > t->val[t->count - 2]) return _23_tree_find(t->children[t->count - 1], val);
    return _23_tree_find(t->children[1], val);
}

static void _23_tree_node_print(void *tree) {
    _23_tree_t t = tree;

    if (t->count > 2) {
        printf("%d, %d", t->val[0], t->val[1]);
    } else {
        printf("%d", t->val[0]);
    }
}
void _23_tree_print(_23_tree_t t) {
    int count_offset = offsetof(struct _23_TreeNode, count);
    int point_offset = offsetof(struct _23_TreeNode, children);
    print_dynamic_tree(t, count_offset, point_offset, 0x1000, _23_tree_node_print);
}