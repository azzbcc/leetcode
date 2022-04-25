// 给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。
//
// 注意：
// 数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。
//
// 示例:
//
//
// int[] nums = new int[] {1,2,3,3,3};
// Solution solution = new Solution(nums);
//
// // pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
// solution.pick(3);
//
// // pick(1) 应该返回 0。因为只有nums[0]等于1。
// solution.pick(1);
//
// Related Topics 水塘抽样 哈希表 数学 随机化 👍 188 👎 0

#define DYNAMIC_ARRAY_SIZE 0x80
typedef struct {
    int key, cur, size, capacity, *data;
    UT_hash_handle hh;
} Solution, *hash_t;
Solution *solutionCreate(int *nums, int size) {
    hash_t s = NULL, cur;
    for (int i = 0; i < size; ++i) {
        HASH_FIND_INT(s, &nums[i], cur);
        if (!cur) {
            cur = calloc(1, sizeof(Solution)), cur->key = nums[i];
            HASH_ADD_INT(s, key, cur);
        }
        if (cur->size == cur->capacity) {
            cur->data = realloc(cur->data, (cur->capacity += DYNAMIC_ARRAY_SIZE) * sizeof(int));
        }
        cur->data[cur->size++] = i;
    }
    return s;
}
int solutionPick(Solution *solution, int target) {
    hash_t cur;
    HASH_FIND_INT(solution, &target, cur);
    cur->cur = (cur->cur + 1) % cur->size;
    return cur->data[cur->cur];
}
void solutionFree(Solution *solution) {
    hash_t cur, next;
    HASH_ITER(hh, solution, cur, next) {
        HASH_DEL(solution, cur);
        free(cur->data);
        free(cur);
    }
}
