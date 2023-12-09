// 如果整数 x 满足：对于每个数位 d ，这个数位 恰好 在 x 中出现 d 次。那么整数 x 就是一个 数值平衡数 。
//
// 给你一个整数 n ，请你返回 严格大于 n 的 最小数值平衡数 。
//
//
//
// 示例 1：
//
//
// 输入：n = 1
// 输出：22
// 解释：
// 22 是一个数值平衡数，因为：
// - 数字 2 出现 2 次
// 这也是严格大于 1 的最小数值平衡数。
//
//
// 示例 2：
//
//
// 输入：n = 1000
// 输出：1333
// 解释：
// 1333 是一个数值平衡数，因为：
// - 数字 1 出现 1 次。
// - 数字 3 出现 3 次。
// 这也是严格大于 1000 的最小数值平衡数。
// 注意，1022 不能作为本输入的答案，因为数字 0 的出现次数超过了 0 。
//
// 示例 3：
//
//
// 输入：n = 3000
// 输出：3133
// 解释：
// 3133 是一个数值平衡数，因为：
// - 数字 1 出现 1 次。
// - 数字 3 出现 3 次。
// 这也是严格大于 3000 的最小数值平衡数。
//
//
//
//
// 提示：
//
//
// 0 <= n <= 10⁶
//
//
// Related Topics 数学 回溯 枚举 👍 62 👎 0

#define MAX 7
struct {
    int len;
    int data[120];
} help[1] = { 1, { 1224444 } };
int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
void digit_dfs(int map[], int len, int res, int cur) {
    if (cur >= len) {
        help->data[help->len++] = res;
        return;
    }
    for (int i = 0; i < MAX; ++i) {
        if (!map[i]) continue;
        res *= 10, res += i, map[i]--;
        digit_dfs(map, len, res, cur + 1);
        res /= 10, map[i]++;
    }
}
void arr_dump(int arr[], int size) {
    int map[MAX] = { 0 }, len = 0, res = 0;
    for (int i = 0; i < size; ++i) {
        len += arr[i];
        map[arr[i]] = arr[i];
    }
    digit_dfs(map, len, res, 0);
}
void dfs(int cur, int sum, int res[], int len) {
    if (sum) arr_dump(res, len);
    for (int i = cur + 1; sum + i < MAX; ++i) {
        res[len] = i;
        dfs(i, sum + i, res, len + 1);
    }
}
int nextBeautifulNumber(int n) {
    static bool init = true;
    if (init) {
        int arr[MAX];
        init = false;
        dfs(0, 0, arr, 0);
        qsort(&help->data, help->len, sizeof(int), cmp);
    }

    int l = 0;
    for (int mid, r = help->len - 1; l <= r;) {
        if (help->data[mid = (l + r) / 2] <= n) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return help->data[l];
}
