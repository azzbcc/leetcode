// 给你一个整数数组 arr ，数组中的每个整数 互不相同 。另有一个由整数数组构成的数组 pieces，其中的整数也 互不相同
// 请你以 任意顺序 连接pieces 中的数组以形成 arr 。但是，不允许 对每个数组 pieces[i] 中的整数重新排序。
//
// 如果可以连接 pieces 中的数组形成 arr ，返回 true ；否则，返回 false 。
//
//
//
// 示例 1：
//
//
// 输入：arr = [15,88], pieces = [[88],[15]]
// 输出：true
// 解释：依次连接 [15] 和 [88]
//
//
// 示例 2：
//
//
// 输入：arr = [49,18,16], pieces = [[16,18,49]]
// 输出：false
// 解释：即便数字相符，也不能重新排列 pieces[0]
//
//
// 示例 3：
//
//
// 输入：arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
// 输出：true
// 解释：依次连接 [91]、[4,64] 和 [78]
//
//
//
// 提示：
//
//
// 1 <= pieces.length <= arr.length <= 100
// sum(pieces[i].length) == arr.length
// 1 <= pieces[i].length <= arr.length
// 1 <= arr[i], pieces[i][j] <= 100
// arr 中的整数 互不相同
// pieces 中的整数 互不相同（也就是说，如果将 pieces 扁平化成一维数组，数组中的所有整数互不相同）
//
//
// Related Topics 数组 哈希表 👍 84 👎 0

#if 0
#define check_end(...)                                                                                                 \
    if (__VA_ARGS__) {                                                                                                 \
        ans = false;                                                                                                   \
        goto end;                                                                                                      \
    }
typedef struct {
    int key, pos;
    UT_hash_handle hh;
} hash_t;
int hash_pos(hash_t *t, int key) {
    hash_t *cur;
    HASH_FIND_INT(t, &key, cur);
    return cur ? cur->pos : -1;
}
bool canFormArray(int *arr, int arrSize, int **pieces, int size, int *colSize) {
    bool ans = true;
    hash_t nodes[arrSize], *hash = NULL;
    for (int i = 0; i < arrSize; ++i) {
        nodes[i] = (hash_t) { arr[i], i };
        HASH_ADD_INT(hash, key, &nodes[i]);
    }
    for (int i = 0, pos; i < size; ++i) {
        check_end(pos = hash_pos(hash, pieces[i][0]), pos == -1);
        for (int j = 1; j < colSize[i]; ++j) {
            check_end(pos + j != hash_pos(hash, pieces[i][j]));
        }
    }
end:
    HASH_CLEAR(hh, hash);
    return ans;
}
#else
typedef struct {
    int key, len, *data;
    UT_hash_handle hh;
} hash_t;
bool canFormArray(int *arr, int arrSize, int **pieces, int size, int *colSize) {
    bool ans = true;
    hash_t nodes[arrSize], *hash = NULL, *cur;
    for (int i = 0; i < size; i++) {
        nodes[i] = (hash_t) { pieces[i][0], colSize[i], pieces[i] };
        HASH_ADD_INT(hash, key, &nodes[i]);
    }
    for (int i = 0; ans && i < arrSize;) {
        HASH_FIND_INT(hash, &arr[i], cur);
        if (!cur || i + cur->len > arrSize) ans = false;
        for (int j = 1; ans && j < cur->len; j++) {
            ans = arr[i + j] == cur->data[j];
        }
        if (ans) i += cur->len;
    }
    HASH_CLEAR(hh, hash);
    return ans;
}
#endif