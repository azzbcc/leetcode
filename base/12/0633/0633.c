// 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。
//
//
//
// 示例 1：
//
// 输入：c = 5
// 输出：true
// 解释：1 * 1 + 2 * 2 = 5
//
//
// 示例 2：
//
// 输入：c = 3
// 输出：false
//
//
// 示例 3：
//
// 输入：c = 4
// 输出：true
//
//
// 示例 4：
//
// 输入：c = 2
// 输出：true
//
//
// 示例 5：
//
// 输入：c = 1
// 输出：true
//
//
//
// 提示：
//
//
// 0 <= c <= 231 - 1
//
// Related Topics 数学
// 👍 204 👎 0

bool judgeSquareSum(int c) {
    for (long l = 0, r = sqrt(c), sum = r * r; l <= r;) {
        if (sum == c) return true;
        if (sum < c) {
            sum += 2 * l++ + 1;
        } else {
            sum -= 2 * r-- - 1;
        }
    }
    return false;
}