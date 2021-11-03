// 给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。
//
// 序号代表了一个元素有多大。序号编号的规则如下：
//
//
// 序号从 1 开始编号。
// 一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
// 每个数字的序号都应该尽可能地小。
//
//
//
//
// 示例 1：
//
// 输入：arr = [40,10,20,30]
// 输出：[4,1,2,3]
// 解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。
//
// 示例 2：
//
// 输入：arr = [100,100,100]
// 输出：[1,1,1]
// 解释：所有元素有相同的序号。
//
//
// 示例 3：
//
// 输入：arr = [37,12,28,9,100,56,80,5,12]
// 输出：[5,3,4,2,8,6,7,1,3]
//
//
//
//
// 提示：
//
//
// 0 <= arr.length <= 10⁵
// -10⁹ <= arr[i] <= 10⁹
//
// Related Topics 数组 哈希表 排序 👍 55 👎 0

typedef struct {
    int key, index;
    UT_hash_handle hh;
} hash_t;
int cmp(hash_t *a, hash_t *b) {
    return a->key >= b->key ? a->key != b->key : -1;
}
int *arrayRankTransform(int *arr, int size, int *returnSize) {
    hash_t nodes[size + 1], *hash = NULL, *cur, *next;
    int index = 0, *ans = malloc((*returnSize = size) * sizeof(int));

    for (int i = 0; i < size; ++i) {
        HASH_FIND_INT(hash, &arr[i], cur);
        if (cur) continue;
        nodes[i].key = arr[i];
        HASH_ADD_INT(hash, key, &nodes[i]);
    }
    HASH_SORT(hash, cmp);
    HASH_ITER(hh, hash, cur, next) { cur->index = ++index; }
    for (int i = 0; i < size; ++i) {
        HASH_FIND_INT(hash, &arr[i], cur);
        ans[i] = cur->index;
    }

    HASH_CLEAR(hh, hash);
    return ans;
}