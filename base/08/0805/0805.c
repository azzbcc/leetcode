// 给定的整数数组 A ，我们要将 A数组 中的每个元素移动到 B数组 或者 C数组中。（B数组和C数组在开始的时候都为空）
//
// 返回true ，当且仅当在我们的完成这样的移动后，可使得B数组的平均值和C数组的平均值相等，并且B数组和C数组都不为空。
//
//
// 示例:
// 输入:
// [1,2,3,4,5,6,7,8]
// 输出: true
// 解释: 我们可以将数组分割为 [1,4,5,8] 和 [2,3,6,7], 他们的平均值都是4.5。
//
//
// 注意:
//
//
// A 数组的长度范围为 [1, 30].
// A[i] 的数据范围为 [0, 10000].
//
// Related Topics 数学
// 👍 53 👎 0

int gcd(int a, int b) {
    for (int tmp; b; tmp = a % b, a = b, b = tmp) {}
    return a;
}
int array_gcd(int arr[], int size) {
    if (!size) return 1;

    if (!*arr) return array_gcd(arr + 1, size - 1);

    int ans = arr[0];
    for (int i = 1; i < size; ++i) {
        ans = gcd(ans, arr[i]);
    }
    return ans;
}
bool splitArraySameAverage(int *A, int ASize) {
    // 约分
    int r = array_gcd(A, ASize);
    for (int i = 0; i < ASize; A[i++] /= r) {}

    // 求和
    int sum = 0, max = 0, max_sum = 0;
    for (int i = 0; i < ASize; sum += A[i++]) {}
    if (!sum) return ASize > 1;

    // 检查是否存在能整除的分组
    for (int c = ASize / 2; c; --c) {
        if (c * sum % ASize == 0) {
            max = c, max_sum = sum * c / ASize;
            break;
        }
    }
    if (!max) return false;

    // 列举所有可能的和
    bool dp[max + 1][max_sum + 1];
    memset(dp, false, sizeof(dp));

    dp[0][0] = true;
    for (int i = 0; i < ASize; ++i) {
        for (int j = max; j; --j) {
            for (int k = max_sum - A[i]; k >= 0; --k) {
                dp[j][k + A[i]] |= dp[j - 1][k];
            }
        }
    }
    for (int c = 1; c <= ASize / 2; ++c) {
        if (c * sum % ASize) continue;
        if (dp[c][c * sum / ASize]) return true;
    }

    return false;
}
