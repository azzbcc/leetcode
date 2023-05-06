// 给你一个字符串 croakOfFrogs，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合。
// 由于同一时间可以有多只青蛙呱呱作响，所以croakOfFrogs 中会混合多个 “croak” 。
//
// 请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。
//
// 要想发出蛙鸣 "croak"，青蛙必须 依序 输出 ‘c’, ’r’, ’o’, ’a’, ’k’ 这 5 个字母。
// 如果没有输出全部五个字母，那么它就不会发出声音。
// 如果字符串 croakOfFrogs 不是由若干有效的 "croak" 字符混合而成，请返回 -1 。
//
//
//
// 示例 1：
//
//
// 输入：croakOfFrogs = "croakcroak"
// 输出：1
// 解释：一只青蛙 “呱呱” 两次
//
//
// 示例 2：
//
//
// 输入：croakOfFrogs = "crcoakroak"
// 输出：2
// 解释：最少需要两只青蛙，“呱呱” 声用黑体标注
// 第一只青蛙 "crcoakroak"
// 第二只青蛙 "crcoakroak"
//
//
// 示例 3：
//
//
// 输入：croakOfFrogs = "croakcrook"
// 输出：-1
// 解释：给出的字符串不是 "croak" 的有效组合。
//
//
//
//
// 提示：
//
//
// 1 <= croakOfFrogs.length <= 10⁵
// 字符串中的字符只有 'c', 'r', 'o', 'a' 或者 'k'
//
//
// Related Topics 字符串 计数 👍 167 👎 0

int indexOf(char ch) {
    static char *croak = "croak";
    for (int i = 0; croak[i]; ++i) {
        if (ch == croak[i]) return i;
    }
    return -1;
}
int minNumberOfFrogs(char *croakOfFrogs) {
    int st[5] = { 0 }, ans = 0, pos;
    for (char *p = croakOfFrogs; *p; ++p) {
        ans = fmax(ans, ++st[pos = indexOf(*p)]);
        if (pos && st[pos] > st[pos - 1]) return -1;
        for (int i = 0; pos == 4 && i < 5; st[i++]--) {}
    }
    for (int i = 0; i < 5; ++i) {
        if (st[i]) return -1;
    }
    return ans;
}