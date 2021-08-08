// 给你一个按升序排序的整数数组
// num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。
//
// 如果可以完成上述分割，则返回 true ；否则，返回 false 。
//
//
//
// 示例 1：
//
// 输入: [1,2,3,3,4,5]
// 输出: True
// 解释:
// 你可以分割出这样两个连续子序列 :
// 1, 2, 3
// 3, 4, 5
//
//
//
//
// 示例 2：
//
// 输入: [1,2,3,3,4,4,5,5]
// 输出: True
// 解释:
// 你可以分割出这样两个连续子序列 :
// 1, 2, 3, 4, 5
// 3, 4, 5
//
//
//
//
// 示例 3：
//
// 输入: [1,2,3,4,4,5]
// 输出: False
//
//
//
//
// 提示：
//
//
// 输入的数组长度范围为 [1, 10000]
//
//
//
// Related Topics 堆 贪心算法
// 👍 183 👎 0

#if 0
static int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
bool isPossible(int *nums, int numsSize) {
    int len = 0, cur = 0;
    int lengths[numsSize];

    lengths[0] = 1, cur = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] == nums[i - 1]) {
            if (cur >= len) lengths[cur] = 0;
            lengths[cur++]++;
            continue;
        }
        if (cur < len && lengths[cur] < 3) return false;
        if (nums[i] == nums[i - 1] + 1) {
            qsort(lengths, cur, sizeof(int), cmp);
            lengths[0] += 1, len = cur, cur = 1;
        } else {
            for (int j = 0; j < cur; ++j) {
                if (lengths[j] < 3) return false;
            }
            lengths[0] = 1, len = 0, cur = 1;
        }
    }
    if (cur > len) return false;
    if (cur < len && lengths[cur] < 3) return false;
    for (int i = 0; i < cur; ++i) {
        if (lengths[i] < 3) return false;
    }
    return true;
}
#else
int min(int a, int b) {
    return a < b ? a : b;
}
bool isPossible(int *nums, int numsSize) {
    int l1 = 0, l2 = 0;
    for (int i = 0, c, ln = 0; i < numsSize; i += c) {
        for (c = 1; i + c < numsSize && nums[i + c] == nums[i]; ++c) {}
        if (i && nums[i] > nums[i - 1] + 1) {
            if (l1 + l2 > 0) return false;
            l1 = c, l2 = ln = 0;
        } else {
            if (l1 + l2 > c) return false;
            int left = c - l1 - l2, new = min(left, ln);
            ln = l2 + new, l2 = l1, l1 = left - new;
        }
    }
    return l1 + l2 == 0;
}
#endif