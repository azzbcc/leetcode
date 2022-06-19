// 给你一个二叉树的根结点 root
// ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
//
// 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
//
//
//
// 示例 1：
//
//
//
//
// 输入: root = [5,2,-3]
// 输出: [2,-3,4]
//
//
// 示例 2：
//
//
//
//
// 输入: root = [5,2,-5]
// 输出: [2]
//
//
//
//
// 提示:
//
//
// 节点数在 [1, 10⁴] 范围内
// -10⁵ <= Node.val <= 10⁵
//
// Related Topics 树 深度优先搜索 哈希表 二叉树 👍 163 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} * hash_t;
int dfs(hash_t *t, struct TreeNode *root, int *max, int *len) {
    hash_t cur;
    if (!root) return 0;
    int val = root->val + dfs(t, root->left, max, len) + dfs(t, root->right, max, len);
    HASH_FIND_INT(*t, &val, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->key = val, cur->count = 0;
        HASH_ADD_INT(*t, key, cur);
    }
    if (cur->count += 1, *max == cur->count) {
        (*len)++;
    } else if (*max < cur->count) {
        *len = 1, *max = cur->count;
    }
    return val;
}
int *findFrequentTreeSum(struct TreeNode *root, int *returnSize) {
    int max = 0, len = 0;
    hash_t hash = NULL, cur, next;

    dfs(&hash, root, &max, &len);

    int *ans = malloc((*returnSize = len) * sizeof(int));

    len = 0;
    HASH_ITER(hh, hash, cur, next) {
        if (cur->count == max) ans[len++] = cur->key;
        HASH_DEL(hash, cur);
        free(cur);
    }

    return ans;
}
