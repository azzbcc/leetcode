// 给你一个下标从 0 开始的整数数组 arr 和一个 m x n 的整数 矩阵 mat 。
// arr 和 mat 都包含范围 [1，m * n] 内的 所有 整数。
//
// 从下标 0 开始遍历 arr 中的每个下标 i ，并将包含整数 arr[i] 的 mat 单元格涂色。
//
// 请你找出 arr 中第一个使得 mat 的某一行或某一列都被涂色的元素，并返回其下标 i 。
//
//
//
// 示例 1：
//
//
// 输入：arr = [1,3,4,2], mat = [[1,4],[2,3]]
// 输出：2
// 解释：遍历如上图所示，arr[2] 在矩阵中的第一行或第二列上都被涂色。
//
//
// 示例 2：
//
//
// 输入：arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
// 输出：3
// 解释：遍历如上图所示，arr[3] 在矩阵中的第二列上都被涂色。
//
//
//
//
// 提示：
//
//
// m == mat.length
// n = mat[i].length
// arr.length == m * n
// 1 <= m, n <= 10⁵
// 1 <= m * n <= 10⁵
// 1 <= arr[i], mat[r][c] <= m * n
// arr 中的所有整数 互不相同
// mat 中的所有整数 互不相同
//
//
// Related Topics 数组 哈希表 矩阵 👍 70 👎 0

typedef struct {
    int x, y;
} point_t;
int firstCompleteIndex(int *arr, int arrSize, int **mat, int size, int *colSize) {
    point_t location[arrSize];
    int row[size], col[*colSize];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for (int x = 0; x < size; ++x) {
        for (int y = 0; y < *colSize; ++y) {
            location[mat[x][y] - 1] = (point_t) { x, y };
        }
    }
    for (int i = 0; i < arrSize; ++i) {
        point_t *p = &location[arr[i] - 1];
        if (++row[p->x], ++col[p->y], row[p->x] == *colSize || col[p->y] == size) return i;
    }
    return 0;
}
