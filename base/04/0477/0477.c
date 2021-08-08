// 两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
//
// 计算一个数组中，任意两个数之间汉明距离的总和。
//
// 示例:
//
//
// 输入: 4, 14, 2
//
// 输出: 6
//
// 解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
// 所以答案为：
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 +2 + 2 = 6.
//
//
// 注意:
//
//
// 数组中元素的范围为从 0到 10^9。
// 数组的长度不超过 10^4。
//
// Related Topics 位运算
// 👍 134 👎 0

#if 0
int totalHammingDistance(int *nums, int size) {
    int sum = 0;
    for (uint32_t mask = 0x80000000, c; mask > 0; mask >>= 1) {
        c = 0;
        for (int j = 0; j < size; ++j) {
            if (mask & nums[j]) c++;
        }
        sum += (size - c) * c;
    }
    return sum;
}
#else
int totalHammingDistance(int *nums, int size) {
    int max = 0, sum = 0, c;
    for (int i = 0; i < size; ++i) {
        if (max < nums[i]) max = nums[i];
    }
    for (uint32_t mask = 1; mask <= max; mask <<= 1) {
        c = 0;
        for (int j = 0; j < size; ++j) {
            if (mask & nums[j]) c++;
        }
        sum += (size - c) * c;
    }
    return sum;
}
#endif
