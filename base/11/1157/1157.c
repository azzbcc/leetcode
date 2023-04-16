// 设计一个数据结构，有效地找到给定子数组的 多数元素 。
//
// 子数组的 多数元素 是在子数组中出现 threshold 次数或次数以上的元素。
//
// 实现 MajorityChecker 类:
//
//
// MajorityChecker(int[] arr) 会用给定的数组 arr 对 MajorityChecker 初始化。
// int query(int left, int right, int threshold) 返回子数组中的元素 arr[left...right]
// 至少出现 threshold 次数，如果不存在这样的元素则返回 -1。
//
//
//
//
// 示例 1：
//
//
// 输入:
// ["MajorityChecker", "query", "query", "query"]
// [[[1, 1, 2, 2, 1, 1]], [0, 5, 4], [0, 3, 3], [2, 3, 2]]
// 输出：
// [null, 1, -1, 2]
//
// 解释：
// MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
// majorityChecker.query(0,5,4); // 返回 1
// majorityChecker.query(0,3,3); // 返回 -1
// majorityChecker.query(2,3,2); // 返回 2
//
//
//
//
// 提示：
//
//
// 1 <= arr.length <= 2 * 10⁴
// 1 <= arr[i] <= 2 * 10⁴
// 0 <= left <= right < arr.length
// threshold <= right - left + 1
// 2 * threshold > right - left + 1
// 调用 query 的次数最多为 10⁴
//
//
// Related Topics 设计 树状数组 线段树 数组 二分查找 👍 103 👎 0

#define MAXN 200
typedef struct {
    int key, count;
    UT_hash_handle hh;
} *hash_t;
typedef struct {
    int size;
    int data[];
} *array_t;
typedef struct {
    int key;
    array_t index;
} node_t;
typedef struct {
    int count;
    array_t arr;
    node_t check[MAXN];
} MajorityChecker;
MajorityChecker *majorityCheckerCreate(int *arr, int size) {
    MajorityChecker *checker = malloc(sizeof(MajorityChecker));
    checker->count = 0, checker->arr = malloc(sizeof(array_t) + size * sizeof(int)), checker->arr->size = size;
    memcpy(checker->arr->data, arr, size * sizeof(int));
    if (size < MAXN) return checker;

    hash_t cur, next, hash = NULL;
    for (int i = 0; i < size; ++i, ++cur->count) {
        HASH_FIND_INT(hash, &arr[i], cur);
        if (cur) continue;
        cur = calloc(1, sizeof(*cur)), cur->key = arr[i];
        HASH_ADD_INT(hash, key, cur);
    }
    HASH_ITER(hh, hash, cur, next) {
        if (cur->count < MAXN / 2) continue;
        array_t new = malloc(sizeof(array_t) + cur->count * sizeof(int));
        new->size   = 0;
        for (int i = 0; i < size; ++i) {
            if (cur->key == arr[i]) new->data[new->size++] = i;
        }
        checker->check[checker->count++] = (node_t) { cur->key, new };
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return checker;
}
int moore_query(array_t arr, int left, int right, int threshold) {
    int ans = -1;
    for (int i = left, c = 0; i <= right; ++i) {
        if (arr->data[i] == ans) {
            c++;
        } else if (c) {
            c--;
        } else {
            ans = arr->data[i], c = 1;
        }
    }
    for (int i = left, c = 0; i <= right; ++i) {
        c += ans == arr->data[i];
        if (c >= threshold) return ans;
    }
    return -1;
}
int search(array_t array, int key) {
    int l = 0, r = array->size - 1;
    for (int mid; l <= r;) {
        mid = (l + r) / 2;
        if (array->data[mid] >= key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int count(array_t array, int left, int right) {
    int l = search(array, left), r = search(array, right);
    return r - l + (r >= 0 && r < array->size && array->data[r] == right);
}
int majorityCheckerQuery(MajorityChecker *checker, int left, int right, int threshold) {
    if (right - left < MAXN) return moore_query(checker->arr, left, right, threshold);
    for (int i = 0; i < checker->count; ++i) {
        if (count(checker->check[i].index, left, right) >= threshold) return checker->check[i].key;
    }
    return -1;
}
void majorityCheckerFree(MajorityChecker *checker) {
    for (int i = 0; i < checker->count; ++i) {
        free(checker->check[i].index);
    }
    free(checker->arr);
    free(checker);
}