// 给你三个整数数组 nums1、nums2 和 nums3 ，请你构造并返回一个 元素各不相同的 数组，且由 至少 在 两个
// 数组中出现的所有值组成。数组中的元素可以按 任意 顺序排列。
//
//
//
// 示例 1：
//
//
// 输入：nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
// 输出：[3,2]
// 解释：至少在两个数组中出现的所有值为：
// - 3 ，在全部三个数组中都出现过。
// - 2 ，在数组 nums1 和 nums2 中出现过。
//
//
// 示例 2：
//
//
// 输入：nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
// 输出：[2,3,1]
// 解释：至少在两个数组中出现的所有值为：
// - 2 ，在数组 nums2 和 nums3 中出现过。
// - 3 ，在数组 nums1 和 nums2 中出现过。
// - 1 ，在数组 nums1 和 nums3 中出现过。
//
//
// 示例 3：
//
//
// 输入：nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
// 输出：[]
// 解释：不存在至少在两个数组中出现的值。
//
//
//
//
// 提示：
//
//
// 1 <= nums1.length, nums2.length, nums3.length <= 100
// 1 <= nums1[i], nums2[j], nums3[k] <= 100
//
//
// Related Topics 数组 哈希表 👍 52 👎 0

#define MAX 100
int *twoOutOfThree(int *nums1, int nums1Size, int *nums2, int nums2Size, int *nums3, int nums3Size, int *returnSize) {
    int ss[3][MAX + 1] = { 0 }, help[MAX], len = 0;
    for (int i = 0; i < nums1Size; ss[0][nums1[i++]] = 1) {}
    for (int i = 0; i < nums2Size; ss[1][nums2[i++]] = 1) {}
    for (int i = 0; i < nums3Size; ss[2][nums3[i++]] = 1) {}
    for (int i = 1; i <= MAX; ++i) {
        if (ss[0][i] + ss[1][i] + ss[2][i] >= 2) help[len++] = i;
    }
    int *ans = malloc((*returnSize = len) * sizeof(int));
    memcpy(ans, help, len * sizeof(int));
    return ans;
}
