// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
// 示例 1:
//
// 输入: [1,2,3,4,5,6,7] 和 k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右旋转 1 步: [7,1,2,3,4,5,6]
// 向右旋转 2 步: [6,7,1,2,3,4,5]
// 向右旋转 3 步: [5,6,7,1,2,3,4]
//
//
// 示例 2:
//
// 输入: [-1,-100,3,99] 和 k = 2
// 输出: [3,99,-1,-100]
// 解释:
// 向右旋转 1 步: [99,-1,-100,3]
// 向右旋转 2 步: [3,99,-1,-100]
//
// 说明:
//
//
// 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
// 要求使用空间复杂度为 O(1) 的 原地 算法。
//
// Related Topics 数组
// 👍 814 👎 0

void swap(int *nums, int a, int b) {
    for (int tmp = nums[a]; tmp != nums[b]; nums[a] = nums[b], nums[b] = tmp) {}
}
#if 0
void left(int *nums, int size, int k);
void right(int *nums, int size, int k);
void left(int *nums, int size, int k) {
    if (!k) return;
    for (; size >= k * 2; nums += k, size -= k) {
        for (int i = 0; i < k; ++i) {
            swap(nums, i, i + k);
        }
    }
    right(nums, size, size - k);
}
void right(int *nums, int size, int k) {
    if (!k) return;
    for (; size >= k * 2; size -= k) {
        for (int i = 1; i <= k; ++i) {
            swap(nums, size - i - k, size - i);
        }
    }
    left(nums, size, size - k);
}
void rotate(int *nums, int size, int k) {
    if (k %= size, size / 2 > k) {
        right(nums, size, k);
    } else {
        left(nums, size, size - k);
    }
}
#elif 0
void rotate(int *nums, int size, int k) {
    int beg = 0, end = size, offset = k % size;
    if (!offset) return;

    bool forward = (end - beg) / 2 >= offset;
    if (!forward) offset = end - beg - offset;

    for (; offset; forward = !forward, offset = end - beg - offset) {
        if (forward) {
            for (; end - offset * 2 >= beg; end -= offset) {
                for (int i = 1; i <= offset; ++i) {
                    swap(nums, end - i - offset, end - i);
                }
            }
        } else {
            for (; beg + offset * 2 <= end; beg += offset) {
                for (int i = 0; i < offset; ++i) {
                    swap(nums, beg + i, beg + i + offset);
                }
            }
        }
    }
}
#else
void reverse(int *nums, int beg, int end) {
    for (; beg < end; beg++, end--) {
        swap(nums, beg, end);
    }
}
void rotate(int *nums, int size, int k) {
    reverse(nums, 0, size - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, size - 1);
}
#endif