// Trie（发音类似 "try"）或者说
// 前缀树是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼
// 写检查。
//
//  请你实现 Trie 类：
//
//
//  Trie() 初始化前缀树对象。
//  void insert(String word) 向前缀树中插入字符串 word 。
//  boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false。
//  boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false
//  。
//
//
//
//
//  示例：
//
//
// 输入
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// 输出
// [null, null, true, false, true, null, true]
//
// 解释
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // 返回 True
// trie.search("app");     // 返回 False
// trie.startsWith("app"); // 返回 True
// trie.insert("app");
// trie.search("app");     // 返回 True
//
//
//
//
//  提示：
//
//
//  1 <= word.length, prefix.length <= 2000
//  word 和 prefix 仅由小写英文字母组成
//  insert、search 和 startsWith 调用次数 总计 不超过 3  *104 次
//
//  Related Topics 设计 字典树
//  👍 688 👎 0

#define WIDTH 26

typedef struct trie_node {
    bool exist;
    struct trie_node *next[WIDTH];
} Trie;
Trie *trieCreate() {
    Trie *t  = calloc(1, sizeof(struct trie_node));
    t->exist = false;
    for (int i = 0; i < WIDTH; t->next[i++] = NULL) {}
    return t;
}
void trieInsert(Trie *trie, char *word) {
    for (char *s = word; *s; s++) {
        if (!trie->next[*s - 'a']) trie->next[*s - 'a'] = trieCreate();
        trie = trie->next[*s - 'a'];
    }
    trie->exist = true;
}
static Trie *trieNode(Trie *trie, char *word) {
    for (char *s = word; *s && trie; trie = trie->next[*s++ - 'a']) {}
    return trie;
}
bool trieSearch(Trie *trie, char *word) {
    trie = trieNode(trie, word);
    return trie ? trie->exist : false;
}
bool trieStartsWith(Trie *trie, char *prefix) {
    trie = trieNode(trie, prefix);
    return trie ? true : false;
}
void trieFree(Trie *trie) {
    if (!trie) return;
    for (int i = 0; i < WIDTH; trieFree(trie->next[i++])) {}
    free(trie);
}