// 搜索旋转数组。给定一个排序后的数组，包含n个整数，但这个数组已被旋转过很多次了，次数不详。
// 请编写代码找出数组中的某个元素，假设数组元素原先是按升序排列的。若有多个相同元素，返回索引值最小的一个。
//
// 示例1:
//
// 输入: arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 5
// 输出: 8（元素5在该数组中的索引）
//
//
// 示例2:
//
// 输入：arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 11
// 输出：-1 （没有找到）
//
//
// 提示:
//
//
// arr 长度范围在[1, 1000000]之间
//
//
// Related Topics 数组 二分查找 👍 130 👎 0

int search(int *arr, int size, int t) {
    for (int l = 0, r = size - 1, mid; l <= r;) {
        if (arr[l] == t) return l;

        mid = (l + r) / 2;
        if (arr[mid] == t) {
            r = mid;
        } else if (arr[0] < arr[mid]) {
            if (arr[0] <= t && t < arr[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else if (arr[0] > arr[mid]) {
            if (arr[mid] < t && t <= arr[size - 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {
            l += 1;
        }
    }
    return -1;
}
