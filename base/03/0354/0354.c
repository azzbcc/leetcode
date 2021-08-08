// 给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h)出现。当另一个信封的宽度和高度都比这个信封大的时候，
// 这个信封就可以放进另一个信封里，如 同俄罗斯套娃一样。
//
// 请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
//
// 说明:
// 不允许旋转信封。
//
// 示例:
//
// 输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// 输出: 3
// 解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
//
// Related Topics 二分查找 动态规划
// 👍 360 👎 0

#if 0
int max(int a, int b) {
    return a > b ? a : b;
}
int cmp(const void *a, const void *b) {
    int *pa = *( int ** )a, *pb = *( int ** )b;
    if (pa[0] == pb[0]) return pa[1] - pb[1];
    return pa[0] - pb[0];
}
int maxEnvelopes(int **envelopes, int size, int *colSize) {
    if (!size) return 0;
    int dp[size], ans = 0;

    memset(dp, 0, sizeof(dp));
    qsort(envelopes, size, sizeof(int **), cmp);
    for (int i = 1; i < size; ++i) {
        for (int j = 0; envelopes[j][0] < envelopes[i][0]; ++j) {
            if (envelopes[i][1] > envelopes[j][1]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    return ans + 1;
}
#else
int cmp(const void *a, const void *b) {
    int *pa = *( int ** )a, *pb = *( int ** )b;
    if (pa[0] == pb[0]) return pb[1] - pa[1];
    return pa[0] - pb[0];
}
int maxEnvelopes(int **envelopes, int size, int *colSize) {
    if (!size) return 0;

    int dp[size], top = 0;
    qsort(envelopes, size, sizeof(int **), cmp);

    dp[0] = envelopes[0][1];
    for (int i = 1; i < size; ++i) {
        if (envelopes[i][1] > dp[top]) {
            dp[++top] = envelopes[i][1];
        } else {
            int l = 0;
            for (int mid, r = top; l <= r;) {
                mid = (l + r) / 2;
                if (dp[mid] < envelopes[i][1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            dp[l] = envelopes[i][1];
        }
    }
    return top + 1;
}
#endif
