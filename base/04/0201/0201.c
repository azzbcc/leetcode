// 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。
//
// 示例 1:
//
// 输入: [5,7]
// 输出: 4
//
// 示例 2:
//
// 输入: [0,1]
// 输出: 0
// Related Topics 位运算
// 👍 150 👎 0

int rangeBitwiseAnd(int m, int n) {
    int ans = m ^ n;

    if (ans > 0x1) ans |= ans >> 1;
    if (ans > 0x3) ans |= ans >> 2;
    if (ans > 0xf) ans |= ans >> 4;
    if (ans > 0xff) ans |= ans >> 8;
    if (ans > 0xffff) ans |= ans >> 16;

    return ~ans & m;
}
