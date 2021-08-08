// 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
//
//
//
// 在杨辉三角中，每个数是它左上方和右上方的数的和。
//
// 示例:
//
// 输入: 3
// 输出: [1,3,3,1]
//
//
// 进阶：
//
// 你可以优化你的算法到 O(k) 空间复杂度吗？
// Related Topics 数组
// 👍 196 👎 0

#if 0
int *getRow(int k, int *returnSize) {
    int *ans = malloc((*returnSize = k + 1) * sizeof(int));
    for (int i = 0; i <= k; ans[i++] = 1) {
        for (int j = i - 1; j > 0; --j) {
            ans[j] += ans[j - 1];
        }
    }

    return ans;
}
#else
int C(int m, int n) {
    long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * (m - i) / (i + 1);
    }
    return ans;
}
int *getRow(int k, int *returnSize) {
    int *ans = malloc((*returnSize = k + 1) * sizeof(int));
    for (int i = 0; i <= k; ++i) {
        ans[i] = C(k, i);
    }
    return ans;
}
#endif