// 公司共有 n 个项目和 m 个小组，每个项目要不无人接手，要不就由 m 个小组之一负责。
//
// group[i] 表示第 i 个项目所属的小组，如果这个项目目前无人接手，那么 group[i] 就等于
// -1。（项目和小组都是从零开始编号的）小组可能存在没有接手任何项目的情况。
//
// 请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：
//
//
// 同一小组的项目，排序后在列表中彼此相邻。
// 项目之间存在一定的依赖关系，我们用一个列表 beforeItems 来表示，其中 beforeItems[i] 表示在进行第 i 个项目前（位于第
// i个 项目左侧）应该完成的所有项目。
//
//
// 如果存在多个解决方案，只需要返回其中任意一个即可。如果没有合适的解决方案，就请返回一个 空列表 。
//
//
//
// 示例 1：
//
//
//
//
// 输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
// 输出：[6,3,4,1,5,2,0,7]
//
//
// 示例 2：
//
//
// 输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
// 输出：[]
// 解释：与示例 1 大致相同，但是在排序后的列表中，4 必须放在 6 的前面。
//
//
//
//
// 提示：
//
//
// 1 <= m <= n <= 3 * 104
// group.length == beforeItems.length == n
// -1 <= group[i] <= m - 1
// 0 <= beforeItems[i].length <= n - 1
// 0 <= beforeItems[i][j] <= n - 1
// i != beforeItems[i][j]
// beforeItems[i] 不含重复元素
//
// Related Topics 深度优先搜索 图 拓扑排序
// 👍 95 👎 0

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
    int key;
    union {
        int degree;
        dynamic_array_t array;
    };
    UT_hash_handle hh;
} hash_t;
void require_record(hash_t **table, int key, int val) {
    hash_t *cur = NULL;

    HASH_FIND_INT(*table, &key, cur);
    if (!cur) {
        cur      = malloc(sizeof(hash_t));
        cur->key = key;
        dynamic_array_init(&cur->array);
        HASH_ADD_INT(*table, key, cur);
    }
    dynamic_array_append(&cur->array, val);
}
hash_t *degree_find(hash_t **table, int key) {
    hash_t *cur = NULL;
    HASH_FIND_INT(*table, &key, cur);
    if (!cur) {
        cur      = malloc(sizeof(hash_t));
        cur->key = key, cur->degree = 0;
        HASH_ADD_INT(*table, key, cur);
    }
    return cur;
}

bool topological_sort(hash_t *degree, hash_t *require, int result[]) {
    hash_t *cur, *next, *tmp;
    int front = 0, rear = 0;

    HASH_ITER(hh, degree, cur, next) {
        if (!cur->degree) result[rear++] = cur->key;
    }
    for (int now; front < rear;) {
        now = result[front++];

        HASH_FIND_INT(require, &now, cur);
        if (!cur) continue;

        for (int i = 0; i < cur->array.size; ++i) {
            tmp = degree_find(&degree, cur->array.data[i]);
            if (--tmp->degree) continue;
            result[rear++] = tmp->key;
        }
    }
    return front == HASH_COUNT(degree);
}
int *sortItems(int n, int m, int *group, int groupSize, int **items, int itemSize, int *itemColSize, int *returnSize) {
    hash_t *cur, *next;
    int len = 0, *ans = malloc(n * sizeof(int));
    hash_t *groupDegree = NULL, *groupRequire = NULL, *curGroupDegree;
    hash_t *groupItemDegree[m], *groupItemRequire[m], *curGroupItemDegree;

    memset(groupItemDegree, 0, sizeof(groupItemDegree));
    memset(groupItemRequire, 0, sizeof(groupItemRequire));

#define GROUP(item) (group[item] != -1 ? n + group[item] : item)
    for (int i = 0; i < n; ++i) {
        curGroupDegree = degree_find(&groupDegree, GROUP(i));
        if (group[i] != -1) curGroupItemDegree = degree_find(&groupItemDegree[group[i]], i);
        for (int j = 0; j < itemColSize[i]; ++j) {
            if (group[i] != group[items[i][j]] || group[i] == -1) {
                require_record(&groupRequire, GROUP(items[i][j]), GROUP(i));
                curGroupDegree->degree += 1;
            } else {
                require_record(&groupItemRequire[group[i]], items[i][j], i);
                curGroupItemDegree->degree += 1;
            }
        }
    }
#undef GROUP

    // 对项目小组拓扑排序
    int result[HASH_COUNT(groupDegree)];
    if (!topological_sort(groupDegree, groupRequire, result)) goto end;

    // 对每一个小组拓扑排序
    for (int i = 0; i < HASH_COUNT(groupDegree); ++i) {
        if (result[i] < n) {
            if (group[result[i]] == -1) ans[len++] = result[i];
        } else {
            int curGroup = result[i] - n, groupItem[HASH_COUNT(groupItemDegree[curGroup])];
            if (!topological_sort(groupItemDegree[curGroup], groupItemRequire[curGroup], groupItem)) break;
            memcpy(ans + len, groupItem, sizeof(groupItem));
            len += HASH_COUNT(groupItemDegree[curGroup]);
        }
    }

end:
    HASH_ITER(hh, groupDegree, cur, next) {
        HASH_DEL(groupDegree, cur);
        free(cur);
    }
    HASH_ITER(hh, groupRequire, cur, next) {
        HASH_DEL(groupRequire, cur);
        dynamic_array_destroy(&cur->array);
        free(cur);
    }
    for (int i = 0; i < m; ++i) {
        HASH_ITER(hh, groupItemDegree[i], cur, next) {
            HASH_DEL(groupItemDegree[i], cur);
            free(cur);
        }
        HASH_ITER(hh, groupItemRequire[i], cur, next) {
            HASH_DEL(groupItemRequire[i], cur);
            dynamic_array_destroy(&cur->array);
            free(cur);
        }
    }

    *returnSize = len == n ? n : 0;
    return ans;
}
