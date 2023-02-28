// 给你两个二维整数数组 items1 和 items2 ，表示两个物品集合。每个数组 items 有以下特质：
//
//
// items[i] = [valuei, weighti] 其中 valuei 表示第 i 件物品的 价值 ，weighti 表示第 i 件物品的 重量 。
//
// items 中每件物品的价值都是 唯一的 。
//
//
// 请你返回一个二维数组 ret，其中 ret[i] = [valuei, weighti]， weighti 是所有价值为 valuei 物品的 重量之和
// 。
//
// 注意：ret 应该按价值 升序 排序后返回。
//
//
//
// 示例 1：
//
//
// 输入：items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
// 输出：[[1,6],[3,9],[4,5]]
// 解释：
// value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 5 ，总重量为 1 + 5 = 6 。
// value = 3 的物品再 items1 中 weight = 8 ，在 items2 中 weight = 1 ，总重量为 8 + 1 = 9 。
// value = 4 的物品在 items1 中 weight = 5 ，总重量为 5 。
// 所以，我们返回 [[1,6],[3,9],[4,5]] 。
//
//
// 示例 2：
//
//
// 输入：items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]]
// 输出：[[1,4],[2,4],[3,4]]
// 解释：
// value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 3 ，总重量为 1 + 3 = 4 。
// value = 2 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 1 ，总重量为 3 + 1 = 4 。
// value = 3 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
// 所以，我们返回 [[1,4],[2,4],[3,4]] 。
//
// 示例 3：
//
//
// 输入：items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]]
// 输出：[[1,7],[2,4],[7,1]]
// 解释：
// value = 1 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 4 ，总重量为 3 + 4 = 7 。
// value = 2 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
// value = 7 的物品在 items2 中 weight = 1 ，总重量为 1 。
// 所以，我们返回 [[1,7],[2,4],[7,1]] 。
//
//
//
//
// 提示：
//
//
// 1 <= items1.length, items2.length <= 1000
// items1[i].length == items2[i].length == 2
// 1 <= valuei, weighti <= 1000
// items1 中每个 valuei 都是 唯一的 。
// items2 中每个 valuei 都是 唯一的 。
//
//
// Related Topics 数组 哈希表 有序集合 排序 👍 53 👎 0

#define MAXN 1001
int **mergeSimilarItems(int **items1, int items1Size, int *items1ColSize, int **items2, int items2Size,
                        int *items2ColSize, int *returnSize, int **returnColumnSizes) {
    int cs[MAXN] = { 0 }, len = 0, **ans;
    for (int i = 0; i < items1Size; len += 1, cs[items1[i][0]] += items1[i][1], ++i) {}
    for (int i = 0; i < items2Size; len += !cs[items2[i][0]], cs[items2[i][0]] += items2[i][1], ++i) {}
    ans = malloc((*returnSize = len) * sizeof(int *)), *returnColumnSizes = malloc(len * sizeof(int));
    for (int i = 0, pos = 0; i < MAXN; ++i) {
        if (!cs[i]) continue;
        ans[pos]    = malloc((returnColumnSizes[0][pos] = 2) * sizeof(int));
        ans[pos][0] = i, ans[pos++][1] = cs[i];
    }
    return ans;
}
