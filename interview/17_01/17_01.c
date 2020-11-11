// 设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。
//
// 示例:
//
// 输入: a = 1, b = 1
// 输出: 2
//
//
//
// 提示：
//
//
// a, b 均可能是负数或 0
// 结果不会溢出 32 位整数
//
// Related Topics 位运算
// 👍 26 👎 0

int add(int a, int b) {
    while (b) {
        uint32_t xor = a ^ b, and = a & b;
        a = xor, b = and << 1;
    }

    return a;
}
