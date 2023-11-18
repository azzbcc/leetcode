// 给你一个下标从 0 开始的数组 nums ，数组中的元素都是 正 整数。请你选出两个下标 i 和 j（i != j），
// 且 nums[i] 的数位和与 nums[j] 的数位和相等。
//
// 请你找出所有满足条件的下标 i 和 j ，找出并返回 nums[i] + nums[j] 可以得到的 最大值 。
//
//
//
// 示例 1：
//
//
// 输入：nums = [18,43,36,13,7]
// 输出：54
// 解释：满足条件的数对 (i, j) 为：
// - (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
// - (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
// 所以可以获得的最大和是 54 。
//
// 示例 2：
//
//
// 输入：nums = [10,12,19,14]
// 输出：-1
// 解释：不存在满足条件的数对，返回 -1 。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10⁵
// 1 <= nums[i] <= 10⁹
//
//
// Related Topics 数组 哈希表 排序 堆（优先队列） 👍 34 👎 0

typedef struct {
    int sum;
    int d[2], c;
    UT_hash_handle hh;
} *hash_t;
int sum(int n) {
    int ans = 0;
    for (; n; ans += n % 10, n /= 10) {}
    return ans;
}
void sort_swap(int arr[]) {
    for (int tmp = arr[0]; tmp > arr[1]; arr[0] = arr[1], arr[1] = tmp) {}
}
int maximumSum(int *nums, int size) {
    int ans     = -1;
    hash_t hash = NULL, cur, next;
    for (int i = 0, d; i < size; ++i) {
        d = sum(nums[i]);
        HASH_FIND_INT(hash, &d, cur);
        if (!cur) {
            cur = malloc(sizeof(*cur)), cur->sum = d, cur->c = 0;
            HASH_ADD_INT(hash, sum, cur);
        }
        if (cur->c < 2) {
            cur->d[cur->c++] = nums[i];
            if (cur->c > 1) sort_swap(cur->d);
        } else if (nums[i] > cur->d[0]) {
            cur->d[0] = nums[i];
            sort_swap(cur->d);
        }
    }
    HASH_ITER(hh, hash, cur, next) {
        if (cur->c > 1) ans = fmax(ans, cur->d[0] + cur->d[1]);
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
