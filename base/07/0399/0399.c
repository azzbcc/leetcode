//给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values
//[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
//
// 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj =
// ? 的结果作为答案。
//
// 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。
//
//
//
// 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
//
//
//
// 示例 1：
//
//
//输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"]
//,["b","a"],["a","e"],["a","a"],["x","x"]]
//输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
//解释：
//条件：a / b = 2.0, b / c = 3.0
//问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
//结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
//
//
// 示例 2：
//
//
//输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], quer
// ies = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
//输出：[3.75000,0.40000,5.00000,0.20000]
//
//
// 示例 3：
//
//
//输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a
//","c"],["x","y"]]
//输出：[0.50000,2.00000,-1.00000,-1.00000]
//
//
//
//
// 提示：
//
//
// 1 <= equations.length <= 20
// equations[i].length == 2
// 1 <= Ai.length, Bi.length <= 5
// values.length == equations.length
// 0.0 < values[i] <= 20.0
// 1 <= queries.length <= 20
// queries[i].length == 2
// 1 <= Cj.length, Dj.length <= 5
// Ai, Bi, Cj, Dj 由小写英文字母与数字组成
//
// Related Topics 并查集 图
// 👍 353 👎 0

typedef struct {
    char *str;
    int index;
    UT_hash_handle hh;
} node_t;

node_t *hash = NULL;
void hash_init(char ***strings, int size) {
    int index   = 0;
    node_t *tmp = NULL;

    hash = NULL;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 2; ++j) {
            HASH_FIND_STR(hash, strings[i][j], tmp);
            if (tmp) continue;
            tmp      = malloc(sizeof(node_t));
            tmp->str = strings[i][j], tmp->index = index++;
            HASH_ADD_STR(hash, str, tmp);
        }
    }
}
int hash_index(char *string) {
    node_t *tmp = NULL;
    HASH_FIND_STR(hash, string, tmp);
    if (tmp) return tmp->index;
    return -1;
}
void hash_uninit() {
    node_t *tmp = NULL, *cur = NULL;
    HASH_ITER(hh, hash, cur, tmp) {
        HASH_DEL(hash, cur);
        free(cur);
    }
}

typedef struct {
    int ancestor;
    double value;
} ancestor_t;
ancestor_t *find(ancestor_t *ancestor, int n) {
    if (n < 0) return NULL;
    if (ancestor[n].ancestor == n) return &ancestor[n];

    int parent = ancestor[n].ancestor;

    find(ancestor, parent);

    ancestor[n].ancestor = ancestor[parent].ancestor;
    ancestor[n].value *= ancestor[parent].value;

    return &ancestor[n];
}
void merge(ancestor_t ancestor[], int from, int to, double value) {
    if (from > to) return merge(ancestor, to, from, 1. / value);
    find(ancestor, from), find(ancestor, to);

    int a = ancestor[from].ancestor, b = ancestor[to].ancestor;

    if (a < b) {
        ancestor[b].ancestor = a, ancestor[b].value = ancestor[from].value * value / ancestor[to].value;
    } else if (a > b) {
        ancestor[a].ancestor = b, ancestor[a].value = ancestor[to].value / value / ancestor[from].value;
    }
}
double *calcEquation(char ***equations, int equationsSize, int *equationsColSize, double *values, int valuesSize,
                     char ***queries, int queriesSize, int *queriesColSize, int *returnSize) {
    hash_init(equations, equationsSize);

    ancestor_t ancestor[HASH_COUNT(hash)];
    for (int i = 0; i < HASH_COUNT(hash); ++i) {
        ancestor[i] = (ancestor_t) { i, 1. };
    }
    for (int i = 0; i < equationsSize; ++i) {
        merge(ancestor, hash_index(equations[i][0]), hash_index(equations[i][1]), values[i]);
    }

    double *ans = malloc((*returnSize = queriesSize) * sizeof(double));
    for (int i = 0; i < queriesSize; ++i) {
        ancestor_t *from = find(ancestor, hash_index(queries[i][0]));
        ancestor_t *to   = find(ancestor, hash_index(queries[i][1]));
        if (!from || !to || from->ancestor != to->ancestor) {
            ans[i] = -1;
        } else {
            ans[i] = to->value / from->value;
        }
    }

    hash_uninit();
    return ans;
}
