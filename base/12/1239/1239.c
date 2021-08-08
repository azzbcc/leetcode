// 给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s
// 中的每一个字符都只出现过一次，那么它就是一个可行解。
//
// 请返回所有可行解 s 中最长长度。
//
//
//
// 示例 1：
//
// 输入：arr = ["un","iq","ue"]
// 输出：4
// 解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
//
//
// 示例 2：
//
// 输入：arr = ["cha","r","act","ers"]
// 输出：6
// 解释：可能的解答有 "chaers" 和 "acters"。
//
//
// 示例 3：
//
// 输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
// 输出：26
//
//
//
//
// 提示：
//
//
// 1 <= arr.length <= 16
// 1 <= arr[i].length <= 26
// arr[i] 中只含有小写英文字母
//
// Related Topics 位运算 回溯算法
// 👍 94 👎 0

typedef struct {
    int mask;
    int len;
} node_t;
bool resolve(char *str, node_t *node) {
    memset(node, 0, sizeof(node_t));
    for (int ch; str[node->len]; ++node->len) {
        ch = str[node->len] - 'a';
        if (node->mask & 1 << ch) return false;
        node->mask |= 1 << ch;
    }
    return true;
}
void dfs(node_t data[], int size, int cur, node_t *node, int *ans) {
    if (cur >= size) return;

    // not choose
    dfs(data, size, cur + 1, node, ans);

    // can choose ?
    if (data[cur].mask & node->mask) return;
    if (*ans < node->len + data[cur].len) *ans = node->len + data[cur].len;

    // choose
    node->mask |= data[cur].mask, node->len += data[cur].len;
    dfs(data, size, cur + 1, node, ans);
    node->mask ^= data[cur].mask, node->len -= data[cur].len;
}
int maxLength(char **arr, int size) {
    node_t data[size], zero = { 0 };
    int len = 0, ans = 0;
    for (int i = 0; i < size; ++i) {
        len += resolve(arr[i], &data[len]);
    }
    dfs(data, len, 0, &zero, &ans);
    return ans;
}
