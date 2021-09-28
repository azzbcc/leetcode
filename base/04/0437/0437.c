// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
//
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
//
//
//
// 示例 1：
//
//
//
//
// 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// 输出：3
// 解释：和等于 8 的路径有 3 条，如图所示。
//
//
// 示例 2：
//
//
// 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// 输出：3
//
//
//
//
// 提示:
//
//
// 二叉树的节点个数的范围是 [0,1000]
// -10⁹ <= Node.val <= 10⁹
// -1000 <= targetSum <= 1000
//
// Related Topics 树 深度优先搜索 二叉树 👍 1035 👎 0

typedef struct {
    int val, count;
    UT_hash_handle hh;
} * hash_t;
void hash_record(hash_t *t, int val, int count) {
    hash_t cur;
    HASH_FIND_INT(*t, &val, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->val = val, cur->count = 0;
        HASH_ADD_INT(*t, val, cur);
    }
    cur->count += count;
}
int hash_count(hash_t t, int val) {
    hash_t cur;
    HASH_FIND_INT(t, &val, cur);
    return cur ? cur->count : 0;
}
int dfs(struct TreeNode *root, hash_t *t, int targetSum, int prefix) {
    if (!root) return 0;
    int count = hash_count(*t, (prefix += root->val) - targetSum);
    hash_record(t, prefix, 1);
    count += dfs(root->left, t, targetSum, prefix) + dfs(root->right, t, targetSum, prefix);
    hash_record(t, prefix, -1);
    return count;
}
int pathSum(struct TreeNode *root, int targetSum) {
    hash_t hash = NULL, cur, next;

    hash_record(&hash, 0, 1);
    int ans = dfs(root, &hash, targetSum, 0);
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }

    return ans;
}
