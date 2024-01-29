// 电子游戏“辐射4”中，任务 “通向自由” 要求玩家到达名为 “Freedom Trail Ring” 的金属表盘，并使用表盘拼写特定关键词才能开门。
//
// 给定一个字符串 ring ，表示刻在外环上的编码；给定另一个字符串 key ，表示需要拼写的关键词。
// 您需要算出能够拼写关键词中所有字符的最少步数。
//
// 最初，ring 的第一个字符与 12:00 方向对齐。
// 您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在 12:00 方向对齐，然后按下中心按钮，以此逐个拼写完 key
// 中的所有字符。
//
// 旋转 ring 拼出 key 字符 key[i] 的阶段中：
//
//
// 您可以将 ring 顺时针或逆时针旋转 一个位置 ，计为1步。
// 旋转的最终目的是将字符串 ring 的一个字符与 12:00 方向对齐，并且这个字符必须等于字符 key[i] 。
// 如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步。
// 按完之后，您可以开始拼写 key 的下一个字符（下一阶段）, 直至完成所有拼写。
//
//
//
//
// 示例 1：
//
//
//
//
//
//
//
//
// 输入: ring = "godding", key = "gd"
// 输出: 4
// 解释:
// 对于 key 的第一个字符 'g'，已经在正确的位置, 我们只需要1步来拼写这个字符。
// 对于 key 的第二个字符 'd'，我们需要逆时针旋转 ring "godding" 2步使它变成 "ddinggo"。
// 当然, 我们还需要1步进行拼写。
// 因此最终的输出是 4。
//
//
// 示例 2:
//
//
// 输入: ring = "godding", key = "godding"
// 输出: 13
//
//
//
//
// 提示：
//
//
// 1 <= ring.length, key.length <= 100
// ring 和 key 只包含小写英文字母
// 保证 字符串 key 一定可以由字符串 ring 旋转拼出
//
//
// Related Topics 深度优先搜索 广度优先搜索 字符串 动态规划 👍 289 👎 0

#define WIDTH 26
typedef struct _node {
    struct _node *next;
    int pos;
    int count;
} node_t;
int dist(int a, int b, int l) {
    return fmin((a + l - b) % l, (b + l - a) % l);
}
int findRotateSteps(char *ring, char *key) {
    size_t rl = strlen(ring), now = 1, ans = INT32_MAX;
    node_t nodes[rl], *map[WIDTH] = { NULL };
    node_t *status[2] = { NULL }, help[rl * 2];

    for (int i = 0; i < rl; ++i) {
        nodes[i] = (node_t) { map[ring[i] - 'a'], i }, map[ring[i] - 'a'] = &nodes[i];
    }
    help[0] = (node_t) { 0 }, status[0] = &help[0];
    for (int i = 0, hp = 1; key[i]; ++i, now ^= 1) {
        status[now] = NULL;
        for (node_t *cur = map[key[i] - 'a']; cur; cur = cur->next) {
            help[hp] = (node_t) { status[now], cur->pos, INT32_MAX };
            for (node_t *pre = status[now ^ 1]; pre; pre = pre->next) {
                help[hp].count = fmin(help[hp].count, pre->count + dist(pre->pos, cur->pos, rl) + 1);
            }
            status[now] = &help[hp], hp = (hp + 1) % (rl * 2);
        }
    }
    for (node_t *p = status[now ^ 1]; p; p = p->next) {
        ans = fmin(ans, p->count);
    }
    return ans;
}