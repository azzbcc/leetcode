// 给你一个由数字和运算符组成的字符串 expression
// ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以按任意顺序 返回答案。
//
// 生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 10⁴ 。
//
//
//
// 示例 1：
//
//
// 输入：expression = "2-1-1"
// 输出：[0,2]
// 解释：
// ((2-1)-1) = 0
// (2-(1-1)) = 2
//
//
// 示例 2：
//
//
// 输入：expression = "2*3-4*5"
// 输出：[-34,-14,-10,-10,10]
// 解释：
// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
//
//
//
//
// 提示：
//
//
// 1 <= expression.length <= 20
// expression 由数字和算符 '+'、'-' 和 '*' 组成。
// 输入表达式中的所有整数值在范围 [0, 99]
//
// Related Topics 递归 记忆化搜索 数学 字符串 动态规划 👍 673 👎 0

#define MAXN 4862
int operator(int left, int op, int right) {
    if (op == '+') return left + right;
    if (op == '-') return left - right;
    if (op == '*') return left * right;
    return 0;
}
int diffWaysToComputeReal(char *exp, int size, int res[]) {
    int len = 0, left[MAXN], right[MAXN];
    for (int i = 0; i < size; ++i) {
        if (isdigit(exp[i])) continue;
        int ll = diffWaysToComputeReal(exp, i, left);
        int rr = diffWaysToComputeReal(exp + i + 1, size - i - 1, right);
        for (int j = 0; j < ll; ++j) {
            for (int k = 0; k < rr; ++k) {
                res[len++] = operator(left[j], exp[i], right[k]);
            }
        }
    }
    if (len == 0) {
        *res = 0, len = 1;
        for (int i = 0; i < size; ++i) {
            *res *= 10, *res += exp[i] - '0';
        }
    }
    return len;
}
int *diffWaysToCompute(char *expression, int *returnSize) {
    int help[MAXN], len = diffWaysToComputeReal(expression, strlen(expression), help);

    int *ans = malloc((*returnSize = len) * sizeof(int));
    memcpy(ans, help, len * sizeof(int));
    return ans;
}
