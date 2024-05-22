// 给你一个整数数组 matches 其中 matches[i] = [winneri, loseri] 表示在一场比赛中 winneri 击败了 loseri 。
//
// 返回一个长度为 2 的列表 answer ：
//
//
// answer[0] 是所有 没有 输掉任何比赛的玩家列表。
// answer[1] 是所有恰好输掉 一场 比赛的玩家列表。
//
//
// 两个列表中的值都应该按 递增 顺序返回。
//
// 注意：
//
//
// 只考虑那些参与 至少一场 比赛的玩家。
// 生成的测试用例保证 不存在 两场比赛结果 相同 。
//
//
//
//
// 示例 1：
//
//
// 输入：matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
// 输出：[[1,2,10],[4,5,7,8]]
// 解释：
// 玩家 1、2 和 10 都没有输掉任何比赛。
// 玩家 4、5、7 和 8 每个都输掉一场比赛。
// 玩家 3、6 和 9 每个都输掉两场比赛。
// 因此，answer[0] = [1,2,10] 和 answer[1] = [4,5,7,8] 。
//
//
// 示例 2：
//
//
// 输入：matches = [[2,3],[1,3],[5,4],[6,4]]
// 输出：[[1,2,5,6],[]]
// 解释：
// 玩家 1、2、5 和 6 都没有输掉任何比赛。
// 玩家 3 和 4 每个都输掉两场比赛。
// 因此，answer[0] = [1,2,5,6] 和 answer[1] = [] 。
//
//
//
//
// 提示：
//
//
// 1 <= matches.length <= 10⁵
// matches[i].length == 2
// 1 <= winneri, loseri <= 10⁵
// winneri != loseri
// 所有 matches[i] 互不相同
//
//
// Related Topics 数组 哈希表 计数 排序 👍 33 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} *hash_t;
int cmp(hash_t a, hash_t b) {
    return a->key - b->key;
}
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

int **findWinners(int **matches, int size, int *colSize, int *returnSize, int **returnColumnSizes) {
    int **ans;
    hash_t cur, next, hash[2] = {NULL};
    for (int i = 0; i < size; ++i) {
        hash_record(&hash[1], matches[i][1]);
    }
    for (int i = 0; i < size; ++i) {
        if (hash_find(hash[1], matches[i][0])) continue;
        hash_record(&hash[0], matches[i][0]);
    }
    HASH_ITER(hh, hash[1], cur, next) {
        if (cur->count == 1) continue;
        HASH_DEL(hash[1], cur);
        free(cur);
    }
    HASH_SORT(hash[1], cmp);
    HASH_SORT(hash[0], cmp);

    ans = malloc((*returnSize = 2) * sizeof(int *)), *returnColumnSizes = malloc(2 * sizeof(int));
    for (int i = 0, j; i < 2; ++i) {
        j = 0, ans[i] = malloc(((*returnColumnSizes)[i] = HASH_COUNT(hash[i])) * sizeof(int));
        HASH_ITER(hh, hash[i], cur, next) {
            ans[i][j++] = cur->key;
            HASH_DEL(hash[i], cur);
            free(cur);
        }
    }
    return ans;
}