// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。
//
//
//
//
//
// 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
//
//
//
//
//
// 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
//
//
//
// 示例:
//
// 输入: [2,1,5,6,2,3]
// 输出: 10
// Related Topics 栈 数组
// 👍 1053 👎 0

typedef struct {
    int height, position;
} node_t;
int largestRectangleArea(int *heights, int size) {
    int top = 0, ans = 0;
    node_t stack[size + 1];

    stack[0] = (node_t) { 0, -1 };
    for (int i = 0, h; i < size; ++i) {
        for (h = heights[i]; top && h <= stack[top].height; --top) {
            if (ans < stack[top].height * (i - stack[top - 1].position - 1)) {
                ans = stack[top].height * (i - stack[top - 1].position - 1);
            }
        }
        stack[++top] = (node_t) { h, i };
    }
    for (; top; --top) {
        if (ans < stack[top].height * (size - stack[top - 1].position - 1)) {
            ans = stack[top].height * (size - stack[top - 1].position - 1);
        }
    }

    return ans;
}
