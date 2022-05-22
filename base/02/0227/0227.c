// 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
//
// 整数除法仅保留整数部分。
//
//
//
//
//
// 示例 1：
//
//
// 输入：s = "3+2*2"
// 输出：7
//
//
// 示例 2：
//
//
// 输入：s = " 3/2 "
// 输出：1
//
//
// 示例 3：
//
//
// 输入：s = " 3+5 / 2 "
// 输出：5
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 3 * 105
// s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
// s 表示一个 有效表达式
// 表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
// 题目数据保证答案是一个 32-bit 整数
//
//
//
// Related Topics 栈 字符串
// 👍 302 👎 0

#define INIT_SIZE 0x100
#define INCR_SIZE 0x10

typedef struct {
    int top, size;
    int base[];
} sstack_t;
sstack_t *stack_create() {
    sstack_t *stack = malloc(sizeof(sstack_t) + INIT_SIZE * sizeof(int));
    stack->top = -1, stack->size = INIT_SIZE;
    return stack;
}
void stack_push(sstack_t **stack, int val) {
    sstack_t *s = *stack;
    if (++s->top >= s->size) *stack = s = realloc(s, sizeof(*s) + (s->size += INCR_SIZE) * sizeof(void *));
    s->base[s->top] = val;
}
int stack_peak(sstack_t *s) {
    return s->base[s->top];
}
int stack_pop(sstack_t *s) {
    return s->base[s->top--];
}
void stack_destroy(sstack_t *s) {
    free(s);
}

// 开二维数组存表
char operators[]    = "+-*/()#";
char priority[7][7] = { { '>', '>', '<', '<', '<', '>', '>' }, { '>', '>', '<', '<', '<', '>', '>' },
                        { '>', '>', '>', '>', '<', '>', '>' }, { '>', '>', '>', '>', '<', '>', '>' },
                        { '<', '<', '<', '<', '<', '=', '-' }, { '>', '>', '>', '>', '-', '>', '>' },
                        { '<', '<', '<', '<', '<', '-', '=' } };

char procede(int a, int b) {
    return priority[strchr(operators, a) - operators][strchr(operators, b) - operators];
}
int operator(int a, int op, int b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return -1;
}
int calculate(char *s) {
    sstack_t *nums = stack_create(), *oper = stack_create();

    stack_push(&oper, '#');
    for (int i = 0, num, except = 1; !i || s[i - 1]; ++i) {
        if (isblank(s[i])) continue;
        if (except && s[i] != '(') {
            if (s[i] == '-') except = -1;
            for (num = 0; isdigit(s[i]); i++) {
                num *= 10, num += s[i] - '0';
            }
            stack_push(&nums, except * num);
            except = 0, i -= 1;
            continue;
        }
        int op = s[i] ? s[i] : '#', n, m;
        switch (procede(stack_peak(oper), op)) {
        case '<':
            except = 1;
            stack_push(&oper, op);
            break;
        case '=':
            stack_pop(oper);
            break;
        case '>':
            i -= 1, n = stack_pop(nums), m = stack_pop(nums);
            stack_push(&nums, operator(m, stack_pop(oper), n));
            break;
        }
    }

    int ans = stack_pop(nums);

    stack_destroy(nums);
    stack_destroy(oper);
    return ans;
}