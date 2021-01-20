// 给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
//
// 示例 1:
//
//
// 输入: [1,2,3]
// 输出: 6
//
//
// 示例 2:
//
//
// 输入: [1,2,3,4]
// 输出: 24
//
//
// 注意:
//
//
// 给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
// 输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。
//
// Related Topics 数组 数学
// 👍 230 👎 0

#if 0
int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int maximumProduct(int *nums, int size) {
    qsort(nums, size, sizeof(int), cmp);
    return max(nums[0] * nums[1] * nums[size - 1], nums[size - 2] * nums[size - 3] * nums[size - 1]);
}
#elif 0
int max(int a, int b) {
    return a > b ? a : b;
}
bool gt(int a, int b) {
    return a > b;
}
bool lt(int a, int b) {
    return a < b;
}
void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
void heap_adjust(int *nums, int pos, int size, bool (*operator)(int, int)) {
    if (pos * 2 + 1 < size && operator(nums[pos], nums[pos * 2 + 1])) {
        swap(&nums[pos], &nums[pos * 2 + 1]);
        heap_adjust(nums, pos * 2 + 1, size, operator);
    }
    if (pos * 2 + 2 < size && operator(nums[pos], nums[pos * 2 + 2])) {
        swap(&nums[pos], &nums[pos * 2 + 2]);
        heap_adjust(nums, pos * 2 + 2, size, operator);
    }
}
void heap_sort(int *nums, int size, bool (*operator)(int, int), int res[], int count) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heap_adjust(nums, i, size, operator);
    }
    for (int i = 0; i < count && i < size; ++i) {
        res[i] = nums[0];
        swap(&nums[0], &nums[size - i - 1]);
        heap_adjust(nums, 0, size - i - 1, operator);
    }
}
int maximumProduct(int *nums, int size) {
    int sg[3], sl[2];
    heap_sort(nums, size, lt, sg, 3);
    heap_sort(nums, size, gt, sl, 2);

    return max(sg[0] * sg[1] * sg[2], sg[0] * sl[0] * sl[1]);
}
#else
void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
int max(int a, int b) {
    return a > b ? a : b;
}
int maximumProduct(int *nums, int size) {
    int sg[3], sl[2];
    memcpy(sg, nums, 3 * sizeof(int));
    memcpy(sl, nums, 2 * sizeof(int));

    if (sg[0] > sg[1]) swap(&sg[0], &sg[1]);
    if (sg[0] > sg[2]) swap(&sg[0], &sg[2]);
    if (sl[0] < sl[1]) swap(&sl[0], &sl[1]);
    if (sl[0] > nums[2]) {
        sl[0] = nums[2];
        if (sl[0] < sl[1]) swap(&sl[0], &sl[1]);
    }
    for (int i = 3; i < size; ++i) {
        if (sg[0] < nums[i]) {
            sg[0] = nums[i];
            if (sg[0] > sg[1]) swap(&sg[0], &sg[1]);
            if (sg[0] > sg[2]) swap(&sg[0], &sg[2]);
        }
        if (sl[0] > nums[i]) {
            sl[0] = nums[i];
            if (sl[0] < sl[1]) swap(&sl[0], &sl[1]);
        }
    }

    return max(sg[0] * sg[1] * sg[2], max(sg[1], sg[2]) * sl[0] * sl[1]);
}
#endif