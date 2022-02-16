// 给你一个数组 pairs ，其中 pairs[i] = [xi, yi] ，并且满足：
//
//
// pairs 中没有重复元素
// xi < yi
//
//
// 令 ways 为满足下面条件的有根树的方案数：
//
//
// 树所包含的所有节点值都在 pairs 中。
// 一个数对 [xi, yi] 出现在 pairs 中 当且仅当 xi 是 yi 的祖先或者 yi 是 xi 的祖先。
// 注意：构造出来的树不一定是二叉树。
//
//
// 两棵树被视为不同的方案当存在至少一个节点在两棵树中有不同的父节点。
//
// 请你返回：
//
//
// 如果 ways == 0 ，返回 0 。
// 如果 ways == 1 ，返回 1 。
// 如果 ways > 1 ，返回 2 。
//
//
// 一棵 有根树 指的是只有一个根节点的树，所有边都是从根往外的方向。
//
// 我们称从根到一个节点路径上的任意一个节点（除去节点本身）都是该节点的 祖先 。根节点没有祖先。
//
//
//
// 示例 1：
//
//
// 输入：pairs = [[1,2],[2,3]]
// 输出：1
// 解释：如上图所示，有且只有一个符合规定的有根树。
//
//
// 示例 2：
//
//
// 输入：pairs = [[1,2],[2,3],[1,3]]
// 输出：2
// 解释：有多个符合规定的有根树，其中三个如上图所示。
//
//
// 示例 3：
//
//
// 输入：pairs = [[1,2],[2,3],[2,4],[1,5]]
// 输出：0
// 解释：没有符合规定的有根树。
//
//
//
// 提示：
//
//
// 1 <= pairs.length <= 10⁵
// 1 <= xi < yi <= 500
// pairs 中的元素互不相同。
//
// Related Topics 树 图 拓扑排序 👍 61 👎 0

#define goto_ans(n)                                                                                                    \
    ans = n;                                                                                                           \
    goto end
typedef struct hash_node *hash_t;
struct hash_node {
    int key;
    hash_t child;
    UT_hash_handle hh;
};
hash_t hash_find(hash_t t, int key) {
    hash_t cur;
    HASH_FIND_INT(t, &key, cur);
    return cur;
}
void hash_record(hash_t *t, int key, int val) {
    hash_t cur = hash_find(*t, key);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->key = key, cur->child = NULL;
        HASH_ADD_INT(*t, key, cur);
    }
    hash_t cur_val = hash_find(cur->child, val);
    if (!cur_val) {
        cur_val = malloc(sizeof(*cur_val)), cur_val->key = val, cur_val->child = NULL;
        HASH_ADD_INT(cur->child, key, cur_val);
    }
}
void hash_destroy(hash_t t) {
    hash_t cur, next;
    HASH_ITER(hh, t, cur, next) {
        hash_destroy(cur->child);
        HASH_DEL(t, cur);
        free(cur);
    }
}
int checkWays(int **pairs, int size, int *colSize) {
    int ans = 0;
    hash_t cur, next, hash = NULL, root = NULL;
    for (int i = 0; i < size; ++i) {
        hash_record(&hash, pairs[i][0], pairs[i][1]);
        hash_record(&hash, pairs[i][1], pairs[i][0]);
    }

    // found root
    int node_count = HASH_COUNT(hash);
    HASH_ITER(hh, hash, cur, next) {
        if (HASH_COUNT(cur->child) + 1 == node_count) {
            root = cur;
            break;
        }
    }
    if (!root) { goto_ans(0); }

    HASH_ITER(hh, hash, cur, next) {
        // skip root
        if (root == cur) continue;

        // find parent
        hash_t parent = root, child_cur, child_next;
        int cur_count = HASH_COUNT(cur->child);
        HASH_ITER(hh, cur->child, child_cur, child_next) {
            hash_t node = hash_find(hash, child_cur->key);
            if (HASH_COUNT(node->child) < HASH_COUNT(parent->child) && HASH_COUNT(node->child) >= cur_count) {
                parent = node;
            }
        }
        if (!parent) { goto_ans(0); }

        // check_contains
        HASH_ITER(hh, cur->child, child_cur, child_next) {
            if (parent->key == child_cur->key) continue;
            if (!hash_find(parent->child, child_cur->key)) { goto_ans(0); }
        }
        if (!ans && HASH_COUNT(parent->child) == cur_count) ans = 2;
    }
    if (!ans) ans = 1;

end:
    hash_destroy(hash);
    return ans;
}
