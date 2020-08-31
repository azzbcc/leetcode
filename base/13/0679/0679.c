//你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
//
// 示例 1:
//
// 输入: [4, 1, 8, 7]
// 输出: True
// 解释: (8-4) * (7-1) = 24
//
//
// 示例 2:
//
// 输入: [1, 2, 1, 2]
// 输出: False
//
//
// 注意:
//
//
// 除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
// 每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1
// 是不允许的。 你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
//
// Related Topics 深度优先搜索
// 👍 165 👎 0

typedef struct {
    int dividend;
    int divisor;
} data_type_t;

static char *operators = "+-*/";

static int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
static int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
static int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
data_type_t operater(data_type_t first, data_type_t second, char op) {
    data_type_t result = first;
    if (op == '*' || op == '/') {
        if (op == '/') {
            int tmp         = second.divisor;
            second.divisor  = second.dividend;
            second.dividend = tmp;
        }
        result.dividend *= second.dividend;
        result.divisor *= second.divisor;
    } else {
        if (result.divisor != second.divisor) {
            result.divisor = lcm(result.divisor, second.divisor);
            result.dividend *= result.divisor / first.divisor;
            second.dividend *= result.divisor / second.divisor;
        }
        if (op == '-') second.dividend = -second.dividend;
        result.dividend += second.dividend;
    }
    return result;
}
bool check24(const char *s) {
    int top              = -1;
    data_type_t stack[4] = { 0 };

    for (int i = 0; s[i]; ++i) {
        if (isdigit(s[i])) {
            stack[++top] = (data_type_t) { s[i] - '0', 1 };
        } else {
            data_type_t a = stack[top--], b = stack[top--];
            stack[++top] = operater(b, a, s[i]);
            if (!stack[top].divisor) {
                return false;
            }
        }
    }
    return 24 * stack[top].divisor == stack[top].dividend;
}
bool dfs(int *nums, int numLeft, char *s, int len, int chLeft) {
    if (numLeft <= 0 && chLeft <= 0) {
        s[len] = '\0';
        return check24(s);
    }
    if (numLeft > 0) {
        s[len] = *nums + '0';
        if (dfs(nums + 1, numLeft - 1, s, len + 1, chLeft)) return true;
    }
    if (numLeft < chLeft) {
        for (int i = 0; operators[i]; ++i) {
            s[len] = operators[i];
            if (dfs(nums, numLeft, s, len + 1, chLeft - 1)) return true;
        }
    }
    return false;
}

bool judgePoint24(int *nums, int size) {
    char str[8] = { '\0' };

    qsort(nums, size, sizeof(int), cmp);
    while (true) {
        // do sth.
        if (dfs(nums, size, str, 0, 3)) return true;

        // query next permutation
        int m, n; // 最后一个比后驱小的数，最后一个比m大的数
        for (m = size - 2; m >= 0 && nums[m] >= nums[m + 1]; --m) {}
        if (m < 0) break;
        for (n = size - 1; nums[n] <= nums[m]; --n) {}
        for (int t = -1; t < 0; t = nums[n], nums[n] = nums[m], nums[m] = t) {}
        for (int l = m, r = size, t; ++l < --r;) {
            t = nums[l], nums[l] = nums[r], nums[r] = t;
        }
    }
    return false;
}
