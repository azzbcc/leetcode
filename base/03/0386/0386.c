// 给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。
//
// 你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。
//
//
//
// 示例 1：
//
//
// 输入：n = 13
// 输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
//
//
// 示例 2：
//
//
// 输入：n = 2
// 输出：[1,2]
//
//
//
//
// 提示：
//
//
// 1 <= n <= 5 * 10⁴
//
// Related Topics 深度优先搜索 字典树 👍 303 👎 0

void dfs(int n, int cur, int **ans) {
    if (cur > n) return;
    if (cur) *(*ans)++ = cur;
    for (int i = !cur; i < 10; dfs(n, cur * 10 + i++, ans)) {}
}
int *lexicalOrder(int n, int *returnSize) {
    int *ans = malloc((*returnSize = n) * sizeof(int)), *p = ans;
    dfs(n, 0, &p);
    return ans;
}
