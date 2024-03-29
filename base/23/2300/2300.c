// 给你两个正整数数组 spells 和 potions ，长度分别为 n 和 m ，
// 其中 spells[i] 表示第 i 个咒语的能量强度，potions[j] 表示第 j 瓶药水的能量强度。
//
// 同时给你一个整数 success 。一个咒语和药水的能量强度 相乘 如果 大于等于 success ，那么它们视为一对 成功 的组合。
//
// 请你返回一个长度为 n 的整数数组 pairs，其中 pairs[i] 是能跟第 i 个咒语成功组合的 药水 数目。
//
//
//
// 示例 1：
//
// 输入：spells = [5,1,3], potions = [1,2,3,4,5], success = 7
// 输出：[4,0,3]
// 解释：
// - 第 0 个咒语：5 * [1,2,3,4,5] = [5,10,15,20,25] 。总共 4 个成功组合。
// - 第 1 个咒语：1 * [1,2,3,4,5] = [1,2,3,4,5] 。总共 0 个成功组合。
// - 第 2 个咒语：3 * [1,2,3,4,5] = [3,6,9,12,15] 。总共 3 个成功组合。
// 所以返回 [4,0,3] 。
//
//
// 示例 2：
//
// 输入：spells = [3,1,2], potions = [8,5,8], success = 16
// 输出：[2,0,2]
// 解释：
// - 第 0 个咒语：3 * [8,5,8] = [24,15,24] 。总共 2 个成功组合。
// - 第 1 个咒语：1 * [8,5,8] = [8,5,8] 。总共 0 个成功组合。
// - 第 2 个咒语：2 * [8,5,8] = [16,10,16] 。总共 2 个成功组合。
// 所以返回 [2,0,2] 。
//
//
//
//
// 提示：
//
//
// n == spells.length
// m == potions.length
// 1 <= n, m <= 10⁵
// 1 <= spells[i], potions[i] <= 10⁵
// 1 <= success <= 10¹⁰
//
//
// Related Topics 数组 双指针 二分查找 排序 👍 63 👎 0

int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int count(int arr[], int size, int mul, long long int target) {
    int l = 0, r = size - 1;
    for (int mid; l <= r;) {
        mid = (l + r) / 2;
        if (1L * arr[mid] * mul >= target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return size - l;
}
int *successfulPairs(int *spells, int sSize, int *potions, int pSize, long long success, int *returnSize) {
    int *ans = malloc((*returnSize = sSize) * sizeof(int));
    qsort(potions, pSize, sizeof(int), cmp);
    for (int i = 0; i < sSize; ++i) {
        ans[i] = count(potions, pSize, spells[i], success);
    }
    return ans;
}
