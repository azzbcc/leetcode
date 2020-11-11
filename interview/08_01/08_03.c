// 三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模100
// 0000007。
//
// 示例1:
//
//
// 输入：n = 3
// 输出：4
// 说明: 有四种走法
//
//
// 示例2:
//
//
// 输入：n = 5
// 输出：13
//
//
// 提示:
//
//
// n范围在[1, 1000000]之间
//
// Related Topics 动态规划
// 👍 29 👎 0
#define SIZE 3
#define MOD  1000000007
typedef struct {
    int size;
    long data[SIZE][SIZE];
} data_t;
static data_t global_plus = { 3, { { 0, 0, 1 }, { 1, 0, 1 }, { 0, 1, 1 } } };
data_t data_mul(data_t a, data_t b) {
    data_t ans = { a.size };
    for (int i = 0; i < a.size; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            ans.data[i][j] = a.data[i][0] * b.data[0][j] + a.data[i][1] * b.data[1][j] + a.data[i][2] * b.data[2][j];
            ans.data[i][j] %= MOD;
        }
    }
    return ans;
}
int waysToStep(int n) {
    data_t init = { 1, { 1, 2, 4 } }, plus = global_plus;
    if (n < 4) return init.data[0][n - 1];

    for (n -= 3; n; n /= 2) {
        if (n % 2) init = data_mul(init, plus);
        plus = data_mul(plus, plus);
    }

    return init.data[0][2];
}