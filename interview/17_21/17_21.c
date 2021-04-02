// 给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。
//
//
//
// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的直方图，在这种情况下，可以接 6 个单位的水（蓝色部分表示水）。 感谢
// Marcos 贡献此图。
//
// 示例:
//
// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出: 6
// Related Topics 栈 数组 双指针
// 👍 145 👎 0

#if 0
int min(int a, int b) {
    return a < b ? a : b;
}
int trap_height(const int height[], int l, int r) {
    int ans = 0;
    for (int h = min(height[l], height[r]); ++l < r; ans += h - height[l]) {}
    return ans;
}
int trap(int *height, int size) {
    if (!size) return 0;
    int memory[2][size];
    struct {
        int top;
        int *base;
    } prefix = { -1, memory[0] }, suffix = { -1, memory[1] };

    prefix.base[++prefix.top] = 0;
    for (int i = 0; i < size; ++i) {
        if (height[i] > height[prefix.base[prefix.top]]) prefix.base[++prefix.top] = i;
    }
    suffix.base[++suffix.top] = size - 1;
    for (int i = size - 1; i >= 0; --i) {
        if (height[i] > height[suffix.base[suffix.top]]) suffix.base[++suffix.top] = i;
    }

    int ans = trap_height(height, prefix.base[prefix.top], suffix.base[suffix.top]);
    for (int i = 0; i < prefix.top; ++i) {
        ans += trap_height(height, prefix.base[i], prefix.base[i + 1]);
    }
    for (int i = 0; i < suffix.top; ++i) {
        ans += trap_height(height, suffix.base[i + 1], suffix.base[i]);
    }

    return ans;
}
#else
int trap(int *height, int size) {
    if (!size) return 0;
    int ans = 0;
    for (int l = 0, r = size - 1, lmax = height[l], rmax = height[r]; l < r;) {
        if (height[l] < height[r]) {
            ans += lmax - height[l++];
            if (lmax < height[l]) lmax = height[l];
        } else {
            ans += rmax - height[r--];
            if (rmax < height[r]) rmax = height[r];
        }
    }
    return ans;
}
#endif