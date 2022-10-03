// 编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
//
//
//
// 示例 1：
//
// 输入：
// [
//  [1,1,1],
//  [1,0,1],
//  [1,1,1]
// ]
// 输出：
// [
//  [1,0,1],
//  [0,0,0],
//  [1,0,1]
// ]
//
//
// 示例 2：
//
// 输入：
// [
//  [0,1,2,0],
//  [3,4,5,2],
//  [1,3,1,5]
// ]
// 输出：
// [
//  [0,0,0,0],
//  [0,4,5,0],
//  [0,3,1,0]
// ]
//
//
// Related Topics 数组 哈希表 矩阵 👍 117 👎 0

void setZeroes(int **matrix, int size, int *colSize) {
    bool row[*colSize], col[size];
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < *colSize; ++j) {
            row[j] = row[j] || matrix[i][j] == 0;
            col[i] = col[i] || matrix[i][j] == 0;
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < *colSize; ++j) {
            if (row[j] || col[i]) matrix[i][j] = 0;
        }
    }
}