// 如果你熟悉 Shell 编程，那么一定了解过花括号展开，它可以用来生成任意字符串。
//
// 花括号展开的表达式可以看作一个由 花括号、逗号 和 小写英文字母 组成的字符串，定义下面几条语法规则：
//
//
// 如果只给出单一的元素 x，那么表达式表示的字符串就只有 "x"。R(x) = {x}
//
//
//
// 例如，表达式 "a" 表示字符串 "a"。
// 而表达式 "w" 就表示字符串 "w"。
//
//
// 当两个或多个表达式并列，以逗号分隔，我们取这些表达式中元素的并集。R({e_1,e_2,...}) = R(e_1) ∪ R(e_2) ∪ ...
//
// 例如，表达式 "{a,b,c}" 表示字符串 "a","b","c"。
// 而表达式 "{{a,b},{b,c}}" 也可以表示字符串 "a","b","c"。
//
//
// 要是两个或多个表达式相接，中间没有隔开时，我们从这些表达式中各取一个元素依次连接形成字符串。R(e_1 + e_2) = {a + b for
// (a, b) in R(e_1) × R(e_2)}
//
// 例如，表达式 "{a,b}{c,d}" 表示字符串 "ac","ad","bc","bd"。
//
//
// 表达式之间允许嵌套，单一元素与表达式的连接也是允许的。
//
// 例如，表达式 "a{b,c,d}" 表示字符串 "ab","ac","ad"。
// 例如，表达式 "a{b,c}{d,e}f{g,h}" 可以表示字符串 "abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg",
// "acefh"。
//
//
//
//
// 给出表示基于给定语法规则的表达式 expression，返回它所表示的所有字符串组成的有序列表。
//
// 假如你希望以「集合」的概念了解此题，也可以通过点击 “显示英文描述” 获取详情。
//
//
//
// 示例 1：
//
//
// 输入：expression = "{a,b}{c,{d,e}}"
// 输出：["ac","ad","ae","bc","bd","be"]
//
// 示例 2：
//
//
// 输入：expression = "{{a,z},a{b,c},{ab,z}}"
// 输出：["a","ab","ac","z"]
// 解释：输出中 不应 出现重复的组合结果。
//
//
//
//
// 提示：
//
//
// 1 <= expression.length <= 60
// expression[i] 由 '{'，'}'，',' 或小写英文字母组成
// 给出的表达式 expression 用以表示一组基于题目描述中语法构造的字符串
//
//
// Related Topics 栈 广度优先搜索 字符串 回溯 👍 94 👎 0

#define MAXN 0x40
typedef struct {
    char str[MAXN];
    UT_hash_handle hh;
} *hash_t;
void hash_record(hash_t *t, char *str) {
    hash_t cur;
    HASH_FIND_STR(*t, str, cur);
    if (cur) return;
    cur = malloc(sizeof(*cur));
    strcpy(cur->str, str);
    HASH_ADD_STR(*t, str, cur);
}
hash_t hash_mul(hash_t t1, hash_t t2) {
    char tmp[MAXN];
    if (!t1) return t2;
    hash_t hash = NULL, t1_cur, t1_next, t2_cur, t2_next;
    HASH_ITER(hh, t1, t1_cur, t1_next) {
        HASH_ITER(hh, t2, t2_cur, t2_next) {
            sprintf(tmp, "%s%s", t1_cur->str, t2_cur->str);
            hash_record(&hash, tmp);
        }
        HASH_DEL(t1, t1_cur);
        free(t1_cur);
    }
    HASH_ITER(hh, t2, t2_cur, t2_next) {
        HASH_DEL(t2, t2_cur);
        free(t2_cur);
    }
    return hash;
}
hash_t hash_add(hash_t t1, hash_t t2) {
    if (!t1) return t2;
    hash_t hash = t1, cur, next;
    HASH_ITER(hh, t2, cur, next) {
        hash_record(&hash, cur->str);
        HASH_DEL(t2, cur);
        free(cur);
    }
    return hash;
}
int hash_cmp(hash_t t1, hash_t t2) {
    return strcmp(t1->str, t2->str);
}

hash_t expr(char **s) {
    hash_t hash = NULL, split, item;
    for (; split = NULL, **s; ++*s) {
        for (; item = NULL, **s == '{' || isalpha(**s);) {
            if (**s == '{') {
                ++*s, item = expr(s), ++*s;
            } else {
                char str[MAXN] = "";
                for (int pos = 0; isalpha(**s); str[pos++] = *(*s)++) {}
                hash_record(&item, str);
            }
            split = hash_mul(split, item);
        }
        hash = hash_add(hash, split);
        if (**s != ',') break;
    }
    return hash;
}
char **braceExpansionII(char *expression, int *returnSize) {
    hash_t cur, hash = expr(&expression);
    char **ans = malloc((*returnSize = HASH_COUNT(hash)) * sizeof(char *));
    HASH_SORT(hash, hash_cmp);
    for (int i = 0; (cur = hash); ++i) {
        ans[i] = strdup(cur->str);
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
