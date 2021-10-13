// 写一个程序，输出从 1 到 n 数字的字符串表示。
//
// 1. 如果 n 是3的倍数，输出“Fizz”；
//
// 2. 如果 n 是5的倍数，输出“Buzz”；
//
// 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
//
// 示例：
//
// n = 15,
//
// 返回:
// [
//    "1",
//    "2",
//    "Fizz",
//    "4",
//    "Buzz",
//    "Fizz",
//    "7",
//    "8",
//    "Fizz",
//    "Buzz",
//    "11",
//    "Fizz",
//    "13",
//    "14",
//    "FizzBuzz"
// ]
//
// Related Topics 数学 字符串 模拟 👍 126 👎 0

char **fizzBuzz(int n, int *returnSize) {
    char str[11];
    char **ans = malloc((*returnSize = n) * sizeof(char *));

    for (int i = 1; i <= n; ++i) {
        if (i % 3 && i % 5) {
            sprintf(str, "%d", i);
            ans[i - 1] = strdup(str);
        } else if (i % 3) {
            ans[i - 1] = strdup("Buzz");
        } else if (i % 5) {
            ans[i - 1] = strdup("Fizz");
        } else {
            ans[i - 1] = strdup("FizzBuzz");
        }
    }

    return ans;
}
