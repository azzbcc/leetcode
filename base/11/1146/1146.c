// 实现支持下列接口的「快照数组」- SnapshotArray：
//
//
// SnapshotArray(int length) - 初始化一个与指定长度相等的 类数组 的数据结构。初始时，每个元素都等于 0。
// void set(index, val) - 会将指定索引 index 处的元素设置为 val。
// int snap() - 获取该数组的快照，并返回快照的编号 snap_id（快照号是调用 snap() 的总次数减去 1）。
// int get(index, snap_id) - 根据指定的 snap_id 选择快照，并返回该快照指定索引 index 的值。
//
//
//
//
// 示例：
//
// 输入：["SnapshotArray","set","snap","set","get"]
//      [[3],[0,5],[],[0,6],[0,0]]
// 输出：[null,null,0,null,5]
// 解释：
// SnapshotArray snapshotArr = new SnapshotArray(3); // 初始化一个长度为 3 的快照数组
// snapshotArr.set(0,5);  // 令 array[0] = 5
// snapshotArr.snap();  // 获取快照，返回 snap_id = 0
// snapshotArr.set(0,6);
// snapshotArr.get(0,0);  // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5
//
//
//
// 提示：
//
//
// 1 <= length <= 50000
// 题目最多进行50000 次set，snap，和 get的调用 。
// 0 <= index < length
// 0 <= snap_id < 我们调用 snap() 的总次数
// 0 <= val <= 10^9
//
//
// Related Topics 设计 数组 哈希表 二分查找 👍 151 👎 0

#if 0
#define DYNAMIC_ARRAY_SIZE 128
typedef struct {
    int *data;
    int length;
    int size, capacity;
} SnapshotArray;
SnapshotArray *snapshotArrayCreate(int length) {
    SnapshotArray *array = malloc(sizeof(SnapshotArray));
    array->length = length, array->size = 0, array->capacity = DYNAMIC_ARRAY_SIZE * 0x8;
    array->data = malloc(array->capacity * length * sizeof(int));
    memset(array->data, 0, array->length * sizeof(int));
    return array;
}
void snapshotArraySet(SnapshotArray *array, int index, int val) {
    array->data[array->size * array->length + index] = val;
}
int snapshotArraySnap(SnapshotArray *array) {
    if (array->size == array->capacity) {
        array->capacity += DYNAMIC_ARRAY_SIZE;
        array->data = realloc(array->data, array->capacity * array->length * sizeof(int));
    }
    memcpy(array->data + (array->size + 1) * array->length, array->data + array->size * array->length,
           array->length * sizeof(int));
    return array->size++;
}
int snapshotArrayGet(SnapshotArray *array, int index, int snap_id) {
    return array->data[snap_id * array->length + index];
}
void snapshotArrayFree(SnapshotArray *array) {
    free(array->data);
    free(array);
}
#else
#define DYNAMIC_ARRAY_SIZE 128
typedef struct {
    int snap, val;
} data_t;
typedef struct {
    data_t *data;
    int size, capacity;
} dynamic_array_t;
void dynamic_array_append(dynamic_array_t *da, data_t val) {
    if (da->size == da->capacity) da->data = realloc(da->data, (da->capacity += DYNAMIC_ARRAY_SIZE) * sizeof(data_t));
    da->data[da->size++] = val;
}
void dynamic_array_destroy(dynamic_array_t *da) {
    if (da) free(da->data);
}
typedef struct {
    int snap, length;
    dynamic_array_t array[];
} SnapshotArray;
SnapshotArray *snapshotArrayCreate(int length) {
    SnapshotArray *array = malloc(sizeof(SnapshotArray) + length * sizeof(dynamic_array_t));
    array->snap = 0, array->length = length;
    memset(array->array, 0, length * sizeof(dynamic_array_t));
    return array;
}
void snapshotArraySet(SnapshotArray *array, int index, int val) {
    dynamic_array_append(&array->array[index], (data_t) { array->snap, val });
}
int snapshotArraySnap(SnapshotArray *array) {
    return array->snap++;
}
int snapshotArrayGet(SnapshotArray *array, int index, int snap_id) {
    int l = 0, r = array->array[index].size - 1;
    for (int mid; l <= r;) {
        mid = (l + r) / 2;
        if (array->array[index].data[mid].snap <= snap_id) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r < 0 ? 0 : array->array[index].data[r].val;
}
void snapshotArrayFree(SnapshotArray *array) {
    for (int i = 0; i < array->length; dynamic_array_destroy(&array->array[i++])) {}
    free(array);
}
#endif