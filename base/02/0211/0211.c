// 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
//
// 实现词典类 WordDictionary ：
//
//
// WordDictionary() 初始化词典对象
// void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
// bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回 false 。
// word 中可能包含一些'.' ，每个 . 都可以表示任何一个字母。
//
//
//
//
// 示例：
//
//
// 输入：
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// 输出：
// [null,null,null,null,false,true,true,true]
//
// 解释：
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True
//
//
//
//
// 提示：
//
//
// 1 <= word.length <= 500
// addWord 中的 word 由小写英文字母组成
// search 中的 word 由 '.' 或小写英文字母组成
// 最多调用 50000 次 addWord 和 search
//
// Related Topics 深度优先搜索 设计 字典树 字符串 👍 312 👎 0

#define WIDTH 26
typedef struct trie_node {
    bool exist;
    struct trie_node *next[WIDTH];
} * trie_t, WordDictionary;
trie_t wordDictionaryCreate() {
    return calloc(1, sizeof(struct trie_node));
}
void wordDictionaryAddWord(trie_t t, char *str) {
    for (char *s = str; *s; s++) {
        if (!t->next[*s - 'a']) t->next[*s - 'a'] = wordDictionaryCreate();
        t = t->next[*s - 'a'];
    }
    t->exist = true;
}
bool wordDictionarySearch(trie_t t, char *word) {
    bool ans = false;
    if (!t) return ans;
    if (!*word) return t->exist;
    if (*word != '.') return wordDictionarySearch(t->next[*word - 'a'], word + 1);
    for (int i = 0; !ans && i < WIDTH; ++i) {
        ans = wordDictionarySearch(t->next[i], word + 1);
    }
    return ans;
}
void wordDictionaryFree(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; wordDictionaryFree(t->next[i++])) {}
    free(t);
}
