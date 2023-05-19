// 你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。
//
// 注意：本题中，每个活字字模只能使用一次。
//
//
//
// 示例 1：
//
//
// 输入："AAB"
// 输出：8
// 解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
//
//
// 示例 2：
//
//
// 输入："AAABBC"
// 输出：188
//
//
// 示例 3：
//
//
// 输入："V"
// 输出：1
//
//
//
// 提示：
//
//
// 1 <= tiles.length <= 7
// tiles 由大写英文字母组成
//
//
// Related Topics 哈希表 字符串 回溯 计数 👍 209 👎 0

int dfs(int count[], char *dict, int size) {
    if (size == 0) return 1;
    int ans = 1;
    for (char *p = dict; *p; ++p) {
        if (!count[*p - 'A']) continue;
        count[*p - 'A']--;
        ans += dfs(count, dict, size - 1);
        count[*p - 'A']++;
    }
    return ans;
}

int numTilePossibilities(char *tiles) {
    char dict[26] = { '\0' };
    int count[26] = { 0 }, size = 0, tmp = 0;
    for (char *p = tiles; *p; ++p, ++size) {
        if (count[*p - 'A']++) continue;
        dict[tmp++] = *p;
    }
    return dfs(count, dict, size) - 1;
}