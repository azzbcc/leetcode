// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
//
//
//
// 示例 1：
//
//
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
//
//
// 示例 2：
//
//
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
//
//
//
//
// 提示：
//
//
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100
//
// Related Topics 数组
// 👍 677 👎 0

typedef struct {
    int x, y;
} point_t;
const point_t wards[] = { 0, 1, 1, 0, 0, -1, -1, 0 };
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize) {
    int m = matrixSize, n = *matrixColSize, wide[4] = { 0, n - 1, m - 1, 0 };
    int *ans = malloc((*returnSize = m * n) * sizeof(int));

    point_t now = { 0, 0 };
    for (int i = 0, forward = 0; i < m * n; ++i) {
        ans[i] = matrix[now.x][now.y];
        now.x += wards[forward].x, now.y += wards[forward].y;
        if (now.x < wide[0] || now.x > wide[2] || now.y < wide[3] || now.y > wide[1]) {
            now.x -= wards[forward].x, now.y -= wards[forward].y;
            wide[forward] += forward % 3 == 0 ? 1 : -1, forward = (forward + 1) % 4;
            now.x += wards[forward].x, now.y += wards[forward].y;
        }
    }

    return ans;
}