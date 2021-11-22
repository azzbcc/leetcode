// 给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。
//
// 实现 Solution class:
//
//
// Solution(int[] nums) 使用整数数组 nums 初始化对象
// int[] reset() 重设数组到它的初始状态并返回
// int[] shuffle() 返回数组随机打乱后的结果
//
//
//
//
// 示例：
//
//
// 输入
// ["Solution", "shuffle", "reset", "shuffle"]
// [[[1, 2, 3]], [], [], []]
// 输出
// [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
//
// 解释
// Solution solution = new Solution([1, 2, 3]);
// solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
// solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
// solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 200
// -10⁶ <= nums[i] <= 10⁶
// nums 中的所有元素都是 唯一的
// 最多可以调用 5 * 10⁴ 次 reset 和 shuffle
//
// Related Topics 数组 数学 随机化 👍 202 👎 0

typedef struct {
    int size, *data, *shuffle;
} Solution;
Solution *solutionCreate(int *nums, int size) {
    Solution *s = malloc(sizeof(Solution));

    s->size    = size;
    s->data    = malloc(size * sizeof(int));
    s->shuffle = malloc(size * sizeof(int));
    memcpy(s->data, nums, size * sizeof(int));

    srand(time(NULL));

    return s;
}
int *solutionReset(Solution *solution, int *retSize) {
    *retSize = solution->size;
    return solution->data;
}
int *solutionShuffle(Solution *solution, int *retSize) {
    *retSize = solution->size;
    memcpy(solution->shuffle, solution->data, solution->size * sizeof(int));

    for (int i = solution->size - 1; i > 0; i--) {
        for (int r = rand() % (i + 1), tmp = solution->shuffle[r]; tmp != solution->shuffle[i];
             solution->shuffle[r] = solution->shuffle[i], solution->shuffle[i] = tmp) {}
    }

    return solution->shuffle;
}
void solutionFree(Solution *solution) {
    free(solution->data);
    free(solution->shuffle);
    free(solution);
}
