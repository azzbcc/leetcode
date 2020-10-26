//给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
//
//
//
// 示例 1:
//
// 输入: [1,2,0]
//输出: 3
//
//
// 示例 2:
//
// 输入: [3,4,-1,1]
//输出: 2
//
//
// 示例 3:
//
// 输入: [7,8,9,11,12]
//输出: 1
//
//
//
//
// 提示：
//
// 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
// Related Topics 数组
// 👍 827 👎 0

void update(int *nums, int size, int index) {
    int old = nums[index];

    nums[index] = index + 1;
    if (old <= 0) return;
    if (old > size) return;
    if (old == index + 1) return;

    update(nums, size, old - 1);
}

int firstMissingPositive_1(int *nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > 0 && nums[i] <= numsSize) update(nums, numsSize, nums[i] - 1);
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1) return i + 1;
    }

    return numsSize + 1;
}

int firstMissingPositive_2(int *nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        for (int tmp = nums[i]; tmp > 0 && tmp <= numsSize && nums[tmp - 1] != tmp;) {
            nums[i] = nums[tmp - 1], nums[tmp - 1] = tmp, tmp = nums[i];
        }
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1) return i + 1;
    }

    return numsSize + 1;
}

int (*firstMissingPositive)(int *, int) = firstMissingPositive_2;
