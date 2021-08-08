//如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y
//两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。
//
//
// 例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； "rats" 和 "arts" 也是相似的，但是 "star" 不与 "t
// ars"，"rats"，或 "arts" 相似。
//
// 总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}。注意，"tars" 和 "arts" 是在同
//一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。
//
// 给你一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个字母异位词。请问 strs
// 中有多少个相似字符串组？
//
//
//
// 示例 1：
//
//
//输入：strs = ["tars","rats","arts","star"]
//输出：2
//
//
// 示例 2：
//
//
//输入：strs = ["omv","ovm"]
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= strs.length <= 100
// 1 <= strs[i].length <= 1000
// sum(strs[i].length) <= 2 * 104
// strs[i] 只包含小写字母。
// strs 中的所有单词都具有相同的长度，且是彼此的字母异位词。
//
//
//
//
// 备注：
//
// 字母异位词（anagram），一种把某个字符串的字母的位置（顺序）加以改换所形成的新词。
// Related Topics 深度优先搜索 并查集 图
// 👍 89 👎 0

int find(int ancestor[], int n) {
    if (ancestor[n] == n) return n;
    return ancestor[n] = find(ancestor, ancestor[n]);
}
void merge(int ancestor[], int a, int b) {
    ancestor[find(ancestor, a)] = find(ancestor, b);
}
bool similar(char *s1, char *s2) {
    int count = 0;
    for (; *s1 && count < 3; s1++, s2++) {
        count += *s1 != *s2;
    }
    return count < 3;
}
int numSimilarGroups(char **strs, int size) {
    int ancestor[size], count = 0;

    for (int i = 0; i < size; i++) {
        ancestor[i] = i;
        for (int j = 0; j < i; j++) {
            if (find(ancestor, i) == find(ancestor, j)) continue;
            if (!similar(strs[i], strs[j])) continue;
            count++, merge(ancestor, i, j);
        }
    }

    return size - count;
}
