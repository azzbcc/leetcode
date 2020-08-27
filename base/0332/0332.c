// 给定一个机票的字符串二维数组 [from,
// to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。 所有这些机票都属于一个从
// JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。
//
// 说明:
//
//
// 如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"]
// 相比就更小，排序更靠前所有的机场都用三个大写字母表示（机场代码）。假定所有机票至少存在一种合理的行程。
//
//
// 示例 1:
//
// 输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// 输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]
//
//
// 示例 2:
//
// 输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// 输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// 解释: 另一种有效的行程是["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。
//
// Related Topics 深度优先搜索 图
// 👍 200 👎 0

#define STR2INT(s) ((s[0] - 'A') * 26 * 26 + (s[1] - 'A') * 26 + (s[2] - 'A'))
#define INT2STR(n)                                                                                                     \
    ({                                                                                                                 \
        char str[4] = { 'A' + n / 26 / 26, 'A' + n / 26 % 26, 'A' + n % 26 };                                          \
        strdup(str);                                                                                                   \
    })

int cmp(const void *a, const void *b) {
    int(*pa)[2] = a, (*pb)[2] = b;

    if ((*pa)[0] == (*pb)[0]) return (*pa)[1] - (*pb)[1];
    return (*pa)[0] - (*pb)[0];
}
bool dfs(int map[][2], int size, int now, int *ans, int len, bool visited[]) {
    ans[len] = now;
    if (len >= size) return true;

    int beg = 0, end = size;
    while (beg < end) {
        int mid = (beg + end) / 2;

        if (map[mid][0] >= now) end = mid;
        if (map[mid][0] < now) beg = mid + 1;
    }
    for (int i = beg; i < size && map[i][0] == now; ++i) {
        if (visited[i]) continue;

        visited[i] = true;
        if (dfs(map, size, map[i][1], ans, len + 1, visited)) return true;
        visited[i] = false;
    }
    return false;
}
char **findItinerary(char ***tickets, int ticketsSize, int *ticketsColSize, int *returnSize) {
    char **ans = NULL;
    bool visited[ticketsSize];
    int map[ticketsSize][2], result[ticketsSize + 1];

    for (int i = 0; i < ticketsSize; ++i) {
        visited[i] = false;
        map[i][0]  = STR2INT(tickets[i][0]);
        map[i][1]  = STR2INT(tickets[i][1]);
    }
    qsort(map, ticketsSize, sizeof(map[0]), cmp);

    *returnSize = 0;
    if (!dfs(map, ticketsSize, STR2INT("JFK"), result, 0, visited)) return NULL;

    *returnSize = ticketsSize + 1, ans = calloc(ticketsSize + 1, sizeof(char *));
    for (int i = 0; i <= ticketsSize; ++i) {
        ans[i] = INT2STR(result[i]);
    }
    return ans;
}
