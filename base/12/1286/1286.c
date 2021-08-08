// 请你设计一个迭代器类，包括以下内容：
//
//
// 一个构造函数，输入参数包括：一个 有序且字符唯一 的字符串 characters（该字符串只包含小写英文字母）和一个数字
// combinationLength 。 函数 next() ，按 字典序 返回长度为 combinationLength 的下一个字母组合。 函数 hasNext()
// ，只有存在长度为 combinationLength 的下一个字母组合时，才返回 True；否则，返回 False。
//
//
//
//
// 示例：
//
// CombinationIterator iterator = new CombinationIterator("abc", 2); // 创建迭代器 iterator
//
// iterator.next(); // 返回 "ab"
// iterator.hasNext(); // 返回 true
// iterator.next(); // 返回 "ac"
// iterator.hasNext(); // 返回 true
// iterator.next(); // 返回 "bc"
// iterator.hasNext(); // 返回 false
//
//
//
//
// 提示：
//
//
// 1 <= combinationLength <= characters.length <= 15
// 每组测试数据最多包含 10^4 次函数调用。
// 题目保证每次调用函数 next 时都存在下一个字母组合。
//
// Related Topics 设计 回溯算法
// 👍 30 👎 0

typedef struct {
    size_t now, m, n;
    char *str, *ans;
} CombinationIterator;

/**
 * C(m, n)
 * @param m
 * @param n
 * @return
 */
int C(int m, int n) {
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * (m - i) / (i + 1);
    }
    return ans;
}

/**
 * C(m, n) <= k <= C(m + 1, n)
 * @param n
 * @param k
 * @return m
 */
int Cm(int n, int k) {
    int m = n;
    for (int s = 1; s <= k; m++) {
        s = s * (m + 1) / (m - n + 1);
    }
    return m - 1;
}

CombinationIterator *combinationIteratorCreate(char *characters, int combinationLength) {
    CombinationIterator *obj = calloc(1, sizeof(CombinationIterator));

    obj->ans = calloc(combinationLength + 1, sizeof(char));
    obj->str = strdup(characters);
    obj->m = strlen(characters), obj->n = combinationLength, obj->now = C(obj->m, obj->n);

    return obj;
}

char *combinationIteratorNext(CombinationIterator *obj) {
    char *ptr = obj->ans;
    for (int k = --obj->now, m, n = obj->n; n; k -= C(m, n--)) {
        m = Cm(n, k), *ptr++ = obj->str[obj->m - m - 1];
    }
    return obj->ans;
}

bool combinationIteratorHasNext(CombinationIterator *obj) {
    return obj->now;
}

void combinationIteratorFree(CombinationIterator *obj) {
    free(obj->ans);
    free(obj->str);
    free(obj);
}