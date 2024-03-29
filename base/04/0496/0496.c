// 给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
//
// 请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。
//
// nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。
//
//
//
// 示例 1:
//
//
// 输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
// 输出: [-1,3,-1]
// 解释:
//     对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
//     对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
//     对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
//
// 示例 2:
//
//
// 输入: nums1 = [2,4], nums2 = [1,2,3,4].
// 输出: [3,-1]
// 解释:
//     对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
//     对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
//
//
//
//
// 提示：
//
//
// 1 <= nums1.length <= nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 10⁴
// nums1和nums2中所有整数 互不相同
// nums1 中的所有整数同样出现在 nums2 中
//
//
//
//
// 进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？
// Related Topics 栈 数组 哈希表 单调栈 👍 556 👎 0

#define MAXN 1000
typedef struct {
    int key, val;
    UT_hash_handle hh;
} hash_t;
typedef struct {
    int top, data[MAXN];
} sstack_t;
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    sstack_t stack[1] = { -1 };
    hash_t *cur, *hash = NULL, nodes[nums2Size];
    int *ans = malloc((*returnSize = nums1Size) * sizeof(int));

    for (int i = nums2Size - 1; i >= 0; stack->data[++stack->top] = nums2[i--]) {
        for (; stack->top > -1 && nums2[i] > stack->data[stack->top]; stack->top--) {}
        nodes[i] = (hash_t) { nums2[i], stack->top > -1 ? stack->data[stack->top] : -1 };
        HASH_ADD_INT(hash, key, &nodes[i]);
    }
    for (int i = 0; i < nums1Size; ++i) {
        HASH_FIND_INT(hash, &nums1[i], cur);
        ans[i] = cur->val;
    }
    HASH_CLEAR(hh, hash);
    return ans;
}