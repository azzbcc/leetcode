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

typedef struct node {
    int val;
    struct node *next;
} * node_t;
void dfs(node_t map[], int now, char **ans, int *pos) {
    for (node_t cur = map[now]; cur; cur = map[now]) {
        map[now] = cur->next;
        dfs(map, cur->val, ans, pos);
    }
    ans[--*pos] = INT2STR(now);
}
void list_insert(node_t *head, node_t n) {
    if (!*head || (*head)->val > n->val) {
        n->next = (*head), *head = n;
        return;
    }
    node_t prev = *head;
    while (prev->next && prev->next->val < n->val) {
        prev = prev->next;
    }
    n->next = prev->next, prev->next = n;
}
char **findItinerary(char ***tickets, int ticketsSize, int *ticketsColSize, int *returnSize) {
    char **ans = NULL;
    struct node nodes[ticketsSize], *map[26 * 26 * 26] = { NULL };
    for (int i = 0; i < ticketsSize; ++i) {
        nodes[i].val  = STR2INT(tickets[i][1]);
        nodes[i].next = NULL;

        list_insert(&map[STR2INT(tickets[i][0])], &nodes[i]);
    }

    *returnSize = ++ticketsSize, ans = calloc(ticketsSize, sizeof(char *));
    dfs(map, STR2INT("JFK"), ans, &ticketsSize);

    return ans;
}
