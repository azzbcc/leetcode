// 给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。
//
// 题目数据保证总会存在一个数值和不超过 k 的矩形区域。
//
//
//
// 示例 1：
//
//
// 输入：matrix = [[1,0,1],[0,-2,3]], k = 2
// 输出：2
// 解释：蓝色边框圈出来的矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
//
//
// 示例 2：
//
//
// 输入：matrix = [[2,2,-1]], k = 3
// 输出：3
//
//
//
//
// 提示：
//
//
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -100 <= matrix[i][j] <= 100
// -105 <= k <= 105
//
//
//
//
// 进阶：如果行数远大于列数，该如何设计解决方案？
// Related Topics 队列 二分查找 动态规划
// 👍 248 👎 0

#define MAXN 100
typedef struct node {
    int val;
    bool red;
    struct node *p[3];
} node_t, *rb_tree_t;
void rb_tree_rotate(rb_tree_t t, bool left) {
    rb_tree_t parent = t->p[2], child = t->p[left], other = child->p[!left];
    if (parent) parent->p[parent->p[0] != t] = child;
    t->p[left] = other, child->p[!left] = t;
    if (other) other->p[2] = t;
    t->p[2] = child, child->p[2] = parent;
}
bool rb_tree_red(rb_tree_t t) {
    return t ? t->red : false;
}
void rb_tree_add(rb_tree_t *t, node_t *node) {
    rb_tree_t cur = *t, parent = NULL;
    if (!cur) {
        *t = node, node->red = false;
        return;
    }
    for (; cur && cur->val != node->val; parent = cur, cur = cur->p[node->val > cur->val]) {}
    if (cur && cur->val == node->val) return;
    cur = node, parent->p[cur->val > parent->val] = cur, cur->p[2] = parent;
    while (rb_tree_red(parent)) {
        rb_tree_t gp = parent->p[2], uncle = gp->p[gp->p[0] == parent];
        if (rb_tree_red(uncle)) {
            parent->red = uncle->red = false, cur = gp, parent = cur->p[2], gp->red = parent != NULL;
            continue;
        }
        if ((gp->p[0] == parent) == (parent->p[0] != cur)) rb_tree_rotate(parent, parent->p[0] != cur), parent = cur;
        rb_tree_rotate(gp, gp->p[0] != parent);

        parent->red = false, gp->red = true;
        if (!parent->p[2]) *t = parent;
    }
}
void rb_tree_del(rb_tree_t *t, int val) {
    rb_tree_t cur = *t;
    for (; cur && cur->val != val; cur = cur->p[val > cur->val]) {}
    if (!cur) return;
    if (cur->p[0] && cur->p[1]) {
        rb_tree_t next = cur->p[1];
        for (; next->p[0]; next = next->p[0]) {}
        cur->val = next->val, cur = next;
    }
    if (cur->p[0] || cur->p[1]) {
        cur->val = cur->p[cur->p[0] == NULL]->val, cur->p[0] = cur->p[1] = NULL;
        return;
    }
    if (rb_tree_red(cur)) {
        cur->p[2]->p[cur->p[2]->p[0] != cur] = NULL;
        return;
    }
    for (rb_tree_t current = cur, parent, brother; current->p[2];) {
        parent = current->p[2], brother = parent->p[parent->p[0] == current];
        if (rb_tree_red(brother)) {
            rb_tree_rotate(parent, parent->p[0] != brother);
            if (!brother->p[2]) *t = brother;
            parent->red = true, brother->red = false;
        } else if (rb_tree_red(brother->p[0]) || rb_tree_red(brother->p[1])) {
            if (!rb_tree_red(brother->p[parent->p[0] != brother])) {
                rb_tree_rotate(brother, parent->p[0] == brother);
                brother->red = true, brother->p[2]->red = false, brother = brother->p[2];
            }
            rb_tree_rotate(parent, parent->p[0] != brother);
            brother->p[brother->p[0] == parent]->red = false;
            brother->red = parent->red, parent->red = false;
            if (!brother->p[2]) *t = brother;
            break;
        } else if (rb_tree_red(parent)) {
            brother->red = true, parent->red = false;
            break;
        } else {
            brother->red = true, current = current->p[2];
        }
    }
    if (!cur->p[2]) {
        *t = NULL;
    } else {
        cur->p[2]->p[cur->p[2]->p[0] != cur] = NULL;
    }
}
int rb_tree_find(rb_tree_t t, int key) {
    if (!t) return INT32_MAX;
    if (t->val < key) return rb_tree_find(t->p[1], key);
    return fmin(t->val, rb_tree_find(t->p[0], key));
}
int maxSumSubmatrix(int **matrix, int matrixSize, int *matrixColSize, int k) {
    long ans = INT32_MIN;
    int m = matrixSize, n = *matrixColSize;
    for (int i = 0; i < m; ++i) {
        int sum[MAXN] = { 0 };
        for (int j = i; j < m; ++j) {
            for (int l = 0; l < n; ++l) {
                sum[l] += matrix[j][l];
            }
            node_t nodes[MAXN + 1] = { 0 };
            rb_tree_t tree         = &nodes[n];
            for (int l = 0, s = 0; l < n; ++l) {
                nodes[l] = (node_t) { s += sum[l], true };
                ans      = fmax(ans, ( long )s - rb_tree_find(tree, s - k));
                if (ans == k) return ans;
                rb_tree_add(&tree, &nodes[l]);
            }
        }
    }
    return ans;
}
