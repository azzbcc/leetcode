// 给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <=t
// ，同时又满足 abs(i - j) <= k 。
//
// 如果存在则返回 true，不存在返回 false。
//
//
//
// 示例 1：
//
//
// 输入：nums = [1,2,3,1], k = 3, t = 0
// 输出：true
//
// 示例 2：
//
//
// 输入：nums = [1,0,1,1], k = 1, t = 2
// 输出：true
//
// 示例 3：
//
//
// 输入：nums = [1,5,9,1,5,9], k = 2, t = 3
// 输出：false
//
//
//
// 提示：
//
//
// 0 <= nums.length <= 2 * 104
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 104
// 0 <= t <= 231 - 1
//
// Related Topics 排序 Ordered Map
// 👍 378 👎 0

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
bool rb_tree_find(rb_tree_t t, long l, long r) {
    if (!t) return false;
    if (t->val > r) {
        return rb_tree_find(t->p[0], l, r);
    } else if (t->val < l) {
        return rb_tree_find(t->p[1], l, r);
    }
    return true;
}
void rb_tree_add(rb_tree_t *t, node_t *node) {
    rb_tree_t cur = *t, parent = NULL;
    if (!cur) {
        *t = node, node->red = false;
        return;
    }
    for (; cur; parent = cur, cur = cur->p[node->val > cur->val]) {}
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
bool containsNearbyAlmostDuplicate(int *nums, int size, int k, int t) {
    node_t nodes[size + 1];
    rb_tree_t tree = NULL;
    for (int i = 0; i < size; ++i) {
        if (rb_tree_find(tree, ( long )nums[i] - t, ( long )nums[i] + t)) return true;
        nodes[i] = (node_t) { nums[i], true, { NULL, NULL, NULL } };
        rb_tree_add(&tree, &nodes[i]);
        if (i >= k) rb_tree_del(&tree, nums[i - k]);
    }
    return false;
}