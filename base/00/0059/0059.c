// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
//
//
//
// 示例 1：
//
//
// 输入：n = 3
// 输出：[[1,2,3],[8,9,4],[7,6,5]]
//
//
// 示例 2：
//
//
// 输入：n = 1
// 输出：[[1]]
//
//
//
//
// 提示：
//
//
// 1 <= n <= 20
//
// Related Topics 数组
// 👍 348 👎 0

typedef struct {
    int x, y;
} point_t;
const point_t wards[] = { 0, 1, 1, 0, 0, -1, -1, 0 };
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes) {
    int **ans   = malloc((*returnSize = n) * sizeof(int *));
    int wide[4] = { 0, n - 1, n - 1, 0 };
    point_t now = { 0, 0 };

    *returnColumnSizes = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        ans[i] = malloc(((*returnColumnSizes)[i] = n) * sizeof(int));
    }
    for (int i = 1, forward = 0; i <= n * n; ++i) {
        ans[now.x][now.y] = i;
        now.x += wards[forward].x, now.y += wards[forward].y;
        if (now.x < wide[0] || now.x > wide[2] || now.y < wide[3] || now.y > wide[1]) {
            now.x -= wards[forward].x, now.y -= wards[forward].y;
            wide[forward] += forward % 3 == 0 ? 1 : -1, forward = (forward + 1) % 4;
            now.x += wards[forward].x, now.y += wards[forward].y;
        }
    }
    return ans;
}
