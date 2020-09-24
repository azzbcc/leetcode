// 给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。
//
// （例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）
//
// 返回 A 中好子数组的数目。
//
//
//
// 示例 1：
//
// 输入：A = [1,2,1,2,3], K = 2
// 输出：7
// 解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
//
//
// 示例 2：
//
// 输入：A = [1,2,1,3,4], K = 3
// 输出：3
// 解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
//
//
//
//
// 提示：
//
//
// 1 <= A.length <= 20000
// 1 <= A[i] <= A.length
// 1 <= K <= A.length
//
// Related Topics 哈希表 双指针 Sliding Window
// 👍 111 👎 0
#define SIZE 9973
typedef struct node {
    int val;
    int count;
    struct node *next;
} node_t, *hash_t[SIZE];
static uint32_t h(int val) {
    return val % SIZE;
}
static node_t *hash_find(hash_t t, int val) {
    node_t *cur = t[h(val)];
    while (cur && cur->val < val) {
        cur = cur->next;
    }
    if (!cur || cur->val > val) return NULL;
    return cur;
}
static bool hash_add(hash_t t, node_t *n) {
    node_t *cur = t[h(n->val)];
    if (!cur || cur->val > n->val) {
        n->next = cur, t[h(n->val)] = n;
    } else if (cur->val == n->val) {
        cur->count++;
        return false;
    } else {
        while (cur->next && cur->next->val < n->val) {
            cur = cur->next;
        }
        if (cur->next && cur->next->val == n->val) {
            cur->next->count++;
            return false;
        } else {
            n->next = cur->next, cur->next = n;
        }
    }
    return true;
}
static node_t *hash_del(hash_t t, int val) {
    node_t *tmp, *cur = t[h(val)];
    if (!cur || cur->val > val) return NULL;
    if (cur->val == val) {
        t[h(val)] = cur->next;
    } else {
        while (cur->next && cur->next->val < val) {
            cur = cur->next;
        }
        if (!cur->next || cur->next->val != val) return NULL;
        tmp = cur->next, cur->next = cur->next->next, cur = tmp;
    }
    return cur;
}
int subarraysWithKDistinct(int *A, int ASize, int K) {
    node_t nodes[K];
    hash_t hash = { NULL };
    int max = 0, min, sum = 0, len;

    // 初始化以当前下标结尾的子串最大长度与最小长度
    for (len = 0; len < K && max < ASize; ++max) {
        nodes[len].val = A[max], nodes[len].count = 1;
        if (hash_add(hash, &nodes[len])) len++;
    }
    if (len < K) return 0;
    for (min = max; min > K; min--) {
        node_t *tmp = hash_find(hash, A[max - min]);
        if (tmp->count == 1) break;
        tmp->count--;
    }
    sum += max - min + 1;

    for (int i = max; i < ASize; ++i) {
        node_t *tmp = hash_find(hash, A[i]);
        if (!tmp) {
            tmp = hash_del(hash, A[i - min]);
            max = min, tmp->val = A[i];
        } else {
            max++, min++;
        }
        for (hash_add(hash, tmp); min > K; min--) {
            tmp = hash_find(hash, A[i - min + 1]);
            if (tmp->count == 1) break;
            tmp->count--;
        }

        sum += max - min + 1;
    }

    return sum;
}
