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
    int index, rank, height;
    struct node *prev, *next;
    struct node *left, *right, *parent;
} node_t, *balance_tree_t;
typedef struct {
    int *indexes[2];
    node_t *lines;
    balance_tree_t *trees;
} BlackBox;

static int max(int a, int b) {
    return a > b ? a : b;
}
static void point_swap(balance_tree_t *a, balance_tree_t *b) {
    balance_tree_t tmp = *a;
    *a = *b, *b = tmp;
}
static int tree_height(balance_tree_t t) {
    return t ? t->height : 0;
}
static void tree_height_update(balance_tree_t t) {
    t->height = max(tree_height(t->left), tree_height(t->right)) + 1;
}
static void tree_left_rotate(balance_tree_t *tree) {
    balance_tree_t t = *tree, child = t->right;
    *tree = child, t->right = child->left, child->left = t;
    child->parent = t->parent, t->parent = child;
    if (t->right) t->right->parent = t;
    tree_height_update(t);
}
static void tree_right_rotate(balance_tree_t *tree) {
    balance_tree_t t = *tree, child = t->left;
    *tree = child, t->left = child->right, child->right = t;
    child->parent = t->parent, t->parent = child;
    if (t->left) t->left->parent = t;
    tree_height_update(t);
}
static void tree_balance(balance_tree_t *tree) {
    balance_tree_t t = *tree;
    int balance      = tree_height(t->left) - tree_height(t->right);
    if (balance < -1) {
        if (tree_height(t->right->left) > tree_height(t->right->right)) {
            tree_right_rotate(&t->right);
            tree_height_update(t->right);
        }
        tree_left_rotate(tree);
    } else if (balance > 1) {
        if (tree_height(t->left->right) > tree_height(t->left->left)) {
            tree_left_rotate(&t->left);
            tree_height_update(t->left);
        }
        tree_right_rotate(tree);
    } else {
        tree_height_update(*tree);
    }
}
static void tree_add(balance_tree_t *tree, balance_tree_t parent, balance_tree_t cur) {
    balance_tree_t now = *tree;
    if (!now) {
        *tree = cur, cur->height = 1;
        if (parent) {
            if (cur->rank > parent->rank) {
                cur->prev = parent, cur->next = parent->next;
                parent->next->prev = cur, parent->next = cur;
            } else {
                cur->prev = parent->prev, cur->next = parent;
                parent->prev->next = cur, parent->prev = cur;
            }
        } else {
            cur->prev = cur->next = cur;
        }
        cur->parent = parent;
    } else {
        tree_add(cur->rank < now->rank ? &now->left : &now->right, now, cur);
        tree_balance(tree);
    }
}
static void tree_remove(balance_tree_t *tree, balance_tree_t cur) {
    balance_tree_t t = *tree;
    if (t != cur) {
        tree_remove(cur->rank < t->rank ? &t->left : &t->right, cur);
        goto done;
    }
    if (!t->left || !t->right) {
        *tree = t->left ? t->left : t->right;
        if (*tree) (*tree)->parent = t->parent;
        if (t->next != t) t->prev->next = t->next, t->next->prev = t->prev;
        t->prev = t->next = t->left = t->right = NULL;
        goto done;
    }
    bool right          = tree_height(t->left) < tree_height(t->right);
    balance_tree_t swap = right ? cur->next : cur->prev;

    if (right) {
        swap->next->prev = t, t->prev->next = swap;
        swap->prev = t->prev, t->next = swap->next;
        swap->next = t, t->prev = swap;
    } else {
        t->next->prev = swap, swap->prev->next = t;
        t->prev = swap->prev, swap->next = t->next;
        t->next = swap, swap->prev = t;
    }
    if (swap->left) swap->left->parent = t;
    if (swap->right) swap->right->parent = t;
    if (t->parent) {
        if (t->parent->left == t) {
            t->parent->left = swap;
        } else {
            t->parent->right = swap;
        }
    } else {
        *tree = swap;
    }
    if (swap->parent != t) {
        if (swap->parent->left == swap) {
            swap->parent->left = t;
        } else {
            swap->parent->right = t;
        }
        t->left->parent = t->right->parent = swap;
        point_swap(&t->left, &swap->left);
        point_swap(&t->right, &swap->right);
        point_swap(&t->parent, &swap->parent);
    } else if (t->left == swap) {
        t->right->parent = swap;
        t->left = swap->left, swap->left = t;
        point_swap(&t->right, &swap->right);
        swap->parent = t->parent, t->parent = swap;
    } else {
        t->left->parent = swap;
        point_swap(&t->left, &swap->left);
        t->right = swap->right, swap->right = t;
        swap->parent = t->parent, t->parent = swap;
    }

    tree_remove(right ? &swap->right : &swap->left, cur);

done:
    if (*tree) tree_balance(tree);
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
    box->trees = calloc(index, sizeof(balance_tree_t));

    return box;
}

int blackBoxOpen(BlackBox *box, int cur, int d) {
    if (d < 0) d = 0;

    node_t *l = &box->lines[2 * cur + d];
    if (!l->next) {
        tree_add(&box->trees[box->indexes[d][cur]], NULL, l);
        tree_add(&box->trees[box->indexes[1 - d][cur]], NULL, &box->lines[2 * cur + 1 - d]);
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
