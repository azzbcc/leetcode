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
    union {
        struct {
            int16_t dividend;
            int16_t divisor;
        };
        int32_t d;
    };
} data_type_t;

static char *operators = "+-*/ab";

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
data_type_t operater(data_type_t a, data_type_t b, char op) {
    if (op == 'a' || op == 'b') {
        data_type_t tmp;
        tmp = a, a = b, b = tmp;
        op  = op == 'a' ? '-' : '/';
    }
    if (op == '*' || op == '/') {
        for (int tmp = b.dividend; op == '/' && tmp != b.divisor; b.dividend = b.divisor, b.divisor = tmp) {}
        a.dividend *= b.dividend, a.divisor *= b.divisor;
    } else {
        if (a.divisor != b.divisor) {
            int base = lcm(a.divisor, b.divisor);
            a.dividend *= base / a.divisor, a.divisor = base;
            b.dividend *= base / b.divisor;
        }
        if (op == '-') b.dividend = -b.dividend;
        a.dividend += b.dividend;
    }
    return a;
}
bool dfs(data_type_t data[], int len) {
    if (len <= 1) return data[0].dividend == 24 * data[0].divisor;

    data_type_t new_data[len - 1];
    for (int i = 0; i < len; ++i) {
        if (i > 0 && data[i].d == data[i - 1].d) continue;
        for (int j = i + 1; j < len; ++j) {
            if (j > i + 1 && data[j].d == data[j - 1].d) continue;
            for (int k = 0, l = 0; k < len; ++k) {
                if (k == i || k == j) continue;
                new_data[l++] = data[k];
            }
            for (int k = 0; operators[k]; ++k) {
                new_data[len - 2] = operater(data[i], data[j], operators[k]);
                if (!new_data[len - 2].divisor) continue;
                if (dfs(new_data, len - 1)) return true;
            }
        }
    }
    return false;
}
bool judgePoint24(int *nums, int size) {
    data_type_t data[size];

    qsort(nums, size, sizeof(int), cmp);
    for (int i = 0; i < size; ++i) {
        data[i].dividend = nums[i], data[i].divisor = 1;
    }

    return dfs(data, size);
}
