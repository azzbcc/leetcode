// 给你一个下标从 0 开始的二维数组 variables ，其中 variables[i] = [ai, bi, ci, mi]，以及一个整数 target。
//
// 如果满足以下公式，则下标 i 是 好下标：
//
//
// 0 <= i < variables.length
// ((aibi % 10)ci) % mi == target
//
//
// 返回一个由 好下标 组成的数组，顺序不限 。
//
//
//
// 示例 1：
//
//
// 输入：variables = [[2,3,3,10],[3,3,3,1],[6,1,1,4]], target = 2
// 输出：[0,2]
// 解释：对于 variables 数组中的每个下标 i ：
// 1) 对于下标 0 ，variables[0] = [2,3,3,10] ，(2³ % 10)³ % 10 = 2 。
// 2) 对于下标 1 ，variables[1] = [3,3,3,1] ，(3³ % 10)³ % 1 = 0 。
// 3) 对于下标 2 ，variables[2] = [6,1,1,4] ，(6¹ % 10)¹ % 4 = 2 。
// 因此，返回 [0,2] 作为答案。
//
//
// 示例 2：
//
//
// 输入：variables = [[39,3,1000,1000]], target = 17
// 输出：[]
// 解释：对于 variables 数组中的每个下标 i ：
// 1) 对于下标 0 ，variables[0] = [39,3,1000,1000] ，(39³ % 10)¹⁰⁰⁰ % 1000 = 1 。
// 因此，返回 [] 作为答案。
//
//
//
//
// 提示：
//
//
// 1 <= variables.length <= 100
// variables[i] == [ai, bi, ci, mi]
// 1 <= ai, bi, ci, mi <= 10³
// 0 <= target <= 10³
//
//
// Related Topics 数组 数学 模拟 👍 3 👎 0

int quick_mod(int a, int b, int c) {
    int ans = 1;
    for (a %= c; b; b /= 2) {
        if (b & 1) ans = 1L * ans * a % c;
        a = 1L * a * a % c;
    }
    return ans;
}
int *getGoodIndices(int **vars, int size, int *colSize, int target, int *returnSize) {
    int len = 0, help[size];
    for (int i = 0, t; i < size; ++i) {
        t = quick_mod(vars[i][0], vars[i][1], 10);
        t = quick_mod(t, vars[i][2], vars[i][3]);
        if (target == t) help[len++] = i;
    }

    int *ans = malloc((*returnSize = len) * sizeof(int));
    memcpy(ans, help, len * sizeof(int));
    return ans;
}
