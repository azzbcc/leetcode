//给定一个整数数组，判断是否存在重复元素。
//
// 如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
//
//
//
// 示例 1:
//
// 输入: [1,2,3,1]
// 输出: true
//
// 示例 2:
//
// 输入: [1,2,3,4]
// 输出: false
//
// 示例 3:
//
// 输入: [1,1,1,3,3,4,3,2,4,2]
// 输出: true

// Related Topics 数组 哈希表
// 👍 317 👎 0

#if 0
typedef struct {
    int num;
    UT_hash_handle hh;
} node_t, *hash_t;
bool containsDuplicate(int *nums, int numsSize) {
    if (!numsSize) return false;

    bool ans = false;
    node_t nodes[numsSize];
    hash_t hash = NULL, tmp;

    for (int i = 0; !ans && i < numsSize; ++i) {
        HASH_FIND_INT(hash, &nums[i], tmp);
        if (tmp) {
            ans = true;
        } else {
            nodes[i].num = nums[i];
            HASH_ADD_INT(hash, num, &nodes[i]);
        }
    }

    HASH_CLEAR(hh, hash);
    return ans;
}
#elif 0
static int cmp(const void *a, const void *b) {
    return *( int * )a < *( int * )b ? -1 : 1;
}
bool containsDuplicate(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] == nums[i - 1]) return true;
    }

    return false;
}
#else
#define SIZE 9973

typedef struct node {
    int val;
    struct node *next;
} node_t;
typedef node_t *hash_t[SIZE];

static uint32_t h(int val) {
    val %= SIZE;
    if (val < 0) val += SIZE;
    return val;
}
static bool hash_add(hash_t t, node_t *n) {
    node_t *cur = t[h(n->val)];
    if (!cur || cur->val > n->val) {
        n->next = cur, t[h(n->val)] = n;
    } else if (cur->val == n->val) {
        return false;
    } else {
        while (cur->next && cur->next->val < n->val) {
            cur = cur->next;
        }
        if (cur->next && cur->next->val == n->val) {
            return false;
        } else {
            n->next = cur->next, cur->next = n;
        }
    }
    return true;
}
bool containsDuplicate(int *nums, int numsSize) {
    if (!numsSize) return false;

    hash_t hash = { NULL };
    node_t nodes[numsSize];

    for (int i = 0; i < numsSize; ++i) {
        nodes[i] = (node_t) { nums[i] };
        if (!hash_add(hash, &nodes[i])) return true;
    }
    return false;
}
#endif
