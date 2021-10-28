// 给定两个整数数组a和b，计算具有最小差绝对值的一对数值（每个数组中取一个值），并返回该对数值的差
//
//
//
// 示例：
//
//
// 输入：{1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
// 输出：3，即数值对(11, 8)
//
//
//
//
// 提示：
//
//
// 1 <= a.length, b.length <= 100000
// -2147483648 <= a[i], b[i] <= 2147483647
// 正确结果在区间 [0, 2147483647] 内
//
// Related Topics 数组 双指针 二分查找 排序 👍 40 👎 0

int cmp(const void *a, const void *b) {
    int pa = *( int * )a, pb = *( int * )b;
    return pa >= pb ? 1 - (pa == pb) : -1;
}
int smallestDifference(int *a, int aSize, int *b, int bSize) {
    qsort(a, aSize, sizeof(int), cmp);
    qsort(b, bSize, sizeof(int), cmp);

    long ans = INT32_MAX;
    for (int i = 0, j = 0; i < aSize; ++i) {
        for (; j < bSize && b[j] < a[i]; ++j) {}
        if (j) ans = fmin(ans, 0L + a[i] - b[j - 1]);
        if (j == bSize) break;
        ans = fmin(ans, 0L + b[j] - a[i]);
    }
    return ans;
}
