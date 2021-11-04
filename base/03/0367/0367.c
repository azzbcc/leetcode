// 给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
//
// 进阶：不要 使用任何内置的库函数，如 sqrt 。
//
//
//
// 示例 1：
//
//
// 输入：num = 16
// 输出：true
//
//
// 示例 2：
//
//
// 输入：num = 14
// 输出：false
//
//
//
//
// 提示：
//
//
// 1 <= num <= 2^31 - 1
//
// Related Topics 数学 二分查找 👍 275 👎 0

bool isPerfectSquare(int num) {
    if (num < 2) return true;
    for (int l = 1, r = num / 2; l <= r;) {
        long mid = l + (r - l) / 2;
        if (mid * mid == num) return true;
        if (mid * mid < num) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return false;
}