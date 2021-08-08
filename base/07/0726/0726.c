// 给定一个化学式formula（作为字符串），返回每种原子的数量。
//
// 原子总是以一个大写字母开始，接着跟随0个或任意个小写字母，表示原子的名字。
//
// 如果数量大于 1，原子后会跟着数字表示原子的数量。如果数量等于 1 则不会跟数字。例如，H2O 和 H2O2 是可行的，但 H1O2
// 这个表达是不可行的。
//
//
// 两个化学式连在一起是新的化学式。例如 H2O2He3Mg4 也是化学式。
//
// 一个括号中的化学式和数字（可选择性添加）也是化学式。例如 (H2O2) 和 (H2O2)3 是化学式。
//
// 给定一个化学式，输出所有原子的数量。格式为：第一个（按字典序）原子的名子，跟着它的数量（如果数量大于
// 1），然后是第二个原子的名字（按字典序），跟着它的数
// 量（如果数量大于 1），以此类推。
//
// 示例 1:
//
//
// 输入:
// formula = "H2O"
// 输出: "H2O"
// 解释:
// 原子的数量是 {'H': 2, 'O': 1}。
//
//
// 示例 2:
//
//
// 输入:
// formula = "Mg(OH)2"
// 输出: "H2MgO2"
// 解释:
// 原子的数量是 {'H': 2, 'Mg': 1, 'O': 2}。
//
//
// 示例 3:
//
//
// 输入:
// formula = "K4(ON(SO3)2)2"
// 输出: "K4N2O14S4"
// 解释:
// 原子的数量是 {'K': 4, 'N': 2, 'O': 14, 'S': 4}。
//
//
// 注意:
//
//
// 所有原子的第一个字母为大写，剩余字母都是小写。
// formula的长度在[1, 1000]之间。
// formula只包含字母、数字和圆括号，并且题目中给定的是合法的化学式。
//
// Related Topics 栈 递归 哈希表
// 👍 85 👎 0
#define MAXN  1000
#define WIDTH 26

typedef struct trie_node {
    int count;
    struct trie_node *next[WIDTH];
} * trie_t;
typedef struct {
    char *s;
    int count;
} string_t;

trie_t trie_create() {
    trie_t t = calloc(1, sizeof(struct trie_node));

    t->count = 0;
    for (int i = 0; i < WIDTH; ++i) {
        t->next[i] = NULL;
    }
    return t;
}
void trie_add(trie_t t, string_t *ss) {
    for (char *s = ss->s; *s; s++) {
        if (!t->next[*s - 'a']) t->next[*s - 'a'] = trie_create();
        t = t->next[*s - 'a'];
    }
    t->count += ss->count;
}
void trie_dump(trie_t t, char *res, int len, char **ps) {
    if (t->count) {
        res[len] = '\0';
        *ps += sprintf(*ps, t->count > 1 ? "%s%d" : "%s", res, t->count);
    }
    for (int i = 0; i < WIDTH; ++i) {
        if (t->next[i]) {
            res[len] = i + (len ? 'a' : 'A');
            trie_dump(t->next[i], res, len + 1, ps);
        }
    }
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; ++i) {
        trie_free(t->next[i]);
    }
    free(t);
}
char *resolve(char *s, char **ps, string_t ss[], int *len) {
    while (*s && *s != ')') {
        if (*s == '(') {
            int pos = *len, count = 0;
            s = resolve(s + 1, ps, ss, len) + 1;
            while (*s && isdigit(*s)) {
                count *= 10, count += *s - '0';
                s++;
            }
            while (count && pos < *len) {
                ss[pos++].count *= count;
            }
            continue;
        }

        ss[*len].s = *ps, *(*ps)++ = *s++ - 'A' + 'a';
        while (*s && islower(*s)) {
            *(*ps)++ = *s++;
        }
        *(*ps)++ = '\0';

        int count = 0;
        while (*s && isdigit(*s)) {
            count *= 10, count += *s - '0';
            s++;
        }
        if (!count) count = 1;
        ss[(*len)++].count = count;
    }

    return s;
}
char *countOfAtoms(char *formula) {
    int len = 0;
    string_t ss[MAXN];
    char ans[MAXN], *ps;
    static char str[MAXN * 2];

    ps = str;
    resolve(formula, &ps, ss, &len);

    trie_t t = trie_create();
    for (int i = 0; i < len; ++i) {
        trie_add(t, &ss[i]);
    }

    ps = str;
    trie_dump(t, ans, 0, &ps);

    trie_free(t);

    return str;
}