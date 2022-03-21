// 给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
//
//
//
// 示例 1：
//
//
// 输入: root = [5,3,6,2,4,null,7], k = 9
// 输出: true
//
//
// 示例 2：
//
//
// 输入: root = [5,3,6,2,4,null,7], k = 28
// 输出: false
//
//
//
//
// 提示:
//
//
// 二叉树的节点个数的范围是 [1, 10⁴].
// -10⁴ <= Node.val <= 10⁴
// root 为二叉搜索树
// -10⁵ <= k <= 10⁵
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉搜索树 哈希表 双指针 二叉树 👍 351 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} * hash_t;
hash_t hash_find(hash_t t, int key) {
    hash_t cur;
    HASH_FIND_INT(t, &key, cur);
    return cur;
}
void hash_record(hash_t *t, int key) {
    hash_t cur = hash_find(*t, key);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->key = key, cur->count = 0;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->count += 1;
}
bool dfs(hash_t *t, struct TreeNode *root, int k) {
    bool ans;
    hash_t find;
    if (!root) return false;
    if (ans = dfs(t, root->left, k), ans) return ans;
    if (find = hash_find(*t, k - root->val), find) return true;
    hash_record(t, root->val);
    return dfs(t, root->right, k);
}
bool findTarget(struct TreeNode *root, int k) {
    hash_t hash = NULL, cur, next;
    bool ans    = dfs(&hash, root, k);
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}