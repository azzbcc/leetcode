// 给定一个无重复元素的有序整数数组 nums 。
//
// 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表。也就是说，nums
// 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 num s 的数字 x 。
//
// 列表中的每个区间范围 [a,b] 应该按如下格式输出：
//
//
// "a->b" ，如果 a != b
// "a" ，如果 a == b
//
//
//
//
// 示例 1：
//
//
// 输入：nums = [0,1,2,4,5,7]
// 输出：["0->2","4->5","7"]
// 解释：区间范围是：
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"
//
//
// 示例 2：
//
//
// 输入：nums = [0,2,3,4,6,8,9]
// 输出：["0","2->4","6","8->9"]
// 解释：区间范围是：
// [0,0] --> "0"
// [2,4] --> "2->4"
// [6,6] --> "6"
// [8,9] --> "8->9"
//
//
// 示例 3：
//
//
// 输入：nums = []
// 输出：[]
//
//
// 示例 4：
//
//
// 输入：nums = [-1]
// 输出：["-1"]
//
//
// 示例 5：
//
//
// 输入：nums = [0]
// 输出：["0"]
//
//
//
//
// 提示：
//
//
// 0 <= nums.length <= 20
// -231 <= nums[i] <= 231 - 1
// nums 中的所有值都 互不相同
// nums 按升序排列
//
// Related Topics 数组
// 👍 85 👎 0

char **summaryRanges(int *nums, int size, int *returnSize) {
    char buffer[25], **ans = malloc(size * (sizeof(char *)));

    if (*returnSize = 0, !size) return ans;
    for (int i = 0, beg = *nums; i < size; ++i) {
        if (i + 1 == size || nums[i] + 1 != nums[i + 1]) {
            if (beg != nums[i]) {
                sprintf(buffer, "%d->%d", beg, nums[i]);
            } else {
                sprintf(buffer, "%d", beg);
            }
            ans[(*returnSize)++] = strdup(buffer);
            if (i + 1 < size) beg = nums[i + 1];
        }
    }

    return ans;
}
