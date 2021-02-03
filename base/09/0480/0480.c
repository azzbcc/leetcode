// 中位数是有序序列最中间的那个数。如果序列的长度是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。
//
// 例如：
//
//
// [2,3,4]，中位数是 3
// [2,3]，中位数是 (2 + 3) / 2 = 2.5
//
//
// 给你一个数组 nums，有一个长度为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1
// 位。你的任务是找出每次窗口移动后得到的新窗 口中元素的中位数，并输出由它们组成的数组。
//
//
//
// 示例：
//
// 给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。
//
//
// 窗口位置                      中位数
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       1
//  1 [3  -1  -3] 5  3  6  7      -1
//  1  3 [-1  -3  5] 3  6  7      -1
//  1  3  -1 [-3  5  3] 6  7       3
//  1  3  -1  -3 [5  3  6] 7       5
//  1  3  -1  -3  5 [3  6  7]      6
//
//
// 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。
//
//
//
// 提示：
//
//
// 你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。
// 与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。
//
// Related Topics Sliding Window
// 👍 173 👎 0

typedef struct rb_tree_node_t {
    bool red;
    int val, count;
    struct rb_tree_node_t *left, *right, *parent;
} rb_tree_t;
static rb_tree_t *rb_tree_node_new(int val, rb_tree_t *parent, bool red) {
    rb_tree_t *t = malloc(sizeof(rb_tree_t));
    t->val = val, t->count = 1, t->red = red;
    t->parent = parent, t->left = t->right = NULL;
    return t;
}
static void rb_tree_node_destroy(rb_tree_t **t) {
    if (!t || !*t) return;
    free(*t);
    *t = NULL;
}
void rb_tree_destroy(rb_tree_t *t) {
    if (!t) return;
    rb_tree_destroy(t->left);
    rb_tree_destroy(t->right);
    rb_tree_node_destroy(&t);
}
bool rb_tree_red(rb_tree_t *t) {
    return t ? t->red : false;
}
rb_tree_t *rb_tree_prev(rb_tree_t *cur) {
    if (cur->left) {
        for (cur = cur->left; cur->right; cur = cur->right) {}
    } else {
        rb_tree_t *last = cur;
        for (cur = cur->parent; cur && cur->left == last; last = cur, cur = cur->parent) {}
    }
    return cur;
}
rb_tree_t *rb_tree_next(rb_tree_t *cur) {
    if (cur->right) {
        for (cur = cur->right; cur->left; cur = cur->left) {}
    } else {
        rb_tree_t *last = cur;
        for (cur = cur->parent; cur && cur->right == last; last = cur, cur = cur->parent) {}
    }
    return cur;
}
static void rb_tree_left_rotate(rb_tree_t *t) {
    rb_tree_t *child = t->right;
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
static void rb_tree_right_rotate(rb_tree_t *t) {
    rb_tree_t *child = t->left;
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
void rb_tree_add(rb_tree_t **tree, int val) {
    rb_tree_t *cur = *tree, *parent = NULL;
    if (!cur) {
        *tree = rb_tree_node_new(val, NULL, false);
        return;
    }
    for (; cur; parent = cur, cur = cur->val > val ? cur->left : cur->right) {
        if (cur->val == val) {
            cur->count += 1;
            return;
        }
    }
    cur = rb_tree_node_new(val, parent, true);
    if (parent->val > val) {
        parent->left = cur;
    } else {
        parent->right = cur;
    }
    while (parent && rb_tree_red(parent)) {
        rb_tree_t *grand_parent = parent->parent, *uncle = NULL;
        uncle = grand_parent->left != parent ? grand_parent->left : grand_parent->right;

        if (rb_tree_red(uncle)) {
            parent->red = uncle->red = false, grand_parent->red = true;
            cur = grand_parent, parent = cur->parent;
            if (!parent) cur->red = false;
            continue;
        }
        if (grand_parent->left == parent) {
            if (parent->right == cur) {
                rb_tree_left_rotate(parent);
                parent = cur;
            }
            rb_tree_right_rotate(grand_parent);
        } else {
            if (parent->left == cur) {
                rb_tree_right_rotate(parent);
                parent = cur;
            }
            rb_tree_left_rotate(grand_parent);
        }
        parent->red = false, grand_parent->red = true;
        if (!parent->parent) *tree = parent;
    }
}
rb_tree_t *rb_tree_find(rb_tree_t *t, int val) {
    if (!t || t->val == val) return t;
    return rb_tree_find(val < t->val ? t->left : t->right, val);
}
void rb_tree_swap(rb_tree_t **tree, rb_tree_t *swap) {
    int relation = 0;
    rb_tree_t *a = swap, *b = rb_tree_next(swap);

#define SWAP(type_t, member)                                                                                           \
    do {                                                                                                               \
        type_t member = a->member;                                                                                     \
        a->member     = b->member;                                                                                     \
        b->member     = member;                                                                                        \
    } while (0)

    SWAP(bool, red);
    if (a->right == b) relation = 1;
    if (b->left == a) relation = 2;
    if (relation != 2) {
        if (!a->parent) {
            *tree = b;
        } else if (a->parent->left == a) {
            a->parent->left = b;
        } else {
            a->parent->right = b;
        }
    }
    if (a->left) a->left->parent = b;
    if (relation != 1 && a->right) a->right->parent = b;
    if (relation != 1) {
        if (!b->parent) {
            *tree = a;
        } else if (b->parent->left == b) {
            b->parent->left = a;
        } else {
            b->parent->right = a;
        }
    }
    if (relation != 2 && b->left) b->left->parent = a;
    if (b->right) b->right->parent = a;
    if (relation != 2) SWAP(rb_tree_t *, left);
    if (relation != 1) SWAP(rb_tree_t *, right);
    if (relation == 0) SWAP(rb_tree_t *, parent);
    if (relation == 1) {
        b->parent = a->parent, a->parent = b;
        a->right = b->right, b->right = a;
    } else if (relation == 2) {
        a->parent = b->parent, b->parent = a;
        b->left = a->left, a->left = b;
    }
#undef SWAP
}
void rb_tree_del(rb_tree_t **tree, int val) {
    rb_tree_t *cur = *tree;
    for (; cur && cur->val != val; cur = cur->val > val ? cur->left : cur->right) {}
    if (!cur) return;

    // 保证待删除节点最多拥有一个孩子
    if (cur->left && cur->right) rb_tree_swap(tree, cur);

    // 当前节点有孩子？当前必然为黑色，孩子必然为单独的红色节点
    if (cur->left) {
        rb_tree_swap(tree, cur->left);
        rb_tree_node_destroy(&cur->parent->left);
        return;
    }
    if (cur->right) {
        rb_tree_swap(tree, cur);
        rb_tree_node_destroy(&cur->parent->right);
        return;
    }

    // 当前为红色？直接删除
    if (rb_tree_red(cur)) goto end;

    for (rb_tree_t *current = cur, *brother, *parent; current->parent;) {
        parent = current->parent, brother = current == parent->left ? parent->right : parent->left;

        /// 红兄，此时父侄必然黑色，对父亲节点旋转，转换为黑兄情况
        if (rb_tree_red(brother)) {
            if (brother == parent->left) {
                rb_tree_right_rotate(parent);
            } else {
                rb_tree_left_rotate(parent);
            }
            if (!brother->parent) *tree = brother;
            parent->red = true, brother->red = false;
            continue;
        }

        /// 黑兄红侄
        if (rb_tree_red(brother->left) || rb_tree_red(brother->right)) {
            if (brother == parent->right) {
                if (!rb_tree_red(brother->right)) {
                    brother->red = true, brother->left->red = false;
                    rb_tree_right_rotate(brother);
                    brother = brother->parent;
                }
                rb_tree_left_rotate(parent);
                brother->right->red = false;
            } else {
                if (!rb_tree_red(brother->left)) {
                    brother->red = true, brother->right->red = false;
                    rb_tree_left_rotate(brother);
                    brother = brother->parent;
                }
                rb_tree_right_rotate(parent);
                brother->left->red = false;
            }
            if (!brother->parent) *tree = brother;
            brother->red = parent->red, parent->red = false;
            break;
        }

        /// 黑兄黑侄红父
        if (rb_tree_red(parent)) {
            brother->red = true, parent->red = false;
            break;
        }

        /// 黑兄黑侄黑父，无法平衡，向祖先回溯
        brother->red = true, current = current->parent;
    }

end:
    // 当前为根节点？直接删除
    if (!cur->parent) {
        rb_tree_node_destroy(tree);
    } else if (cur == cur->parent->left) {
        rb_tree_node_destroy(&cur->parent->left);
    } else {
        rb_tree_node_destroy(&cur->parent->right);
    }
}

typedef struct {
    int offset, size;
    rb_tree_t *mid, *tree;
} data_t;
void data_mid_lshift(data_t *d) {
    if (d->offset > 1) {
        d->offset -= 1;
    } else {
        d->mid = rb_tree_prev(d->mid), d->offset = d->mid->count;
    }
}
void data_mid_rshift(data_t *d) {
    if (d->offset < d->mid->count) {
        d->offset += 1;
    } else {
        d->mid = rb_tree_next(d->mid), d->offset = 1;
    }
}
void data_add(data_t *d, int val) {
    d->size += 1;
    rb_tree_add(&d->tree, val);
    if (!d->mid) {
        d->offset = 1, d->mid = d->tree;
    } else if (val < d->mid->val && d->size % 2) {
        data_mid_lshift(d);
    } else if (val >= d->mid->val && d->size % 2 == 0) {
        data_mid_rshift(d);
    }
}
double data_middle(data_t *data) {
    if (data->size % 2 == 1 || data->offset > 1) return data->mid->val;
    rb_tree_t *prev = rb_tree_prev(data->mid);
    return (( double )prev->val + data->mid->val) / 2;
}
void data_calculate(data_t *d, int out, int in) {
    if (in == out) return;
    rb_tree_t *find = rb_tree_find(d->tree, out);

    // 数据更新
    find->count -= 1;
    rb_tree_add(&d->tree, in);

    if (in >= d->mid->val && out > d->mid->val) {
        // do nothing
    } else if (in >= d->mid->val && out == d->mid->val) {
        // right shift possible
        if (d->offset > d->mid->count) data_mid_rshift(d);
    } else if (in >= d->mid->val && out < d->mid->val) {
        // right shift
        data_mid_rshift(d);
    } else if (in < d->mid->val && out > d->mid->val) {
        // left shift
        data_mid_lshift(d);
    } else if (in < d->mid->val && out == d->mid->val) {
        // left shift
        data_mid_lshift(d);
    } else if (in < d->mid->val && out < d->mid->val) {
        // do nothing
    }
    if (!find->count) rb_tree_del(&d->tree, out);
}

double *medianSlidingWindow(int *nums, int size, int k, int *returnSize) {
    data_t data = { 0 };
    double *ans = malloc((*returnSize = size - k + 1) * sizeof(double));

    for (int i = 0; i < k; ++i) {
        data_add(&data, nums[i]);
    }
    for (int i = 0; i + k < size; ++i) {
        ans[i] = data_middle(&data);
        data_calculate(&data, nums[i], nums[i + k]);
    }
    ans[size - k] = data_middle(&data);

    rb_tree_destroy(data.tree);
    return ans;
}