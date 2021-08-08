// 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
//
// 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有
// maxWidth 个字符。
//
// 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
//
// 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
//
// 说明:
//
//
// 单词是指由非空格字符组成的字符序列。
// 每个单词的长度大于 0，小于等于 maxWidth。
// 输入单词数组 words 至少包含一个单词。
//
//
// 示例:
//
// 输入:
// words = ["This", "is", "an", "example", "of", "text", "justification."]
// maxWidth = 16
// 输出:
// [
//   "This    is    an",
//   "example  of text",
//   "justification.  "
// ]
//
//
// 示例 2:
//
// 输入:
// words = ["What","must","be","acknowledgment","shall","be"]
// maxWidth = 16
// 输出:
// [
//  "What   must   be",
//  "acknowledgment  ",
//  "shall be        "
// ]
// 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
//     因为最后一行应为左对齐，而不是左右两端对齐。
//     第二行同样为左对齐，这是因为这行只包含一个单词。
//
//
// 示例 3:
//
// 输入:
// words = ["Science","is","what","we","understand","well","enough","to","explain",
//         "to","a","computer.","Art","is","everything","else","we","do"]
// maxWidth = 20
// 输出:
// [
//  "Science  is  what we",
//  "understand      well",
//  "enough to explain to",
//  "a  computer.  Art is",
//  "everything  else  we",
//  "do                  "
// ]
//
// Related Topics 字符串
// 👍 116 👎 0

char *line(char *words[], int sum, int size, int maxWidth, bool end) {
    int empty[size];
    char *ans = malloc(maxWidth + 1), *tmp = ans;

    if (end) {
        for (int i = size - 2; i >= 0; --i) {
            empty[i] = 1, sum += empty[i];
        }
    } else {
        for (int i = size - 2; i >= 0; --i) {
            empty[i] = (maxWidth - sum) / (i + 1), sum += empty[i];
        }
    }
    empty[size - 1] = maxWidth - sum;

    for (int i = 0; i < size; ++i) {
        tmp += sprintf(tmp, "%s%-*s", words[i], empty[i], "");
    }

    return ans;
}
char **fullJustify(char **words, int wordsSize, int maxWidth, int *returnSize) {
    char *help[wordsSize], **ans;
    int lens[wordsSize], last = 0, sum = 0, len = 0;

    for (int i = 0; i < wordsSize; sum += lens[i++]) {
        lens[i] = strlen(words[i]);
        if (sum + lens[i] + i - last > maxWidth) {
            help[len++] = line(&words[last], sum, i - last, maxWidth, false);
            sum = 0, last = i;
        }
    }
    help[len++] = line(&words[last], sum, wordsSize - last, maxWidth, true);

    *returnSize = len, ans = malloc(len * sizeof(char *));
    memcpy(ans, help, len * sizeof(char *));

    return ans;
}
