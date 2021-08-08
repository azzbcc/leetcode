// 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
//
//
// 每行中的整数从左到右按升序排列。
// 每行的第一个整数大于前一行的最后一个整数。
//
//
//
//
// 示例 1：
//
//
// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// 输出：true
//
//
// 示例 2：
//
//
// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// 输出：false
//
//
//
//
// 提示：
//
//
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104
//
// Related Topics 数组 二分查找
// 👍 375 👎 0

bool searchMatrix(int **matrix, int size, int *colSize, int target) {
    int m = size, n = *colSize;
    for (int mid, l = 0, r = m * n - 1; l <= r;) {
        mid = (l + r) / 2;
        if (matrix[mid / n][mid % n] == target) return true;
        if (matrix[mid / n][mid % n] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return false;
}
