// 基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
//
// 假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。
//
//
// 例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
//
//
// 另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。
//
// 给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end
// 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。
//
// 注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
//
//
//
// 示例 1：
//
//
// 输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
// 输出：1
//
//
// 示例 2：
//
//
// 输入：start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// 输出：2
//
//
// 示例 3：
//
//
// 输入：start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
// 输出：3
//
//
//
//
// 提示：
//
//
// start.length == 8
// end.length == 8
// 0 <= bank.length <= 10
// bank[i].length == 8
// start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成
//
// Related Topics 广度优先搜索 哈希表 字符串 👍 175 👎 0

#define MAX 9
typedef struct {
    int index;
    char str[MAX];
    UT_hash_handle hh;
} * hash_t;
typedef struct {
    int step;
    char now[MAX];
} node_t;
int bfs(hash_t hash, char *start, char *end, int size) {
    hash_t find;
    node_t q[size + 1];
    bool used[size + 1];
    int front = 0, rear = 1;
    static char *gene = "ACGT";

    memset(q, 0, sizeof(q));
    strcpy(q->now, start);
    memset(used, false, sizeof(used));
    for (; front < rear; ++front) {
        node_t cur = q[front];
        if (!strcmp(cur.now, end)) return cur.step;
        for (int i = 0, tmp; gene[i]; ++i) {
            for (int j = 0; start[j]; ++j) {
                if (gene[i] == cur.now[j]) continue;
                tmp = cur.now[j], cur.now[j] = gene[i];
                HASH_FIND_STR(hash, cur.now, find);
                if (find && !used[find->index]) {
                    used[find->index] = true;
                    strcpy(q[rear].now, find->str);
                    q[rear++].step = cur.step + 1;
                }
                cur.now[j] = tmp;
            }
        }
    }
    return -1;
}
int minMutation(char *start, char *end, char **bank, int size) {
    hash_t hash = NULL, cur, next;
    for (int i = 0; i < size; ++i) {
        cur = malloc(sizeof(*cur)), cur->index = i;
        strcpy(cur->str, bank[i]);
        HASH_ADD_STR(hash, str, cur);
    }
    int ans = bfs(hash, start, end, size);
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
