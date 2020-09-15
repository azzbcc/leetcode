// 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i
// 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//
// 说明：你不能倾斜容器，且 n 的值至少为 2。
//
//
//
//
//
// 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
//
//
//
// 示例：
//
// 输入：[1,8,6,2,5,4,8,3,7]
// 输出：49
// Related Topics 数组 双指针
// 👍 1698 👎 0

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int maxArea(int *height, int heightSize) {
    int cur_height = 0, max = 0;
    int beg = 0, end = heightSize - 1;

    while (beg < end) {
        while (beg < end && height[beg] <= cur_height) {
            beg += 1;
        }
        while (beg < end && height[end] <= cur_height) {
            end -= 1;
        }
        if (beg >= end) break;

        cur_height = MIN(height[beg], height[end]);
        max        = MAX(max, (end - beg) * cur_height);
    }

    return max;
}
