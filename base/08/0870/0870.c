// 给定两个大小相等的数组 nums1 和 nums2，nums1 相对于 nums 的优势可以用满足 nums1[i] > nums2[i] 的索引 i 的数目来描述。
//
// 返回 nums1 的任意排列，使其相对于 nums2 的优势最大化。
//
//
//
// 示例 1：
//
//
// 输入：nums1 = [2,7,11,15], nums2 = [1,10,4,11]
// 输出：[2,11,7,15]
//
//
// 示例 2：
//
//
// 输入：nums1 = [12,24,8,32], nums2 = [13,25,32,11]
// 输出：[24,32,8,12]
//
//
//
//
// 提示：
//
//
// 1 <= nums1.length <= 10⁵
// nums2.length == nums1.length
// 0 <= nums1[i], nums2[i] <= 10⁹
//
//
// Related Topics 贪心 数组 双指针 排序 👍 271 👎 0

int cmp(const void *a, const void *b) {
    int *pa = ( int * )a, *pb = ( int * )b;
    return pa[1] - pb[1];
}
int *advantageCount(int *nums1, int size, int *nums2, int nums2Size, int *returnSize) {
    int s1[size][2], s2[size][2];
    int *ans = malloc((*returnSize = size) * sizeof(int));
    for (int i = 0; i < size; ++i) {
        s1[i][0] = i, s1[i][1] = nums1[i];
        s2[i][0] = i, s2[i][1] = nums2[i];
    }
    qsort(s1, size, sizeof(s1[0]), cmp);
    qsort(s2, size, sizeof(s2[0]), cmp);
    for (int i = 0, l = 0, r = size - 1; i < size; ++i) {
        ans[s2[l][1] < s1[i][1] ? s2[l++][0] : s2[r--][0]] = s1[i][1];
    }
    return ans;
}
