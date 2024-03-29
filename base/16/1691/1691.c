// 给你 n 个长方体 cuboids ，其中第 i 个长方体的长宽高表示为 cuboids[i] = [widthi, lengthi, heighti]（下标从 0
// 开始）。请你从 cuboids 选出一个 子集 ，并将它们堆叠起来。
//
// 如果 widthi <= widthj 且 lengthi <= lengthj 且 heighti <= heightj ，你就可以将长方体 i 堆叠在长方体 j
// 上。你可以通过旋转把长方体的长宽高重新排列，以将它放在另一个长方体上。
//
// 返回 堆叠长方体 cuboids 可以得到的 最大高度 。
//
//
//
// 示例 1：
//
//
//
//
// 输入：cuboids = [[50,45,20],[95,37,53],[45,23,12]]
// 输出：190
// 解释：
// 第 1 个长方体放在底部，53x37 的一面朝下，高度为 95 。
// 第 0 个长方体放在中间，45x20 的一面朝下，高度为 50 。
// 第 2 个长方体放在上面，23x12 的一面朝下，高度为 45 。
// 总高度是 95 + 50 + 45 = 190 。
//
//
// 示例 2：
//
//
// 输入：cuboids = [[38,25,45],[76,35,3]]
// 输出：76
// 解释：
// 无法将任何长方体放在另一个上面。
// 选择第 1 个长方体然后旋转它，使 35x3 的一面朝下，其高度为 76 。
//
//
// 示例 3：
//
//
// 输入：cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
// 输出：102
// 解释：
// 重新排列长方体后，可以看到所有长方体的尺寸都相同。
// 你可以把 11x7 的一面朝下，这样它们的高度就是 17 。
// 堆叠长方体的最大高度为 6 * 17 = 102 。
//
//
//
//
// 提示：
//
//
// n == cuboids.length
// 1 <= n <= 100
// 1 <= widthi, lengthi, heighti <= 100
//
//
// Related Topics 数组 动态规划 排序 👍 95 👎 0

void cuboid_sort(int *cuboids) {
    int a = cuboids[0], b = cuboids[1], c = cuboids[2];
    for (int tmp = a; tmp > b; a = b, b = tmp) {}
    for (int tmp = a; tmp > c; a = c, c = tmp) {}
    for (int tmp = b; tmp > c; b = c, c = tmp) {}
    cuboids[0] = a, cuboids[1] = b, cuboids[2] = c;
}
int cmp(const void *a, const void *b) {
    int *pa = *( int ** )a, *pb = *( int ** )b;
    return pa[0] + pa[1] + pa[2] - pb[0] - pb[1] - pb[2];
}
int maxHeight(int **cuboids, int size, int *colSize) {
    int dp[size], ans = 0;
    for (int i = 0; i < size; cuboid_sort(cuboids[i++])) {}
    qsort(cuboids, size, sizeof(int *), cmp);
    for (int i = 0; i < size; ++i) {
        dp[i] = cuboids[i][2];
        for (int j = 0; j < i; ++j) {
            if (cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]) {
                dp[i] = fmax(dp[i], cuboids[i][2] + dp[j]);
            }
        }
        ans = fmax(ans, dp[i]);
    }
    return ans;
}
