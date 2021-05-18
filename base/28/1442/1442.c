// 给你一个整数数组 arr 。
//
// 现需要从数组中取三个下标 i、j 和 k ，其中 (0 <= i < j <= k < arr.length) 。
//
// a 和 b 定义如下：
//
//
// a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
// b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
//
//
// 注意：^ 表示 按位异或 操作。
//
// 请返回能够令 a == b 成立的三元组 (i, j , k) 的数目。
//
//
//
// 示例 1：
//
// 输入：arr = [2,3,1,6,7]
// 输出：4
// 解释：满足题意的三元组分别是 (0,1,2), (0,2,2), (2,3,4) 以及 (2,4,4)
//
//
// 示例 2：
//
// 输入：arr = [1,1,1,1,1]
// 输出：10
//
//
// 示例 3：
//
// 输入：arr = [2,3]
// 输出：0
//
//
// 示例 4：
//
// 输入：arr = [1,3,5,7,9]
// 输出：3
//
//
// 示例 5：
//
// 输入：arr = [7,11,12,9,5,2,7,17,22]
// 输出：8
//
//
//
//
// 提示：
//
//
// 1 <= arr.length <= 300
// 1 <= arr[i] <= 10^8
//
// Related Topics 位运算 数组 数学
// 👍 92 👎 0

#if 0
int countTriplets(int *arr, int size) {
    int prefix[size + 1], ans = 0;

    prefix[0] = 0;
    for (int i = 0; i < size; ++i) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int ij = prefix[j] ^ prefix[i];
            for (int k = j; k < size; ++k) {
                int jk = prefix[j] ^ prefix[k + 1];
                ans += ij == jk;
            }
        }
    }

    return ans;
}
#elif 0
int countTriplets(int *arr, int size) {
    int prefix[size + 1], ans = 0;

    prefix[0] = 0;
    for (int i = 0; i < size; ++i) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }
    for (int i = 0; i < size; ++i) {
        for (int k = i + 1; k < size; ++k) {
            if (prefix[i] == prefix[k + 1]) ans += k - i;
        }
    }

    return ans;
}
#else
typedef struct {
    int key, count, last, ans;
    UT_hash_handle hh;
} * hash_t;
int hash_record(hash_t *t, int key, int index) {
    int ans    = 0;
    hash_t cur = NULL;
    HASH_FIND_INT(*t, &key, cur);
    if (!cur) {
        cur = calloc(1, sizeof(*cur)), cur->key = key;
        HASH_ADD_INT(*t, key, cur);
    } else {
        ans = cur->ans, cur->ans += cur->count * (index - cur->last - 1) + cur->count - 1;
    }
    cur->last = index, cur->count += 1;
    return ans;
}
int countTriplets(int *arr, int size) {
    int prefix = 0, ans = 0;
    hash_t hash = NULL, cur, next;

    hash_record(&hash, prefix, 0);
    for (int i = 0; i < size; ++i) {
        ans += hash_record(&hash, prefix ^= arr[i], i + 1);
    }
    HASH_ITER(hh, hash, cur, next) {
        ans += cur->ans;
        HASH_DEL(hash, cur);
        free(cur);
    }

    return ans;
}
#endif