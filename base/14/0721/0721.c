// 给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其
// 余元素是 emails 表示该账户的邮箱地址。
//
// 现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于
// 不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。
//
// 合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。账户本身可以以任意顺序返回。
//
//
//
// 示例 1：
//
//
// 输入：
// accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"],
//      ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
// 输出：
// [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
//  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
// 解释：
// 第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。
// 第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
// 可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
//  ['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。
//
//
//
//
// 提示：
//
//
// accounts的长度将在[1，1000]的范围内。
// accounts[i]的长度将在[1，10]的范围内。
// accounts[i][j]的长度将在[1，30]的范围内。
//
// Related Topics 深度优先搜索 并查集
// 👍 150 👎 0

#define DYNAMIC_ARRAY_SIZE 128

typedef struct {
    char **data;
    int size, capacity;
} dynamic_array_t;
dynamic_array_t *dynamic_array_init() {
    dynamic_array_t *da = malloc(sizeof(dynamic_array_t));
    da->size = 0, da->capacity = DYNAMIC_ARRAY_SIZE;
    da->data = malloc(da->capacity * sizeof(char *));
    return da;
}
int dynamic_array_append(dynamic_array_t *da, char *val) {
    if (da->size == da->capacity) da->data = realloc(da->data, (da->capacity += DYNAMIC_ARRAY_SIZE) * sizeof(char *));
    da->data[da->size] = val;
    return da->size++;
}
typedef struct {
    int index;
    char *email;
    UT_hash_handle hh;
} hash_t;
int find(int ancestor[], int n) {
    if (ancestor[n] == n) return n;
    return ancestor[n] = find(ancestor, ancestor[n]);
}
void merge(int ancestor[], int a, int b) {
    ancestor[find(ancestor, b)] = find(ancestor, a);
}
hash_t *hash_find(hash_t *hash, const char *str) {
    hash_t *find = NULL;
    HASH_FIND_STR(hash, str, find);
    return find;
}
int cmp(const void *a, const void *b) {
    return strcmp(*( char ** )a, *( char ** )b);
}
char ***accountsMerge(char ***accounts, int size, int *colSize, int *returnSize, int **returnColumnSizes) {
    char ***ans = malloc(size * sizeof(char **));
    int ancestor[size], len = 0;
    hash_t *hash = NULL, *cur, *next;
    dynamic_array_t *help[size];

    for (int i = 0; i < size; ++i) {
        ancestor[i] = i;
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < colSize[i]; ++j) {
            if ((cur = hash_find(hash, accounts[i][j]))) {
                merge(ancestor, cur->index, i);
            } else {
                cur        = malloc(sizeof(hash_t));
                cur->email = accounts[i][j], cur->index = i;
                HASH_ADD_STR(hash, email, cur);
            }
        }
    }

    memset(help, 0, sizeof(help));
    for (int i = 0; i < size; ++i) {
        if (find(ancestor, i) != i) continue;
        help[i] = dynamic_array_init();
        dynamic_array_append(help[i], accounts[i][0]);
    }
    HASH_ITER(hh, hash, cur, next) {
        dynamic_array_append(help[find(ancestor, cur->index)], cur->email);
        HASH_DEL(hash, cur);
        free(cur);
    }

    *returnColumnSizes = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        if (find(ancestor, i) != i) continue;
        qsort(&help[i]->data[1], help[i]->size - 1, sizeof(char *), cmp);
        ans[len] = help[i]->data, (*returnColumnSizes)[len++] = help[i]->size;
        free(help[i]);
    }
    *returnSize = len;

    return ans;
}
