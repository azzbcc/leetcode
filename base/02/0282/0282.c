// 给定一个仅包含数字 0-9 的字符串 num 和一个目标值整数 target ，
// 在 num 的数字之间添加 二元 运算符（不是一元）+、- 或 * ，
// 返回所有能够得到目标值的表达式。
//
//
//
// 示例 1:
//
//
// 输入: num = "123", target = 6
// 输出: ["1+2+3", "1*2*3"]
//
//
// 示例 2:
//
//
// 输入: num = "232", target = 8
// 输出: ["2*3+2", "2+3*2"]
//
// 示例 3:
//
//
// 输入: num = "105", target = 5
// 输出: ["1*0+5","10-5"]
//
// 示例 4:
//
//
// 输入: num = "00", target = 0
// 输出: ["0+0", "0-0", "0*0"]
//
//
// 示例 5:
//
//
// 输入: num = "3456237490", target = 9191
// 输出: []
//
//
//
// 提示：
//
//
// 1 <= num.length <= 10
// num 仅含数字
// -2³¹ <= target <= 2³¹ - 1
//
// Related Topics 数学 字符串 回溯 👍 325 👎 0

#define MAXN 0x1000
#define MAXM 21

typedef struct {
    int top;
    long data[MAXM];
} sstack_t;
int help_len;
char *help[MAXN];
long operator(long a, char op, long b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return -1;
}
void stack_simplify(sstack_t *s) {
    for (; s->top; s->top -= 2) {
        s->data[s->top - 2] = operator(s->data[s->top - 2], ( char )s->data[s->top - 1], s->data[s->top]);
    }
}
void dfs(char *str, int target, sstack_t *s, char res[], int pos) {
    if (!*str) {
        res[pos] = '\0';
        stack_simplify(s);
        if (s->data[0] == target) help[help_len++] = strdup(res);
        return;
    }
    sstack_t ss[4] = { *s, *s, *s, *s }, *sp = &ss[0];

    if (sp->data[sp->top]) {
        res[pos] = *str, sp->data[sp->top] = sp->data[sp->top] * 10 + *str - '0';
        dfs(str + 1, target, sp, res, pos + 1);
    }
    // add '+'
    stack_simplify(++sp);
    res[pos] = '+', res[pos + 1] = *str;
    sp->data[++sp->top] = '+', sp->data[++sp->top] = *str - '0';
    dfs(str + 1, target, sp, res, pos + 2);

    // add '-'
    stack_simplify(++sp);
    res[pos] = '-', res[pos + 1] = *str;
    sp->data[++sp->top] = '-', sp->data[++sp->top] = *str - '0';
    dfs(str + 1, target, sp, res, pos + 2);

    // add '*'
    for (sp++; sp->top && sp->data[sp->top - 1] == '*'; sp->top -= 2) {
        sp->data[sp->top - 2] = sp->data[sp->top - 2] * sp->data[sp->top];
    }
    res[pos] = '*', res[pos + 1] = *str;
    sp->data[++sp->top] = '*', sp->data[++sp->top] = *str - '0';
    dfs(str + 1, target, sp, res, pos + 2);
}
char **addOperators(char *num, int target, int *returnSize) {
    char res[MAXM]   = { *num };
    sstack_t stack[1] = { { 0, { *num++ - '0' } } };

    help_len = 0;
    dfs(num, target, stack, res, 1);

    char **ans = malloc((*returnSize = help_len) * sizeof(char *));
    memcpy(ans, help, help_len * sizeof(char *));
    return ans;
}
