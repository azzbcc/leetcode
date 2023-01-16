// 一个句子是由一些单词与它们之间的单个空格组成，且句子的开头和结尾没有多余空格。比方说，"Hello World" ，"HELLO"
// ，"hello world hello world" 都是句子。每个单词都 只 包含大写和小写英文字母。
//
// 如果两个句子 sentence1 和 sentence2
// ，可以通过往其中一个句子插入一个任意的句子（可以是空句子）而得到另一个句子，那么我们称这两个句子是 相似的
// 。比方说，sentence1 = "Hello my name is Jane" 且 sentence2 = "Hello Jane" ，我们可以往 sentence2 中 "Hello" 和 "Jane"
// 之间插入 "my name is" 得到 sentence1 。
//
// 给你两个句子 sentence1 和 sentence2 ，如果 sentence1 和 sentence2 是相似的，请你返回 true ，否则返回false 。
//
//
//
// 示例 1：
//
// 输入：sentence1 = "My name is Haley", sentence2 = "My Haley"
// 输出：true
// 解释：可以往 sentence2 中 "My" 和 "Haley" 之间插入 "name is" ，得到 sentence1 。
//
//
// 示例 2：
//
// 输入：sentence1 = "of", sentence2 = "A lot of words"
// 输出：false
// 解释：没法往这两个句子中的一个句子只插入一个句子就得到另一个句子。
//
//
// 示例 3：
//
// 输入：sentence1 = "Eating right now", sentence2 = "Eating"
// 输出：true
// 解释：可以往 sentence2 的结尾插入 "right now" 得到 sentence1 。
//
//
// 示例 4：
//
// 输入：sentence1 = "Luky", sentence2 = "Lucccky"
// 输出：false
//
//
//
//
// 提示：
//
//
// 1 <= sentence1.length, sentence2.length <= 100
// sentence1 和 sentence2 都只包含大小写英文字母和空格。
// sentence1 和 sentence2 中的单词都只由单个空格隔开。
//
//
// Related Topics 数组 双指针 字符串 👍 64 👎 0

#define MAXN 100
typedef struct {
    char *ptr;
    int len;
} letter_t;
void letter_init(letter_t *l) {
    l->ptr = NULL, l->len = 0;
}
bool letter_eq(letter_t *l1, letter_t *l2) {
    return l1->len == l2->len && !strncmp(l1->ptr, l2->ptr, l1->len);
}
typedef struct {
    letter_t letters[MAXN];
    int count;
} string_t;
void string_parser(string_t *s, char *str) {
    letter_init(&s->letters[s->count = 0]);
    for (int i = 0; !i || str[i - 1]; ++i) {
        if (isalpha(str[i])) {
            if (!s->letters[s->count].len++) {
                s->letters[s->count].ptr = str + i;
            }
        } else if (s->letters[s->count].len) {
            letter_init(&s->letters[++s->count]);
        }
    }
}
bool string_similar(string_t *s1, string_t *s2) {
    if (s1->count > s2->count) return string_similar(s2, s1);

    int l = 0, r = 0;
    for (; l < s1->count && letter_eq(&s1->letters[l], &s2->letters[l]); ++l) {}
    for (; r < s1->count - l && letter_eq(&s1->letters[s1->count - r - 1], &s2->letters[s2->count - r - 1]); ++r) {}
    return l + r == s1->count;
}
bool areSentencesSimilar(char *sentence1, char *sentence2) {
    string_t s1 = { 0 }, s2 = { 0 };
    string_parser(&s1, sentence1);
    string_parser(&s2, sentence2);
    return string_similar(&s1, &s2);
}