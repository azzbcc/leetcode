// 给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。
//
//
// 上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。
//
// 示例:
//
// 给定 matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]
//
// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12
//
//
// 说明:
//
//
// 你可以假设矩阵不可变。
// 会多次调用 sumRegion 方法。
// 你可以假设 row1 ≤ row2 且 col1 ≤ col2。
//
// Related Topics 动态规划
// 👍 150 👎 0

#define md matrix->data

typedef struct {
    int size;
    int *data[];
} NumMatrix;

NumMatrix *numMatrixCreate(int **grid, int size, int *colSize) {
    int col = size ? *colSize : 0;
    NumMatrix *matrix = malloc(sizeof(NumMatrix) + (size + 1) * sizeof(int *));

    matrix->size = size, md[0] = calloc(col + 1, sizeof(int));
    for (int i = 0; i < size; ++i) {
        md[i + 1] = malloc((col + 1) * sizeof(int)), md[i + 1][0] = 0;
        for (int j = 0; j < col; ++j) {
            md[i + 1][j + 1] = grid[i][j] + md[i][j + 1] + md[i + 1][j] - md[i][j];
        }
    }

    return matrix;
}

int numMatrixSumRegion(NumMatrix *matrix, int row1, int col1, int row2, int col2) {
    return md[row2 + 1][col2 + 1] - md[row1][col2 + 1] - md[row2 + 1][col1] + md[row1][col1];
}

void numMatrixFree(NumMatrix *matrix) {
    for (int i = 0; i <= matrix->size; free(md[i++])) {}
    free(matrix);
}