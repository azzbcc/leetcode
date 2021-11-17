// 给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。
// 你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
//
//
//
// 示例 1:
//
//
// 输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
// 输出: 16
// 解释: 这两个单词为 "abcw", "xtfn"。
//
// 示例 2:
//
//
// 输入: ["a","ab","abc","d","cd","bcd","abcd"]
// 输出: 4
// 解释: 这两个单词为 "ab", "cd"。
//
// 示例 3:
//
//
// 输入: ["a","aa","aaa","aaaa"]
// 输出: 0
// 解释: 不存在这样的两个单词。
//
//
//
//
// 提示：
//
//
// 2 <= words.length <= 1000
// 1 <= words[i].length <= 1000
// words[i] 仅包含小写字母
//
// Related Topics 位运算 数组 字符串 👍 236 👎 0

typedef struct {
    uint32_t len, mask;
} node_t;
node_t node_parser(char *str) {
    node_t ans = { 0 };
    for (; *str; ++str, ++ans.len) {
        ans.mask |= 0x1 << (*str - 'a');
    }
    return ans;
}
int maxProduct(char **words, int size) {
    int ans = 0;
    node_t nodes[size];
    for (int i = 0; i < size; ++i) {
        nodes[i] = node_parser(words[i]);
        for (int j = 0; j < i; ++j) {
            if (nodes[i].mask & nodes[j].mask) continue;
            ans = fmax(ans, nodes[i].len * nodes[j].len);
        }
    }
    return ans;
}