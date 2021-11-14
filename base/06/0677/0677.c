// 实现一个 MapSum 类，支持两个方法，insert 和 sum：
//
//
// MapSum() 初始化 MapSum 对象
// void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。
// 如果键 key 已经存在，那么原来的键值对将被替代成新的键值对。
// int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
//
//
//
//
// 示例：
//
//
// 输入：
// ["MapSum", "insert", "sum", "insert", "sum"]
// [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
// 输出：
// [null, null, 3, null, 5]
//
// 解释：
// MapSum mapSum = new MapSum();
// mapSum.insert("apple", 3);
// mapSum.sum("ap");           // return 3 (apple = 3)
// mapSum.insert("app", 2);
// mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
//
//
//
//
// 提示：
//
//
// 1 <= key.length, prefix.length <= 50
// key 和 prefix 仅由小写英文字母组成
// 1 <= val <= 1000
// 最多调用 50 次 insert 和 sum
//
// Related Topics 设计 字典树 哈希表 字符串 👍 167 👎 0

#define WIDTH 26

typedef struct trie_node_t *trie_t;
struct trie_node_t {
    int sum;
    trie_t next[WIDTH];
};
trie_t trie_create() {
    return calloc(1, sizeof(struct trie_node_t));
}
void trie_insert(trie_t t, char *s, int val) {
    trie_t cur = t;
    for (; *s; cur = cur->next[*s++ - 'a']) {
        if (!cur->next[*s - 'a']) cur->next[*s - 'a'] = trie_create();
        cur->next[*s - 'a']->sum += val;
    }
    t->sum += val;
}
trie_t trie_find(trie_t t, const char *s) {
    trie_t cur = t;
    for (; *s && cur; cur = cur->next[*s - 'a']) {}
    return cur;
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; trie_free(t->next[i++])) {}
    free(t);
}
typedef struct {
    char *str;
    int val;
    UT_hash_handle hh;
} * hash_t;
int hash_record(hash_t *t, char *key, int val) {
    hash_t cur;
    int plus = val;
    HASH_FIND_STR(*t, key, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->str = key;
        HASH_ADD_STR(*t, str, cur);
    } else {
        plus -= cur->val;
    }
    cur->val = val;
    return plus;
}
typedef struct {
    hash_t hash;
    trie_t trie;
} MapSum;
MapSum *mapSumCreate() {
    MapSum *sum = malloc(sizeof(MapSum));
    sum->hash = NULL, sum->trie = trie_create();
    return sum;
}
void mapSumInsert(MapSum *mapSum, char *key, int val) {
    int plus = hash_record(&mapSum->hash, key, val);
    trie_insert(mapSum->trie, key, plus);
}
int mapSumSum(MapSum *mapSum, char *prefix) {
    trie_t cur = mapSum->trie;
    for (; *prefix && cur; cur = cur->next[*prefix++ - 'a']) {}
    return cur ? cur->sum : 0;
}
void mapSumFree(MapSum *mapSum) {
    hash_t cur, next;
    trie_free(mapSum->trie);
    HASH_ITER(hh, mapSum->hash, cur, next) {
        HASH_DEL(mapSum->hash, cur);
        free(cur);
    }
    free(mapSum);
}