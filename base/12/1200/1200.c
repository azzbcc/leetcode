// 给你个整数数组 arr，其中每个元素都 不相同。
//
// 请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
//
//
//
// 示例 1：
//
// 输入：arr = [4,2,1,3]
// 输出：[[1,2],[2,3],[3,4]]
//
//
// 示例 2：
//
// 输入：arr = [1,3,6,10,15]
// 输出：[[1,3]]
//
//
// 示例 3：
//
// 输入：arr = [3,8,-10,23,19,-4,-14,27]
// 输出：[[-14,-10],[19,23],[23,27]]
//
//
//
//
// 提示：
//
//
// 2 <= arr.length <= 10^5
// -10^6 <= arr[i] <= 10^6
//
// Related Topics 数组 排序 👍 81 👎 0

int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int **minimumAbsDifference(int *arr, int size, int *returnSize, int **returnColumnSizes) {
    int min = INT32_MAX, *help[size], len = 0;
    qsort(arr, size, sizeof(int), cmp);
    for (int i = 1; i < size; ++i) {
        min = fmin(min, arr[i] - arr[i - 1]);
    }
    for (int i = 1; i < size; ++i) {
        if (arr[i] - arr[i - 1] != min) continue;
        help[len] = malloc(2 * sizeof(int));
        memcpy(help[len++], &arr[i - 1], 2 * sizeof(int));
    }
    int **ans          = malloc((*returnSize = len) * sizeof(int *));
    *returnColumnSizes = malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i) {
        (*returnColumnSizes)[i] = 2, ans[i] = help[i];
    }
    return ans;
}
