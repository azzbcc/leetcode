// 给出一些不同颜色的盒子，盒子的颜色由数字表示，即不同的数字表示不同的颜色。
// 你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。每一轮你可以移除具有相同颜色的连续 k 个盒子（k >=
// 1），这样一轮之后你将得到 k*k 个积分 。 当你将所有盒子都去掉之后，求你能获得的最大积分和。
//
//
//
// 示例：
//
// 输入：boxes = [1,3,2,2,2,3,4,3,1]
// 输出：23
// 解释：
// [1, 3, 2, 2, 2, 3, 4, 3, 1]
// ----> [1, 3, 3, 4, 3, 1] (3*3=9 分)
// ----> [1, 3, 3, 3, 1] (1*1=1 分)
// ----> [1, 1] (3*3=9 分)
// ----> [] (2*2=4 分)
//
//
//
//
// 提示：
//
//
// 1 <= boxes.length <= 100
// 1 <= boxes[i] <= 100
//
// Related Topics 深度优先搜索 动态规划
// 👍 228 👎 0
#define MAXN 100
typedef struct st_state {
    struct st_node {
        uint8_t val, count;
        int8_t prev, next;
    } nodes[MAXN];
    int8_t head;
    uint8_t repeats[MAXN + 1];
} state_t;

void dfs(state_t state, int ans, int *result) {
    // remove all data which repeat only 1 time
    for (int8_t pos = state.head; pos >= 0;) {
        if (state.repeats[state.nodes[pos].val] == 1) {
            state.repeats[state.nodes[pos].val] = 0;
            ans += state.nodes[pos].count * state.nodes[pos].count;

            // remove current node
            if (state.nodes[pos].prev >= 0) state.nodes[state.nodes[pos].prev].next = state.nodes[pos].next;
            if (state.nodes[pos].next >= 0) state.nodes[state.nodes[pos].next].prev = state.nodes[pos].prev;

            // back to prev if exists
            if (state.nodes[pos].prev >= 0) {
                pos = state.nodes[pos].prev;
            } else if (state.nodes[pos].next >= 0) {
                state.head = pos = state.nodes[pos].next;
            } else {
                state.head = -1;
                break;
            }
        } else if (state.nodes[pos].next >= 0 && state.nodes[pos].val == state.nodes[state.nodes[pos].next].val) {
            state.repeats[state.nodes[pos].val] -= 1;
            state.nodes[pos].count += state.nodes[state.nodes[pos].next].count;

            // remove next node
            state.nodes[pos].next = state.nodes[state.nodes[pos].next].next;
            if (state.nodes[pos].next >= 0) state.nodes[state.nodes[pos].next].prev = pos;
        } else {
            pos = state.nodes[pos].next;
        }
    }

    if (state.head < 0) {
        if (*result < ans) *result = ans;
        return;
    }

    for (int8_t pos = state.nodes[state.head].next; state.nodes[pos].next >= 0; pos = state.nodes[pos].next) {
        // try remove current node
        state_t cur = state;

        // remove current node
        cur.repeats[cur.nodes[pos].val] -= 1;
        cur.nodes[cur.nodes[pos].prev].next = cur.nodes[pos].next;
        cur.nodes[cur.nodes[pos].next].prev = cur.nodes[pos].prev;

        dfs(cur, ans + cur.nodes[pos].count * cur.nodes[pos].count, result);
    }
}

int removeBoxes(int *boxes, int boxesSize) {
    int ans       = 0;
    state_t state = { .nodes[0] = { boxes[0], 1, -1, -1 } };

    // data initial
    state.repeats[boxes[0]] = 1;
    for (int i = 1, cur = 0; i < boxesSize; ++i) {
        if (boxes[i] == state.nodes[cur].val) {
            state.nodes[cur].count += 1;
        } else {
            cur += 1;
            state.repeats[boxes[i]] += 1;
            state.nodes[cur].val = boxes[i], state.nodes[cur].count = 1;
            state.nodes[cur].prev     = cur - 1;
            state.nodes[cur].next     = -1;
            state.nodes[cur - 1].next = cur;
        }
    }

    dfs(state, 0, &ans);

    return ans;
}
