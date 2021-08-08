// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
//
//
//
// 在杨辉三角中，每个数是它左上方和右上方的数的和。
//
// 示例:
//
// 输入: 5
// 输出:
// [
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
// ]
// Related Topics 数组
// 👍 402 👎 0

int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
    int **ans = malloc((*returnSize = numRows) * sizeof(int *));

    *returnColumnSizes = malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; ++i) {
        ans[i]    = malloc(((*returnColumnSizes)[i] = i + 1) * sizeof(int));
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }

    return ans;
}