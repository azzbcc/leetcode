// 给定一个放有字母和数字的数组，找到最长的子数组，且包含的字母和数字的个数相同。
//
// 返回该子数组，若存在多个最长子数组，返回左端点下标值最小的子数组。若不存在这样的数组，返回一个空数组。
//
// 示例 1:
//
//
// 输入: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]
//
// 输出: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]
//
//
// 示例 2:
//
//
// 输入: ["A","A"]
//
// 输出: []
//
//
// 提示：
//
//
// array.length <= 100000
//
//
// Related Topics 数组 哈希表 前缀和 👍 115 👎 0

typedef struct {
    int key, index;
    UT_hash_handle hh;
} *hash_t;
char **findLongestSubarray(char **array, int size, int *returnSize) {
    int len = 0, start = 0;
    hash_t cur, next, hash = NULL;
    cur = malloc(sizeof(*cur)), cur->key = 0, cur->index = -1;
    HASH_ADD_INT(hash, key, cur);
    for (int i = 0, now = 0; i < size; ++i) {
        now += isdigit(array[i][0]) ? 1 : -1;
        HASH_FIND_INT(hash, &now, cur);
        if (!cur) {
            cur = malloc(sizeof(*cur)), cur->key = now, cur->index = i;
            HASH_ADD_INT(hash, key, cur);
        } else if (i - cur->index > len) {
            start = cur->index + 1, len = i - cur->index;
        }
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    char **ans = malloc((*returnSize = len) * sizeof(char *));
    memcpy(ans, array + start, len * sizeof(char *));
    return ans;
}
