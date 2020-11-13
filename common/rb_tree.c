/**
 * rb_tree.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/17 下午3:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <rb_tree.h>
#include <print.h>

static int max(int a, int b) {
    return a > b ? a : b;
}
static rb_tree_t rb_tree_node_new(int val, rb_tree_t parent, rb_tree_color_t color) {
    rb_tree_t tree = calloc(1, sizeof(struct RBTreeNode));
    tree->val = val, tree->parent = parent, tree->color = color;
    return tree;
}
static void rb_tree_node_destroy(rb_tree_t *tree) {
    free(*tree);
    *tree = NULL;
}
static rb_tree_t rb_tree_create_size_real(const int arr[], size_t len, rb_tree_t parent, rb_tree_color_t color) {
    if (!len) return NULL;
    size_t mid = len / 2;

    rb_tree_t t = rb_tree_node_new(arr[mid], parent, color);
    if (mid) t->left = rb_tree_create_size_real(arr, mid, t, !color);
    if (mid + 1 < len) t->right = rb_tree_create_size_real(arr + mid + 1, len - mid - 1, t, !color);

    return t;
}
static void rb_tree_left_rotate(rb_tree_t t) {
    rb_tree_t child = t->right;
    if (child->left) child->left->parent = t;
    if (t->parent) {
        if (t->parent->left == t) {
            t->parent->left = child;
        } else {
            t->parent->right = child;
        }
    }
    t->right = child->left, child->left = t;
    child->parent = t->parent, t->parent = child;
}
static void rb_tree_right_rotate(rb_tree_t t) {
    rb_tree_t child = t->left;
    if (child->right) child->right->parent = t;
    if (t->parent) {
        if (t->parent->left == t) {
            t->parent->left = child;
        } else {
            t->parent->right = child;
        }
    }
    t->left = child->right, child->right = t;
    child->parent = t->parent, t->parent = child;
}

rb_tree_t rb_tree_create_size(const int arr[], size_t len) {
    return rb_tree_create_size_real(arr, len, NULL, BLACK);
}

bool rb_tree_add(rb_tree_t *tree, int val) {
    rb_tree_t cur = *tree, parent = NULL;
    if (!cur) {
        *tree = rb_tree_node_new(val, NULL, BLACK);
        return true;
    }
    for (; cur; parent = cur, cur = cur->val > val ? cur->left : cur->right) {
        if (cur->val == val) return false;
    }
    cur = rb_tree_node_new(val, parent, RED);
    if (parent->val > val) {
        parent->left = cur;
    } else {
        parent->right = cur;
    }
    while (parent && parent->color == RED) {
        rb_tree_t grand_parent = parent->parent, uncle = NULL;
        uncle = grand_parent->left != parent ? grand_parent->left : grand_parent->right;

        if (rb_tree_color(uncle) == RED) {
            parent->color = uncle->color = BLACK, grand_parent->color = RED;
            cur = grand_parent, parent = cur->parent;
            // 回溯到根节点，将根节点改为黑色
            if (!parent) cur->color = BLACK;
            continue;
        }
        bool right = parent->right == cur;
        if (grand_parent->left == parent) {
            if (right) {
                rb_tree_left_rotate(parent);
                parent = cur;
            }
            rb_tree_right_rotate(grand_parent);
        } else {
            if (!right) {
                rb_tree_right_rotate(parent);
                parent = cur;
            }
            rb_tree_left_rotate(grand_parent);
        }
        parent->color = BLACK, grand_parent->color = RED;
        if (!parent->parent) *tree = parent;
    }
    return true;
}

bool rb_tree_del(rb_tree_t *tree, int val) {
    rb_tree_t cur = *tree;
    for (; cur && cur->val != val; cur = cur->val > val ? cur->left : cur->right) {}
    if (!cur) return false;

    // 保证待删除节点最多拥有一个孩子
    if (cur->left && cur->right) {
        rb_tree_t next = cur->right;
        for (; next->left; next = next->left) {}
        cur->val = next->val, cur = next;
    }

    // 当前节点有孩子？当前必然为黑色，孩子必然为单独的红色节点
    if (cur->left || cur->right) {
        rb_tree_t child = cur->left ? cur->left : cur->right;
        cur->val = child->val, cur->left = cur->right = NULL;
        rb_tree_node_destroy(&child);
        return true;
    }

    // 当前为红色？直接删除
    if (rb_tree_color(cur) == RED) {
        if (cur->parent->left == cur) {
            cur->parent->left = NULL;
        } else {
            cur->parent->right = NULL;
        }
        rb_tree_node_destroy(&cur);
        return true;
    }

    for (rb_tree_t current = cur, brother, parent; current->parent;) {
        parent = current->parent, brother = current == parent->left ? parent->right : parent->left;

        /// 红兄，此时父侄必然黑色，对父亲节点旋转，转换为黑兄情况
        if (rb_tree_color(brother) == RED) {
            if (brother == parent->left) {
                rb_tree_right_rotate(parent);
            } else {
                rb_tree_left_rotate(parent);
            }
            if (!brother->parent) *tree = brother;
            parent->color = RED, brother->color = BLACK;
            continue;
        }

        /// 黑兄红侄
        if (rb_tree_color(brother->left) == RED || rb_tree_color(brother->right) == RED) {
            if (brother == parent->right) {
                if (rb_tree_color(brother->right) == BLACK) {
                    brother->color = RED, brother->left->color = BLACK;
                    rb_tree_right_rotate(brother);
                    brother = brother->parent;
                }
                rb_tree_left_rotate(parent);
                brother->right->color = BLACK;
            } else {
                if (rb_tree_color(brother->left) == BLACK) {
                    brother->color = RED, brother->right->color = BLACK;
                    rb_tree_left_rotate(brother);
                    brother = brother->parent;
                }
                rb_tree_right_rotate(parent);
                brother->left->color = BLACK;
            }
            if (!brother->parent) *tree = brother;
            brother->color = parent->color, parent->color = BLACK;
            break;
        }

        /// 黑兄黑侄红父
        if (rb_tree_color(parent) == RED) {
            brother->color = RED, parent->color = BLACK;
            break;
        }

        /// 黑兄黑侄黑父，无法平衡，向祖先回溯
        brother->color = RED, current = current->parent;
    }

    // 当前为根节点？直接删除
    if (!cur->parent) {
        rb_tree_node_destroy(tree);
    } else if (cur == cur->parent->left) {
        rb_tree_node_destroy(&cur->parent->left);
    } else {
        rb_tree_node_destroy(&cur->parent->right);
    }

    return true;
}

rb_tree_color_t rb_tree_color(rb_tree_t t) {
    return t ? t->color : BLACK;
}

void rb_tree_free(rb_tree_t t) {
    if (!t) return;
    rb_tree_free(t->left);
    rb_tree_free(t->right);
    rb_tree_node_destroy(&t);
}

bool rb_tree_equal(rb_tree_t t1, rb_tree_t t2) {
    if (t1 == t2) return true;
    if (!t1 || !t2) return false;

    return t1->val == t2->val && rb_tree_equal(t1->left, t2->left) && rb_tree_equal(t1->right, t2->right);
}

rb_tree_t rb_tree_find(rb_tree_t t, int val) {
    if (!t || t->val == val) return t;
    return rb_tree_find(val < t->val ? t->left : t->right, val);
}

static void rb_tree_node_print(void *tree) {
    rb_tree_t t = tree;
    printf("[%d, %c, ", t->val, "br"[t->color]);
    if (t->parent) {
        printf("%d", t->parent->val);
    } else {
        printf("INF");
    }
    putchar(']');
}
void rb_tree_print(rb_tree_t t) {
    int offsets[] = { offsetof(struct RBTreeNode, left), offsetof(struct RBTreeNode, right) };
    print_static_tree(t, offsets, LEN(offsets), 0x1000, rb_tree_node_print);
}
