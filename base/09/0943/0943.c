// 给定一个字符串数组 A，找到以 A 中每个字符串作为子字符串的最短字符串。
//
// 我们可以假设 A 中没有字符串是 A 中另一个字符串的子字符串。
//
//
//
// 示例 1：
//
// 输入：["alex","loves","leetcode"]
// 输出："alexlovesleetcode"
// 解释："alex"，"loves"，"leetcode" 的所有排列都会被接受。
//
// 示例 2：
//
// 输入：["catg","ctaagt","gcta","ttca","atgcatc"]
// 输出："gctaagttcatgcatc"
//
//
//
// 提示：
//
//
// 1 <= A.length <= 12
// 1 <= A[i].length <= 20
//
//
//
// Related Topics 动态规划
// 👍 49 👎 0
#define MAXN 12U

uint8_t lens[MAXN], same_lens[MAXN][MAXN], lengths[0x1U << MAXN][MAXN];
static int max_same_len(const char *s1, int len1, const char *s2, int len2) {
    for (int len = len1 < len2 ? len1 - 1 : len2 - 1;; len--) {
        bool equal = true;
        for (int i = 0; equal && i < len; ++i) {
            equal = s1[len1 - len + i] == s2[i];
        }
        if (equal) return len;
    }
}
char *shortestSuperstring(char **grid, int size) {
    // data initial
    memset(lengths, 0xff, sizeof(lengths));
    for (size_t i = 0; i < size; ++i) {
        lens[i] = strlen(grid[i]);
    }
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (i == j) continue;
            same_lens[i][j] = max_same_len(grid[i], lens[i], grid[j], lens[j]);
        }
    }

    // 定义S为任意个字符串组成的集合，k为集合中最后一个字符串
    // lengths[S][k] = min(
    //     lengths[S-k][0] + len[k] - same_lens[0][k],
    //     lengths[S-k][1] + len[k] - same_lens[1][k],
    //     lengths[S-k][2] + len[k] - same_lens[2][k],
    //     ...
    //     lengths[S-k][i] + len[k] - same_lens[i][k],
    // )
    for (uint8_t i = 0; i < size; ++i) {
        lengths[0x1U << i][i] = lens[i];
    }
    for (uint16_t S = 0x3; S < 0x1U << size; ++S) {
        for (uint8_t k = 0; k < size; ++k) {
            uint16_t tk = 0x1U << k;
            if (0 == (S & tk)) continue;
            for (uint8_t i = 0; i < size; ++i) {
                if (i == k || (S & 0x1U << i) == 0) continue;
                if (lengths[S][k] > lengths[S ^ tk][i] + lens[k] - same_lens[i][k]) {
                    lengths[S][k] = lengths[S ^ tk][i] + lens[k] - same_lens[i][k];
                }
            }
        }
    }

    // 根据最短字符串长度组装结果
    char *ans = NULL;
    uint8_t last = 0xff, min = 0xff;
    uint16_t check_sum = (0x1U << size) - 1;
    for (uint8_t i = 0; i < size; ++i) {
        if (min > lengths[check_sum][i]) min = lengths[check_sum][i];
    }
    ans = calloc(min + 1, sizeof(char));
    for (uint8_t i = 0, pos; i < size; ++i) {
        for (pos = 0; pos < size; ++pos) {
            uint16_t tj = 0x1U << pos;
            if (0 == (check_sum & tj)) continue;
            uint8_t same_len = 0;
            if (last < size) same_len = same_lens[pos][last];
            if (lengths[check_sum][pos] == min + same_len) break;
        }
        memcpy(ans + lengths[check_sum][pos] - lens[pos], grid[pos], lens[pos]);
        last = pos, min = lengths[check_sum][pos] - lens[pos];
        check_sum ^= 0x1U << pos;
    }

    return ans;
}
