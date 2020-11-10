// 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//
// 必须原地修改，只允许使用额外常数空间。
//
// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
// Related Topics 数组
// 👍 601 👎 0

#if 0
void nextPermutation(int *nums, int numsSize) {
    for (int pos = --numsSize - 1; pos >= 0; --pos) {
        int tmp = nums[pos];
        if (tmp >= nums[numsSize]) {
            for (int i = pos; i < numsSize; ++i) {
                nums[i] = nums[i + 1];
            }
            nums[numsSize] = tmp;
        } else {
            while (nums[--numsSize] > tmp) {}
            nums[pos]          = nums[numsSize + 1];
            nums[numsSize + 1] = tmp;
            return;
        }
    }
}
#else
void nextPermutation(int *nums, int numsSize) {
    int found = numsSize - 2;
    for (; found >= 0 && nums[found] >= nums[found + 1]; found--) {}
    if (found >= 0) {
        int item = numsSize - 1, tmp;
        for (int beg = found + 1, mid; beg <= item;) {
            mid = (beg + item) / 2;
            if (nums[mid] > nums[found]) {
                beg = mid + 1;
            } else {
                item = mid - 1;
            }
        }
        tmp = nums[item], nums[item] = nums[found], nums[found] = tmp;
    }
    for (int beg = found + 1, end = numsSize - 1, tmp; beg < end; beg++, end--) {
        tmp = nums[beg], nums[beg] = nums[end], nums[end] = tmp;
    }
}
#endif