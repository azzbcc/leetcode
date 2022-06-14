// 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
//
//
//
// 示例 1：
//
//
// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,4,7,5,3,6,8,9]
//
//
// 示例 2：
//
//
// 输入：mat = [[1,2],[3,4]]
// 输出：[1,2,3,4]
//
//
//
//
// 提示：
//
//
// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 10⁴
// 1 <= m * n <= 10⁴
// -10⁵ <= mat[i][j] <= 10⁵
//
// Related Topics 数组 矩阵 模拟 👍 328 👎 0

typedef union {
    struct {
        int x, y;
    };
    int data[2];
} point_t;
const point_t wards[] = { -1, 1, 1, -1 };
int *findDiagonalOrder(int **mat, int size, int *colSize, int *returnSize) {
    point_t now = { 0 };
    int m = size, n = *colSize, *ans = malloc((*returnSize = m * n) * sizeof(int));

    for (int i = 0, ward = 0; i < m * n; ++i) {
        ans[i] = mat[now.x][now.y];

        now = (point_t) { now.x + wards[ward].x, now.y + wards[ward].y };
        if (now.x < 0 || now.x >= m || now.y < 0 || now.y >= n) {
            now.data[ward] += 1, ward = 1 - ward;
        }
        if (now.x < 0 || now.x >= m || now.y < 0 || now.y >= n) {
            now = (point_t) { now.x + wards[ward].x, now.y + wards[ward].y };
        }
    }
    return ans;
}
