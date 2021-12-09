// 给你一个下标从 0 开始的二维整数数组 pairs ，其中 pairs[i] = [starti, endi] 。如果 pairs 的一个重新排列，
// 满足对每一个下标 i （ 1 <= i < pairs.length ）都有 endi-1 == starti ，
// 那么我们就认为这个重新排列是 pairs 的一个 合法重新排列 。
//
// 请你返回 任意一个 pairs 的合法重新排列。
//
// 注意：数据保证至少存在一个 pairs 的合法重新排列。
//
//
//
// 示例 1：
//
//
// 输入：pairs = [[5,1],[4,5],[11,9],[9,4]]
// 输出：[[11,9],[9,4],[4,5],[5,1]]
// 解释：
// 输出的是一个合法重新排列，因为每一个 endi-1 都等于 starti 。
// end0 = 9 == 9 = start1
// end1 = 4 == 4 = start2
// end2 = 5 == 5 = start3
//
//
// 示例 2：
//
//
// 输入：pairs = [[1,3],[3,2],[2,1]]
// 输出：[[1,3],[3,2],[2,1]]
// 解释：
// 输出的是一个合法重新排列，因为每一个 endi-1 都等于 starti 。
// end0 = 3 == 3 = start1
// end1 = 2 == 2 = start2
// 重新排列后的数组 [[2,1],[1,3],[3,2]] 和 [[3,2],[2,1],[1,3]] 都是合法的。
//
//
// 示例 3：
//
//
// 输入：pairs = [[1,2],[1,3],[2,1]]
// 输出：[[1,2],[2,1],[1,3]]
// 解释：
// 输出的是一个合法重新排列，因为每一个 endi-1 都等于 starti 。
// end0 = 2 == 2 = start1
// end1 = 1 == 1 = start2
//
//
//
//
// 提示：
//
//
// 1 <= pairs.length <= 10⁵
// pairs[i].length == 2
// 0 <= starti, endi <= 10⁹
// starti != endi
// pairs 中不存在一模一样的数对。
// 至少 存在 一个合法的 pairs 重新排列。
//
// 👍 16 👎 0

#define DYNAMIC_ARRAY_SIZE 128

typedef struct {
    int size, capacity;
    int *data;
} dynamic_array_t;
void dynamic_array_init(dynamic_array_t *da) {
    da->size = 0, da->capacity = DYNAMIC_ARRAY_SIZE;
    da->data = malloc(da->capacity * sizeof(int));
}
void dynamic_array_append(dynamic_array_t *da, int val) {
    if (da->size == da->capacity) da->data = realloc(da->data, (da->capacity += DYNAMIC_ARRAY_SIZE) * sizeof(int));
    da->data[da->size++] = val;
}
void dynamic_array_destroy(dynamic_array_t *da) {
    free(da->data);
}
typedef struct {
    int key, in;
    dynamic_array_t edge[1];
    UT_hash_handle hh;
} * hash_t;
hash_t hash_find(hash_t t, int key) {
    hash_t cur;
    HASH_FIND_INT(t, &key, cur);
    return cur;
}
void pair_record(hash_t *t, int from, int to, int index) {
    hash_t find;
    if (!(find = hash_find(*t, from))) {
        find = malloc(sizeof(*find)), find->key = from, find->in = 0;
        dynamic_array_init(find->edge);
        HASH_ADD_INT(*t, key, find);
    }
    dynamic_array_append(find->edge, index);
    if (!(find = hash_find(*t, to))) {
        find = malloc(sizeof(*find)), find->key = to, find->in = 0;
        dynamic_array_init(find->edge);
        HASH_ADD_INT(*t, key, find);
    }
    find->in += 1;
}
void dfs(int **edge, hash_t t, int now, dynamic_array_t *res) {
    hash_t find = hash_find(t, now);
    if (!find) return;

    for (int pos; find->edge->size;) {
        pos = find->edge->data[--find->edge->size];
        dfs(edge, t, edge[pos][1], res);
    }
    dynamic_array_append(res, now);
}
int **validArrangement(int **pairs, int size, int *colSize, int *returnSize, int **returnColumnSizes) {
    hash_t hash = NULL, cur, next;
    for (int i = 0; i < size; ++i) {
        pair_record(&hash, pairs[i][0], pairs[i][1], i);
    }

    int start = hash->key;
    HASH_ITER(hh, hash, cur, next) {
        if (cur->in + 1 == cur->edge->size) {
            start = cur->key;
            break;
        }
    }

    dynamic_array_t res[1];
    dynamic_array_init(res);
    dfs(pairs, hash, start, res);

    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        dynamic_array_destroy(cur->edge);
        free(cur);
    }

    int **ans          = malloc((*returnSize = size) * sizeof(int *));
    *returnColumnSizes = malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i) {
        ans[i]    = malloc(((*returnColumnSizes)[i] = 2) * sizeof(int));
        ans[i][0] = res->data[size - i], ans[i][1] = res->data[size - i - 1];
    }
    dynamic_array_destroy(res);

    return ans;
}