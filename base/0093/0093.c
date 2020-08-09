// 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
//
// 有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。
//
//
//
// 示例:
//
// 输入: "25525511135"
// 输出: ["255.255.11.135", "255.255.111.35"]
// Related Topics 字符串 回溯算法
// 👍 324 👎 0

#define MAXN 0x1000
int help_len     = 0;
char *help[MAXN] = { NULL };
bool check(const char *s, int len) {
    if (len < 0 || len > 3) return false;
    if (len == 1) return true;
    if (*s == '0') return false;

    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum *= 10;
        sum += s[i] - '0';
    }

    return sum <= 0xff;
}
void dfs(const char *s, size_t len, int points[5], int pos) {
    if (pos > 3) {
        if (!check(s + points[pos - 1], len - points[pos - 1])) return;
        points[pos] = len;
        help[help_len] = calloc(len + 4, sizeof(char));
        for (int i = 0; i < 4; ++i) {
            for (int j = points[i]; j < points[i + 1]; ++j) {
                help[help_len][i + j] = s[j];
            }
            help[help_len][i + points[i + 1]] = '.';
        }
        help[help_len][len + 3] = '\0';
        assert(help_len++ < MAXN);
        return;
    }

    for (int i = 1; i <= 3; ++i) {
        // 剩余串长或分隔符不足
        int now = points[pos - 1] + i;
        if (now + (4 - pos) > len || now + 3 * (4 - pos) < len) continue;
        // 当前分隔符不合法，剪枝
        if (!check(s + points[pos - 1], i)) continue;

        points[pos] = points[pos - 1] + i;
        dfs(s, len, points, pos + 1);
    }
}

char **restoreIpAddresses_1(char *s, int *returnSize) {
    int points[5] = { 0 };

    help_len = 0;
    dfs(s, strlen(s), points, 1);

    *returnSize = help_len;
    char **ans  = calloc(help_len, sizeof(char *));
    memcpy(ans, help, help_len * sizeof(char *));

    return ans;
}

void dfs_2(const char *s, size_t len, int addr[4], int pos) {
    if (pos >= 4 && 0 == len) {
        help[help_len] = calloc(16, sizeof(char));
        sprintf(help[help_len], "%d.%d.%d.%d", addr[0], addr[1], addr[2], addr[3]);
        assert(help_len++ < MAXN);
        return;
    }
    if (len < 4 - pos || len > 3 * (4 - pos)) return;
    addr[pos] = s[0] - '0';
    dfs_2(s + 1, len - 1, addr, pos + 1);

    if (!addr[pos]) return;
    if (len > 1) {
        addr[pos] = addr[pos] * 10 + s[1] - '0';
        dfs_2(s + 2, len - 2, addr, pos + 1);
    }
    if (len > 2) {
        addr[pos] = addr[pos] * 10 + s[2] - '0';
        if (addr[pos] > 0xff) return;
        dfs_2(s + 3, len - 3, addr, pos + 1);
    }
}

char **restoreIpAddresses_2(char *s, int *returnSize) {
    int addr[4] = { 0 };

    help_len = 0;
    dfs_2(s, strlen(s), addr, 0);

    *returnSize = help_len;
    char **ans  = calloc(help_len, sizeof(char *));
    memcpy(ans, help, help_len * sizeof(char *));

    return ans;
}

char **(*restoreIpAddresses)(char *, int *) = restoreIpAddresses_2;