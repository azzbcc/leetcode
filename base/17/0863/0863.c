// 给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。
//
// 返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。
//
//
//
//
//
//
// 示例 1：
//
// 输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
// 输出：[7,4,1]
// 解释：
// 所求结点为与目标结点（值为 5）距离为 2 的结点，
// 值分别为 7，4，以及 1
//
//
//
// 注意，输入的 "root" 和 "target" 实际上是树上的结点。
// 上面的输入仅仅是对这些对象进行了序列化描述。
//
//
//
//
// 提示：
//
//
// 给定的树是非空的。
// 树上的每个结点都具有唯一的值 0 <= node.val <= 500 。
// 目标结点 target 是树上的结点。
// 0 <= K <= 1000.
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树
// 👍 329 👎 0

#define MAXN 500
typedef struct {
    struct TreeNode *key, *val;
    UT_hash_handle hh;
} * hash_t;
typedef struct {
    struct TreeNode *node;
    int depth;
} node_t;
struct TreeNode *hash_find(hash_t t, struct TreeNode *key) {
    hash_t cur;
    HASH_FIND_PTR(t, &key, cur);
    return cur ? cur->val : NULL;
}
void hash_record(hash_t *t, struct TreeNode *key, struct TreeNode *val) {
    hash_t cur = malloc(sizeof(*cur));
    cur->key = key, cur->val = val;
    HASH_ADD_PTR(*t, key, cur);
}
int *distanceK(struct TreeNode *root, struct TreeNode *find, int k, int *returnSize) {
    int l, r;
    node_t queue[MAXN] = { 0 };
    hash_t hash = NULL, record = NULL, cur, next;

    hash_record(&record, find, find);
    for (l = 0, r = 0, queue[r++] = (node_t) { root }; l < r; l++) {
        struct TreeNode *now = queue[l].node;
        if (now == find) break;
        if (now->left) {
            hash_record(&hash, now->left, now);
            queue[r++] = (node_t) { now->left };
        }
        if (now->right) {
            hash_record(&hash, now->right, now);
            queue[r++] = (node_t) { now->right };
        }
    }
    for (l = 0, r = 0, queue[r++] = (node_t) { find, 0 }; l < r; l++) {
        node_t *now = &queue[l];
        if (now->depth == k) break;
        struct TreeNode *parent = hash_find(hash, now->node);
        if (now->node->left && !hash_find(record, now->node->left)) {
            hash_record(&record, now->node->left, now->node);
            queue[r++] = (node_t) { now->node->left, now->depth + 1 };
        }
        if (now->node->right && !hash_find(record, now->node->right)) {
            hash_record(&record, now->node->right, now->node);
            queue[r++] = (node_t) { now->node->right, now->depth + 1 };
        }
        if (parent && !hash_find(record, parent)) {
            hash_record(&record, parent, now->node);
            queue[r++] = (node_t) { parent, now->depth + 1 };
        }
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    HASH_ITER(hh, record, cur, next) {
        HASH_DEL(record, cur);
        free(cur);
    }

    int *ans = malloc((*returnSize = r - l) * sizeof(int));
    for (int i = l; i < r; ++i) {
        ans[i - l] = queue[i].node->val;
    }

    return ans;
}
