// 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
// 的最短转换序列的长度。转换需遵循如下规则：
//
//
//
// 每次转换只能改变一个字母。
// 转换过程中的中间单词必须是字典中的单词。
//
//
// 说明:
//
//
// 如果不存在这样的转换序列，返回 0。
// 所有单词具有相同的长度。
// 所有单词只由小写字母组成。
// 字典中不存在重复的单词。
// 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
//
//
// 示例 1:
//
// 输入:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// 输出: 5
//
// 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//     返回它的长度 5。
//
//
// 示例 2:
//
// 输入:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
//输出: 0
//
//解释: endWord "cog" 不在字典中，所以无法进行转换。
// Related Topics 广度优先搜索
// 👍 566 👎 0

typedef struct {
    const char *str;
    int step;
} node_t;
static bool similar(const char *s1, const char *s2) {
    for (int c = 0; *s1 && *s2; s1++, s2++) {
        c += *s1 != *s2;
        if (c > 1) return false;
    }
    return true;
}
int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize) {
    int front = 0, rear = 0;
    bool visited[wordListSize];
    node_t queue[wordListSize + 1];

    memset(visited, false, sizeof(visited));
    queue[rear++] = (node_t) { beginWord, 1 };
    while (front < rear) {
        node_t now = queue[front++];

        if (!strcmp(now.str, endWord)) return now.step;

        for (int i = 0; i < wordListSize; ++i) {
            if (visited[i] || !similar(wordList[i], now.str)) continue;
            visited[i] = true, queue[rear++] = (node_t) { wordList[i], now.step + 1 };
        }
    }

    return 0;
}
