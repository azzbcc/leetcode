// 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k
// 个数。返回的结果必须要是按升序排好的。
//
// 整数 a 比整数 b 更接近 x 需要满足：
//
//
// |a - x| < |b - x| 或者
// |a - x| == |b - x| 且 a < b
//
//
//
//
// 示例 1：
//
//
// 输入：arr = [1,2,3,4,5], k = 4, x = 3
// 输出：[1,2,3,4]
//
//
// 示例 2：
//
//
// 输入：arr = [1,2,3,4,5], k = 4, x = -1
// 输出：[1,2,3,4]
//
//
//
//
// 提示：
//
//
// 1 <= k <= arr.length
// 1 <= arr.length <= 10⁴
//
// arr 按 升序 排列
// -10⁴ <= arr[i], x <= 10⁴
//
//
// Related Topics 数组 双指针 二分查找 排序 堆（优先队列） 👍 382 👎 0

int *findClosestElements(int *arr, int size, int k, int x, int *returnSize) {
    int pos, l = 0;
    int *ans = malloc((*returnSize = k) * sizeof(int));
    for (int mid, r = size - 1; l <= r;) {
        mid = (l + r) / 2;
        if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    for (pos = fmin(size - k, l); pos > 0; --pos) {
        if (abs(arr[pos - 1] - x) > abs(arr[pos + k - 1] - x)) break;
    }
    memcpy(ans, arr + pos, k * sizeof(int));
    return ans;
}
