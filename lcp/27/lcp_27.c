// 秋日市集上有个奇怪的黑盒，黑盒的主视图为 n\*m 的矩形。从黑盒的主视图来看，黑盒的上面和下面各均匀分布有 m
// 个小孔，黑盒的左面和右面各均匀分布有 n 个小孔。黑盒左上角小孔序号为 0，按顺时针编号，总共有 2*(m+n)
// 个小孔。每个小孔均可以打开或者关闭，初始时，所有小孔均处于关闭状态。每个小孔上的盖子均为 镜面材质。例如一个 2\*3
// 的黑盒主视图与其小孔分布如图所示:
//
// ![image.png](https://pic.leetcode-cn.com/1598951281-ZCBrif-image.png){:height="200px"}
//
// 店长告诉小扣，这里是「几何学的快问快答」，店长可能有两种操作：
//
// - `open(int index, int direction)` - 若小孔处于关闭状态，则打开小孔，照入光线；否则直接照入光线；
// - `close(int index)` - 关闭处于打开状态小孔，店长保证不会关闭已处于关闭状态的小孔；
//
// 其中：
// - `index`： 表示小孔序号
// - `direction`：`1` 表示光线沿 $y=x$ 方向，`-1` 表示光线沿 $y=-x$ 方向。
//
// ![image.png](https://pic.leetcode-cn.com/1599620810-HdOlMi-image.png){:height="200px"}
//
//
// 当光线照至边界时：若边界上的小孔为开启状态，则光线会射出；否则，光线会在小孔之间进行反射。特别地：
//  1. 若光线射向未打开的拐角（黑盒顶点），则光线会原路反射回去；
//  2. 光线自拐角处的小孔照入时，只有一种入射方向（如自序号为 0 的小孔照入方向只能为 `-1`）
//
// ![image.png](https://pic.leetcode-cn.com/1598953840-DLiAsf-image.png){:height="200px"}
//
// 请帮助小扣判断并返回店长每次照入的光线从几号小孔射出。
//
//
// **示例 1：**
// >输入：
// >`["BlackBox","open","open","open","close","open"]`
// >`[[2,3],[6,-1],[4,-1],[0,-1],[6],[0,-1]]`
// >
// >输出：`[null,6,4,6,null,4]`
// >
// >解释：
// >BlackBox b = BlackBox(2,3); // 新建一个 2x3 的黑盒
// >b.open(6,-1) // 打开 6 号小孔，并沿 y=-x 方向照入光线，光线至 0 号小孔反射，从 6 号小孔射出
// >b.open(4,-1) // 打开 4 号小孔，并沿 y=-x 方向照入光线，光线轨迹为 4-2-8-2-4，从 4 号小孔射出
// >b.open(0,-1) // 打开 0 号小孔，并沿 y=-x 方向照入光线，由于 6 号小孔为开启状态，光线从 6 号小孔射出
// >b.close(6) // 关闭 6 号小孔
// >b.shoot(0,-1) // 从 0 号小孔沿 y=-x 方向照入光线，由于 6 号小孔为关闭状态，4 号小孔为开启状态，光线轨迹为 0-6-4，从
// 4 号小孔射出
//
// **示例 2：**
// >输入：
// >`["BlackBox","open","open","open","open","close","open","close","open"]`
// >`[[3,3],[1,-1],[5,1],[11,-1],[11,1],[1],[11,1],[5],[11,-1]]`
// >
// >输出：`[null,1,1,5,1,null,5,null,11]`
// >
// >解释：
// >
// >![image.png](https://pic.leetcode-cn.com/1599204202-yGDMVk-image.png){:height
// ="300px"}
// >
// >BlackBox b = BlackBox(3,3); // 新建一个 3x3 的黑盒
// >b.open(1,-1) // 打开 1 号小孔，并沿 y=-x 方向照入光线，光线轨迹为 1-5-7-11-1，从 1 号小孔射出
// >b.open(5,1) // 打开 5 号小孔，并沿 y=x 方向照入光线，光线轨迹为 5-7-11-1，从 1 号小孔射出
// >b.open(11,-1) // 打开 11 号小孔，并沿逆 y=-x 方向照入光线，光线轨迹为 11-7-5，从 5 号小孔射出
// >b.open(11,1) // 从 11 号小孔沿 y=x 方向照入光线，光线轨迹为 11-1，从 1 号小孔射出
// >b.close(1) // 关闭 1 号小孔
// >b.open(11,1) // 从 11 号小孔沿 y=x 方向照入光线，光线轨迹为 11-1-5，从 5 号小孔射出
// >b.close(5) // 关闭 5 号小孔
// >b.open(11,-1) // 从 11 号小孔沿 y=-x 方向照入光线，光线轨迹为 11-1-5-7-11，从 11 号小孔射出
//
//
//
// **提示：**
// - `1 <= n, m <= 10000`
// - `1 <= 操作次数 <= 10000`
// - `direction` 仅为 `1` 或 `-1`
// - `0 <= index < 2*(m+n)`
// 👍 7 👎 0

typedef struct node {
    bool red;
    int index, rank;
    struct node *prev, *next;
    struct node *left, *right, *parent;
} node_t, *rb_tree_t;
typedef struct {
    int *indexes[2];
    node_t *lines;
    rb_tree_t *trees;
} BlackBox;

static int max(int a, int b) {
    return a > b ? a : b;
}
static void tree_node_swap_next(rb_tree_t *tree, rb_tree_t t) {
    rb_tree_t a = t, b = t->next;

    if (a != b->next) {
        a->prev->next = b, b->next->prev = a;
        a->next = b->next, b->prev = a->prev;
        a->prev = b, b->next = a;
    }

#define SWAP(type_t, member)                                                                                           \
    do {                                                                                                               \
        type_t member = a->member;                                                                                     \
        a->member     = b->member;                                                                                     \
        b->member     = member;                                                                                        \
    } while (0)
    SWAP(bool, red);

    int relation = 0;
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
    if (relation != 2) SWAP(rb_tree_t, left);
    if (relation != 1) SWAP(rb_tree_t, right);
    if (relation == 0) SWAP(rb_tree_t, parent);
    if (relation == 1) {
        b->parent = a->parent, a->parent = b;
        a->right = b->right, b->right = a;
    } else if (relation == 2) {
        a->parent = b->parent, b->parent = a;
        b->left = a->left, a->left = b;
    }
#undef SWAP
}
static void tree_node_reset(rb_tree_t t) {
    if (t->parent) {
        if (t->parent->left == t) {
            t->parent->left = NULL;
        } else {
            t->parent->right = NULL;
        }
    }
    t->prev->next = t->next, t->next->prev = t->prev;
    t->red = false, t->left = t->right = t->parent = t->prev = t->next = NULL;
}
static bool tree_color_red(rb_tree_t t) {
    return t ? t->red : false;
}
static void tree_left_rotate(rb_tree_t t) {
    rb_tree_t child = t->right;
    if (t->parent) {
        if (t->parent->left == t) {
            t->parent->left = child;
        } else {
            t->parent->right = child;
        }
    }
    t->right = child->left, child->left = t;
    child->parent = t->parent, t->parent = child;
    if (t->right) t->right->parent = t;
}
static void tree_right_rotate(rb_tree_t t) {
    rb_tree_t child = t->left;
    if (t->parent) {
        if (t->parent->left == t) {
            t->parent->left = child;
        } else {
            t->parent->right = child;
        }
    }
    t->left = child->right, child->right = t;
    child->parent = t->parent, t->parent = child;
    if (t->left) t->left->parent = t;
}
static void tree_add(rb_tree_t *tree, rb_tree_t cur) {
    rb_tree_t now = *tree, parent = NULL;
    if (!now) {
        cur->next = cur->prev = cur, *tree = cur;
        return;
    }

    cur->red = true;
    for (; now; parent = now, now = now->rank > cur->rank ? now->left : now->right) {}

    if (cur->rank < parent->rank) {
        parent->left = cur, cur->parent = parent;
        cur->prev = parent->prev, cur->next = parent;
        parent->prev->next = cur, parent->prev = cur;
    } else {
        parent->right = cur, cur->parent = parent;
        cur->next = parent->next, cur->prev = parent;
        parent->next->prev = cur, parent->next = cur;
    }

    while (tree_color_red(parent)) {
        rb_tree_t grand_parent = parent->parent, uncle = NULL;
        uncle = grand_parent->left != parent ? grand_parent->left : grand_parent->right;

        if (tree_color_red(uncle)) {
            parent->red = uncle->red = false, grand_parent->red = true;
            cur = grand_parent, parent = cur->parent;
            // 回溯到根节点，将根节点改为黑色
            if (!parent) cur->red = false;
            continue;
        }
        if (grand_parent->left == parent) {
            if (parent->right == cur) {
                tree_left_rotate(parent);
                parent = cur;
            }
            tree_right_rotate(grand_parent);
        } else {
            if (parent->right != cur) {
                tree_right_rotate(parent);
                parent = cur;
            }
            tree_left_rotate(grand_parent);
        }
        parent->red = false, grand_parent->red = true;
        if (!parent->parent) *tree = parent;
    }
}
static void tree_remove(rb_tree_t *tree, rb_tree_t cur) {
    // 保证待删除节点最多拥有一个孩子
    if (cur->left && cur->right) tree_node_swap_next(tree, cur);

    // 当前节点有孩子？孩子节点为单独的红色叶子节点
    if (cur->left) tree_node_swap_next(tree, cur->prev);
    if (cur->right) tree_node_swap_next(tree, cur);

    // 当前为红色？直接删除
    if (tree_color_red(cur)) {
        tree_node_reset(cur);
        return;
    }

    for (rb_tree_t current = cur, brother, parent; current->parent;) {
        parent = current->parent, brother = current == parent->left ? parent->right : parent->left;

        /// 红兄，此时父侄必然黑色，对父亲节点旋转，转换为黑兄情况
        if (tree_color_red(brother)) {
            if (brother == parent->left) {
                tree_right_rotate(parent);
            } else {
                tree_left_rotate(parent);
            }
            if (!brother->parent) *tree = brother;
            parent->red = true, brother->red = false;
            continue;
        }

        /// 黑兄红侄
        if (tree_color_red(brother->left) || tree_color_red(brother->right)) {
            if (brother == parent->right) {
                if (!tree_color_red(brother->right)) {
                    brother->red = true, brother->left->red = false;
                    tree_right_rotate(brother);
                    brother = brother->parent;
                }
                tree_left_rotate(parent);
                brother->right->red = false;
            } else {
                if (!tree_color_red(brother->left)) {
                    brother->red = true, brother->right->red = false;
                    tree_left_rotate(brother);
                    brother = brother->parent;
                }
                tree_right_rotate(parent);
                brother->left->red = false;
            }
            if (!brother->parent) *tree = brother;
            brother->red = parent->red, parent->red = false;
            break;
        }

        /// 黑兄黑侄红父
        if (tree_color_red(parent)) {
            brother->red = true, parent->red = false;
            break;
        }

        /// 黑兄黑侄黑父，无法平衡，向祖先回溯
        brother->red = true, current = current->parent;
    }

    if (!cur->parent) *tree = NULL;
    tree_node_reset(cur);
}

BlackBox *blackBoxCreate(int n, int m) {
    BlackBox *box = malloc(sizeof(BlackBox));

    int sum = (n + m) * 2, index = 0;
    box->indexes[0] = malloc(sum * sizeof(int));
    box->indexes[1] = malloc(sum * sizeof(int));
    box->lines      = calloc((n + m) * 4, sizeof(node_t));

    for (int direction = 0; direction < 2; ++direction) {
        for (int i = 0; i <= m; ++i) {
            node_t *cur = &box->lines[i * 2 + direction];
            if (cur->rank) continue;
            for (int now = i, d = direction, rank = 0; !cur->rank; d = 1 - d, cur = &box->lines[now * 2 + d]) {
                cur->index = now, cur->rank = ++rank, box->indexes[d][now] = index;
                if (d) {
                    if (now) now = sum - now;
                } else if (now <= m * 2) {
                    now = m * 2 - now;
                } else {
                    now = m * 4 + n * 2 - now;
                }
            }
            index += 1;
        }
    }
    box->trees = calloc(index, sizeof(rb_tree_t));

    return box;
}

int blackBoxOpen(BlackBox *box, int cur, int d) {
    if (d < 0) d = 0;

    node_t *l = &box->lines[2 * cur + d];
    if (!l->next) {
        tree_add(&box->trees[box->indexes[d][cur]], l);
        tree_add(&box->trees[box->indexes[1 - d][cur]], &box->lines[2 * cur + 1 - d]);
    }
    return l->next->index;
}

void blackBoxClose(BlackBox *box, int cur) {
    tree_remove(&box->trees[box->indexes[0][cur]], &box->lines[2 * cur]);
    tree_remove(&box->trees[box->indexes[1][cur]], &box->lines[2 * cur + 1]);
}

void blackBoxFree(BlackBox *box) {
    free(box->indexes[0]);
    free(box->indexes[1]);
    free(box->trees);
    free(box->lines);
    free(box);
}
