// 给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。
//
// 每一步，你可以从下标 i 跳到下标：
//
//
// i + 1 满足：i + 1 < arr.length
// i - 1 满足：i - 1 >= 0
// j 满足：arr[i] == arr[j] 且 i != j
//
//
// 请你返回到达数组最后一个元素的下标处所需的 最少操作次数 。
//
// 注意：任何时候你都不能跳到数组外面。
//
//
//
// 示例 1：
//
// 输入：arr = [100,-23,-23,404,100,23,23,23,3,404]
// 输出：3
// 解释：那你需要跳跃 3 次，下标依次为 0 --> 4 --> 3 --> 9 。下标 9 为数组的最后一个元素的下标。
//
//
// 示例 2：
//
// 输入：arr = [7]
// 输出：0
// 解释：一开始就在最后一个元素处，所以你不需要跳跃。
//
//
// 示例 3：
//
// 输入：arr = [7,6,9,6,9,6,9,7]
// 输出：1
// 解释：你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
//
//
// 示例 4：
//
// 输入：arr = [6,1,9]
// 输出：2
//
//
// 示例 5：
//
// 输入：arr = [11,22,7,7,7,7,7,7,7,22,13]
// 输出：3
//
//
//
//
// 提示：
//
//
// 1 <= arr.length <= 5 * 10^4
// -10^8 <= arr[i] <= 10^8
//
// Related Topics 广度优先搜索 数组 哈希表 👍 132 👎 0

typedef struct {
    int key, pos;
    UT_hash_handle hh;
} * hash_t;
int minJumps(int *arr, int size) {
    int prev[size], dp[size], queue[size];
    hash_t hash = NULL, cur, next;

    memset(prev, -1, sizeof(prev));
    memset(dp, 0x3f, sizeof(dp));
    queue[0] = 0, dp[0] = 0;

    for (int i = 0; i < size; prev[i] = cur->pos, cur->pos = i++) {
        HASH_FIND_INT(hash, &arr[i], cur);
        if (cur) continue;
        cur = malloc(sizeof(*cur)), cur->key = arr[i], cur->pos = -1;
        HASH_ADD_INT(hash, key, cur);
    }
    for (int front = 0, rear = 1, now; front < rear; ++front) {
        if ((now = queue[front]) + 1 == size) break;

        if (dp[now] + 1 < dp[now + 1]) queue[rear++] = now + 1, dp[now + 1] = dp[now] + 1;
        if (now > 0 && dp[now] + 1 < dp[now - 1]) queue[rear++] = now - 1, dp[now - 1] = dp[now] + 1;
        HASH_FIND_INT(hash, &arr[now], cur);
        for (int i = cur->pos; i != -1; i = prev[i]) {
            if (dp[now] + 1 < dp[i]) queue[rear++] = i, dp[i] = dp[now] + 1;
        }
        cur->pos = -1;
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }

    return dp[size - 1];
}