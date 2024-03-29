// 编写一个算法来判断一个数 n 是不是快乐数。
//
// 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为
// 1，也可能是 无限循环 但始终变不到 1。
// 如果 可以变为 1，那么这个数就是快乐数。
//
// 如果 n 是快乐数就返回 True ；不是，则返回 False 。
//
//
//
// 示例：
//
// 输入：19
// 输出：true
// 解释：
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
//
// Related Topics 哈希表 数学
// 👍 422 👎 0
#define MAX 810

int S(int n) {
    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}
int happy(int n, int *arr) {
    if (arr[n]) return 2 - (arr[n] == 1);

    arr[n] = 3;

    return arr[n] = happy(S(n), arr);
}
bool isHappy(int n) {
    if (n > MAX) n = S(n);
    static int arr[MAX + 1] = { 2, 1 };
    return 1 == happy(n, arr);
}
