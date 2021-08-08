// 实现一个带有buildDict, 以及 search方法的魔法字典。
//
// 对于buildDict方法，你将被给定一串不重复的单词来构建一个字典。
//
// 对于search方法，你将被给定一个单词，并且判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。
//
// 示例 1:
//
//
// Input: buildDict(["hello", "leetcode"]), Output: Null
// Input: search("hello"), Output: False
// Input: search("hhllo"), Output: True
// Input: search("hell"), Output: False
// Input: search("leetcoded"), Output: False
//
//
// 注意:
//
//
// 你可以假设所有输入都是小写字母 a-z。
// 为了便于竞赛，测试所用的数据量很小。你可以在竞赛结束后，考虑更高效的算法。
// 请记住重置MagicDictionary类中声明的类变量，因为静态/类变量会在多个测试用例中保留。 请参阅这里了解更多详情。
//
// Related Topics 字典树 哈希表
// 👍 59 👎 0
#define WIDTH 26

typedef struct magic_dictionary {
    bool exist;
    struct magic_dictionary *next[WIDTH];
} MagicDictionary;

MagicDictionary *magicDictionaryCreate() {
    return calloc(1, sizeof(MagicDictionary));
}
static void magicDictionaryInsert(MagicDictionary *dict, char *s) {
    MagicDictionary *cur = dict;

    while (*s) {
        if (!cur->next[*s - 'a']) cur->next[*s - 'a'] = magicDictionaryCreate();
        cur = cur->next[*s++ - 'a'];
    }
    cur->exist = true;
}
void magicDictionaryBuildDict(MagicDictionary *dict, char **strings, int sice) {
    for (int i = 0; i < sice; ++i) {
        magicDictionaryInsert(dict, strings[i]);
    }
}
static bool dfs(MagicDictionary *dict, char *word, bool wrong) {
    if (!dict) return false;
    if (!*word) return wrong && dict->exist;
    if (wrong) return dfs(dict->next[*word - 'a'], word + 1, wrong);
    for (int i = 0; i < WIDTH; ++i) {
        if (dfs(dict->next[i], word + 1, *word != 'a' + i)) return true;
    }
    return false;
}
bool magicDictionarySearch(MagicDictionary *dict, char *word) {
    return dfs(dict, word, false);
}
void magicDictionaryFree(MagicDictionary *dict) {
    if (!dict) return;
    for (int i = 0; i < WIDTH; magicDictionaryFree(dict->next[i++])) {}
    free(dict);
}