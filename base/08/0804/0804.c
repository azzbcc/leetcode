// 国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串， 比如: "a" 对应 ".-", "b" 对应
// "-...", "c " 对应 "-.-.", 等等。
//
// 为了方便，所有26个英文字母对应摩尔斯密码表如下：
//
// [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","-
// -","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--
// .."]
//
// 给定一个单词列表，每个单词可以写成每个字母对应摩尔斯密码的组合。例如，"cab" 可以写成 "-.-..--..."，(即 "-.-." + ".-"
// +
// "-..." 字符串的结合)。我们将这样一个连接过程称作单词翻译。
//
// 返回我们可以获得所有词不同单词翻译的数量。
//
// 例如:
// 输入: words = ["gin", "zen", "gig", "msg"]
// 输出: 2
// 解释:
// 各单词翻译如下:
// "gin" -> "--...-."
// "zen" -> "--...-."
// "gig" -> "--...--."
// "msg" -> "--...--."
//
// 共有 2 种不同翻译, "--...-." 和 "--...--.".
//
//
//
//
// 注意:
//
//
// 单词列表words 的长度不会超过 100。
// 每个单词 words[i]的长度范围为 [1, 12]。
// 每个单词 words[i]只包含小写字母。
//
// Related Topics 字符串
// 👍 130 👎 0

#if 0
#define WIDTH     2

typedef struct trie_node_t *trie_t;
struct trie_node_t {
    bool exist;
    trie_t next[WIDTH];
};

static char *dict[] = { ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
                        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
                        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.." };

trie_t trie_create() {
    trie_t t = calloc(1, sizeof(struct trie_node_t));

    t->exist = false;
    for (int i = 0; i < WIDTH; ++i) {
        t->next[i] = NULL;
    }

    return t;
}
#define INDEX(ch) (ch == '.')
bool trie_insert(trie_t t, char *s) {
    trie_t cur = t;

    while (*s) {
        char *str = dict[*s - 'a'];
        while (*str) {
            if (!cur->next[INDEX(*str)]) cur->next[INDEX(*str)] = trie_create();
            cur = cur->next[INDEX(*str)];
            str++;
        }
        s++;
    }

    bool ans = cur->exist;
    cur->exist = true;
    return !ans;
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; ++i) {
        trie_free(t->next[i]);
    }
    free(t);
}

int uniqueMorseRepresentations(char **words, int wordsSize) {
    int ans = 0;
    trie_t trie = trie_create();
    for (int i = 0; i < wordsSize; ++i) {
        ans += trie_insert(trie, words[i]);
    }

    trie_free(trie);

    return ans;
}
#else
#define MAXN 50
typedef struct {
    char str[MAXN];
    UT_hash_handle hh;
} * hash_t, node_t;
void morse_dump(char *str, char *out) {
    static char *dict[] = { ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
                            ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
                            "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.." };
    for (char *p = out; *str; ++str) {
        p += sprintf(p, "%s", dict[*str - 'a']);
    }
}
int uniqueMorseRepresentations(char **words, int size) {
    node_t nodes[size];
    hash_t hash = NULL, cur;
    for (int i = 0; i < size; ++i) {
        morse_dump(words[i], nodes[i].str);
        HASH_FIND_STR(hash, nodes[i].str, cur);
        if (!cur) HASH_ADD_STR(hash, str, &nodes[i]);
    }
    int ans = HASH_COUNT(hash);
    HASH_CLEAR(hh, hash);
    return ans;
}
#endif