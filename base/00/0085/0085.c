// 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
//
//
//
// 示例 1：
//
//
// 输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]
// ,["1","0","0","1","0"]]
// 输出：6
// 解释：最大矩形如上图所示。
//
//
// 示例 2：
//
//
// 输入：matrix = []
// 输出：0
//
//
// 示例 3：
//
//
// 输入：matrix = [["0"]]
// 输出：0
//
//
// 示例 4：
//
//
// 输入：matrix = [["1"]]
// 输出：1
//
//
// 示例 5：
//
//
// 输入：matrix = [["0","0"]]
// 输出：0
//
//
//
//
// 提示：
//
//
// rows == matrix.length
// cols == matrix[0].length
// 0 <= row, cols <= 200
// matrix[i][j] 为 '0' 或 '1'
//
// Related Topics 栈 数组 哈希表 动态规划
// 👍 718 👎 0

#if 0
typedef struct {
    int row, col, ans;
} node_t;

int maximalRectangle(char **matrix, int size, int *colSize) {
    if (!size || !*colSize) return 0;

    int ans = 0;
    node_t dp[size][*colSize];

    for (int i = 0; i < *colSize; ++i) {
        if (matrix[0][i] == '1') {
            dp[0][i] = (node_t) { 1, 1, 1 };
            if (i) dp[0][i].row += dp[0][i - 1].row, dp[0][i].ans += dp[0][i - 1].ans;
            if (ans < dp[0][i].ans) ans = dp[0][i].ans;
        } else {
            dp[0][i] = (node_t) { 0, 0, 0 };
        }
    }
    for (int i = 1; i < size; ++i) {
        if (matrix[i][0] == '1') {
            dp[i][0] = (node_t) { 1, dp[i - 1][0].col + 1, dp[i - 1][0].ans + 1 };
            if (ans < dp[i][0].ans) ans = dp[i][0].ans;
        } else {
            dp[i][0] = (node_t) { 0, 0, 0 };
        }
        for (int j = 1; j < *colSize; ++j) {
            if (matrix[i][j] == '1') {
                dp[i][j] = (node_t) { dp[i][j - 1].row + 1, dp[i - 1][j].col + 1, 0 };
                for (int row = 1, max; row <= dp[i][j].row; ++row) {
                    for (max = 0; max < dp[i][j].col; ++max) {
                        if (dp[i - max][j].row < row) break;
                    }
                    if (dp[i][j].ans < row * max) dp[i][j].ans = row * max;
                }
                if (ans < dp[i][j].ans) ans = dp[i][j].ans;
            } else {
                dp[i][j] = (node_t) { 0, 0, 0 };
            }
        }
    }

    return ans;
}
#elif 0
int maximalRectangle(char **matrix, int size, int *colSize) {
    if (!size || !*colSize) return 0;

    int heights[*colSize], ans = 0;

    memset(heights, 0, sizeof(heights));
    for (int i = 0; i < size; ++i) {
        int stack[*colSize], top = 0;
        for (int j = 0; j < *colSize; ++j) {
            if (matrix[i][j] == '0') {
                top = 0, heights[j] = 0;
                continue;
            }
            stack[top++] = heights[j] += 1;
            for (int k = 0; k < top; ++k) {
                if (stack[k] > heights[j]) stack[k] = heights[j];
                if (ans < (top - k) * stack[k]) ans = (top - k) * stack[k];
            }
        }
    }

    return ans;
}
#else
typedef struct {
    int height, position;
} node_t;
int maximalRectangle(char **matrix, int size, int *colSize) {
    if (!size || !*colSize) return 0;

    node_t stack[*colSize + 1];
    int top = 0, ans = 0, heights[*colSize];

    memset(heights, 0, sizeof(heights));
    stack[0] = (node_t) { 0, -1 };
    for (int i = 0; i < size; ++i) {
        for (int j = 0, h; j < *colSize; ++j) {
            if (matrix[i][j] == '0') {
                heights[j] = 0;
            } else {
                heights[j] += 1;
            }
            for (h = heights[j]; top && h <= stack[top].height; --top) {
                if (ans < stack[top].height * (j - stack[top - 1].position - 1)) {
                    ans = stack[top].height * (j - stack[top - 1].position - 1);
                }
            }
            stack[++top] = (node_t) { h, j };
        }
        for (; top; --top) {
            if (ans < stack[top].height * (*colSize - stack[top - 1].position - 1)) {
                ans = stack[top].height * (*colSize - stack[top - 1].position - 1);
            }
        }
    }

    return ans;
}
#endif