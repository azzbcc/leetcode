// 给你二叉树的根结点 root ，请你设计算法计算二叉树的 垂序遍历 序列。
//
// 对位于 (row, col) 的每个结点而言，其左右子结点分别位于 (row + 1, col - 1) 和 (row + 1, col + 1) 。树的根结点位于 (0,
// 0) 。
//
// 二叉树的 垂序遍历
// 从最左边的列开始直到最右边的列结束，按列索引每一列上的所有结点，形成一个按出现位置从上到下排序的有序列表。如果同行同列上有多个结点，则按结点的值从小到大进行排序。
//
// 返回二叉树的 垂序遍历 序列。
//
//
//
// 示例 1：
//
//
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[9],[3,15],[20],[7]]
// 解释：
// 列 -1 ：只有结点 9 在此列中。
// 列  0 ：只有结点 3 和 15 在此列中，按从上到下顺序。
// 列  1 ：只有结点 20 在此列中。
// 列  2 ：只有结点 7 在此列中。
//
// 示例 2：
//
//
// 输入：root = [1,2,3,4,5,6,7]
// 输出：[[4],[2],[1,5,6],[3],[7]]
// 解释：
// 列 -2 ：只有结点 4 在此列中。
// 列 -1 ：只有结点 2 在此列中。
// 列  0 ：结点 1 、5 和 6 都在此列中。
//           1 在上面，所以它出现在前面。
//           5 和 6 位置都是 (2, 0) ，所以按值从小到大排序，5 在 6 的前面。
// 列  1 ：只有结点 3 在此列中。
// 列  2 ：只有结点 7 在此列中。
//
//
// 示例 3：
//
//
// 输入：root = [1,2,3,4,6,5,7]
// 输出：[[4],[2],[1,5,6],[3],[7]]
// 解释：
// 这个示例实际上与示例 2 完全相同，只是结点 5 和 6 在树中的位置发生了交换。
// 因为 5 和 6 的位置仍然相同，所以答案保持不变，仍然按值从小到大排序。
//
//
//
// 提示：
//
//
// 树中结点数目总数在范围 [1, 1000] 内
// 0 <= Node.val <= 1000
//
// Related Topics 树 深度优先搜索 广度优先搜索 哈希表 二叉树
// 👍 118 👎 0

#include <stdarg.h>
typedef enum { TYPE_COL, TYPE_ROW, TYPE_NODE } type_t;
typedef struct __hash_node {
    type_t type;
    int key, count;
    struct __hash_node *hash;
    UT_hash_handle hh;
} * hash_t;
void hash_record(hash_t *t, type_t type, ...) {
    hash_t cur;
    va_list list;
    va_start(list, type);

    // 加入哈希表
    int key = va_arg(list, int);
    HASH_FIND_INT(*t, &key, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->type = type, cur->key = key, cur->count = 0, cur->hash = NULL;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->count += 1;

    // 进入子哈希表
    if (type == TYPE_COL) {
        int row = va_arg(list, int), val = va_arg(list, int);
        hash_record(&cur->hash, TYPE_ROW, row, val);
    } else if (type == TYPE_ROW) {
        int val = va_arg(list, int);
        hash_record(&cur->hash, TYPE_NODE, val);
    }

    va_end(list);
}
void hash_free(hash_t *t) {
    hash_t cur, next;
    HASH_ITER(hh, *t, cur, next) {
        HASH_DEL(*t, cur);
        hash_free(&cur->hash);
        free(cur);
    }
}
int cmp(hash_t a, hash_t b) {
    return a->key - b->key;
}
void dfs(struct TreeNode *root, int row, int col, hash_t *t) {
    if (!root) return;
    hash_record(t, TYPE_COL, col, row, root->val);
    dfs(root->left, row + 1, col - 1, t);
    dfs(root->right, row + 1, col + 1, t);
}
int **verticalTraversal(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    hash_t hash = NULL, cur_col, next_col, cur_row, next_row, cur_node, next_node;

    dfs(root, 0, 0, &hash);
    HASH_SORT(hash, cmp);

    int p_col = 0, p_row, **ans = malloc((*returnSize = HASH_COUNT(hash)) * sizeof(int *));
    *returnColumnSizes = malloc(HASH_COUNT(hash) * sizeof(int));
    HASH_ITER(hh, hash, cur_col, next_col) {
        p_row = 0, ans[p_col] = malloc((returnColumnSizes[0][p_col] = cur_col->count) * sizeof(int));
        HASH_SORT(cur_col->hash, cmp);
        HASH_ITER(hh, cur_col->hash, cur_row, next_row) {
            HASH_SORT(cur_row->hash, cmp);
            HASH_ITER(hh, cur_row->hash, cur_node, next_node) {
                for (int i = 0; i < cur_node->count; ++i) {
                    ans[p_col][p_row++] = cur_node->key;
                }
            }
        }
        p_col += 1;
    }

    hash_free(&hash);
    return ans;
}
