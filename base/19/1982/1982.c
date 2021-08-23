// 存在一个未知数组需要你进行还原，给你一个整数 n 表示该数组的长度。另给你一个数组 sums ，由未知数组中全部 2ⁿ 个
// 子集的和 组成（子集中的元素没有 特定的顺序）。
//
// 返回一个长度为 n 的数组 ans 表示还原得到的未知数组。如果存在 多种 答案，只需返回其中 任意一个 。
//
// 如果可以由数组 arr 删除部分元素（也可能不删除或全删除）得到数组 sub ，那么数组 sub 就是数组 arr 的一个 子集 。sub
// 的元素之和就是 arr 的一个 子集的和 。一个空数组的元素之和为 0 。
//
// 注意：生成的测试用例将保证至少存在一个正确答案。
//
//
//
// 示例 1：
//
//
// 输入：n = 3, sums = [-3,-2,-1,0,0,1,2,3]
// 输出：[1,2,-3]
// 解释：[1,2,-3] 能够满足给出的子集的和：
// - []：和是 0
// - [1]：和是 1
// - [2]：和是 2
// - [1,2]：和是 3
// - [-3]：和是 -3
// - [1,-3]：和是 -2
// - [2,-3]：和是 -1
// - [1,2,-3]：和是 0
// 注意，[1,2,-3] 的任何排列和 [-1,-2,3] 的任何排列都会被视作正确答案。
//
//
// 示例 2：
//
//
// 输入：n = 2, sums = [0,0,0,0]
// 输出：[0,0]
// 解释：唯一的正确答案是 [0,0] 。
//
//
// 示例 3：
//
//
// 输入：n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
// 输出：[0,-1,4,5]
// 解释：[0,-1,4,5] 能够满足给出的子集的和。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 15
// sums.length == 2ⁿ
// -10⁴ <= sums[i] <= 10⁴
//
// 👍 15 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} * hash_t;
void hash_record(hash_t *t, int key) {
    hash_t cur = NULL;
    HASH_FIND_INT(*t, &key, cur);
    if (!cur) {
        cur = calloc(1, sizeof(*cur)), cur->key = key;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->count += 1;
}
typedef struct {
    int size;
    hash_t del;
    int *data;
} heap_t;
void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
void heap_adjust(heap_t *heap, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < heap->size && heap->data[new_pos] > heap->data[new_pos + 1]) new_pos += 1;
    if (new_pos < heap->size && heap->data[pos] > heap->data[new_pos]) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
void heap_del(heap_t *heap, int key) {
    hash_record(&heap->del, key);
}
void heap_pop(heap_t *heap) {
    swap(&heap->data[0], &heap->data[--heap->size]);
    heap_adjust(heap, 0);
}
int heap_top(heap_t *heap) {
    for (hash_t cur = NULL;; cur->count -= 1) {
        HASH_FIND_INT(heap->del, &heap->data[0], cur);
        if (!cur || !cur->count) return heap->data[0];
        heap_pop(heap);
    }
}
int *recoverArray(int n, int *sums, int size, int *returnSize) {
    hash_t cur, next;
    heap_t heap[1] = { size, NULL, sums };
    int min = sums[0], *ans = malloc((*returnSize = n) * sizeof(int));

    for (int i = 0; i < size; min = fmin(min, sums[i++])) {}
    for (int i = 0; i < size; sums[i++] -= min) {}
    for (int i = size / 2 - 1; i >= 0; heap_adjust(heap, i--)) {}

    heap_del(heap, 0);
    for (int i = 0; i < n; ++i) {
        ans[i] = heap_top(heap);
        for (int mask = 0; mask < 1 << i; ++mask) {
            int sn = ans[i];
            for (int j = 0; j < i; ++j) {
                if (mask & 1 << j) sn += ans[j];
            }
            heap_del(heap, sn);
        }
    }
    HASH_ITER(hh, heap->del, cur, next) {
        HASH_DEL(heap->del, cur);
        free(cur);
    }
    for (int mask = 0; mask < 1 << n; ++mask) {
        int s = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & 1 << i) s += ans[i];
        }
        if (s + min == 0) {
            for (int i = 0; i < n; ++i) {
                if (mask & 1 << i) ans[i] = -ans[i];
            }
            break;
        }
    }

    return ans;
}