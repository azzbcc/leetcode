// 请你设计并实现一个能够对其中的值进行跟踪的数据结构，并支持对频率相关查询进行应答。
//
// 实现 FrequencyTracker 类：
//
//
// FrequencyTracker()：使用一个空数组初始化 FrequencyTracker 对象。
// void add(int number)：添加一个 number 到数据结构中。
// void deleteOne(int number)：从数据结构中删除一个 number 。数据结构 可能不包含 number ，在这种情况下不删除任何内容。
// bool hasFrequency(int frequency): 如果数据结构中存在出现 frequency 次的数字，则返回 true，否则返回 false。
//
//
//
//
// 示例 1：
//
//
// 输入
// ["FrequencyTracker", "add", "add", "hasFrequency"]
// [[], [3], [3], [2]]
// 输出
// [null, null, null, true]
//
// 解释
// FrequencyTracker frequencyTracker = new FrequencyTracker();
// frequencyTracker.add(3); // 数据结构现在包含 [3]
// frequencyTracker.add(3); // 数据结构现在包含 [3, 3]
// frequencyTracker.hasFrequency(2); // 返回 true ，因为 3 出现 2 次
//
//
// 示例 2：
//
//
// 输入
// ["FrequencyTracker", "add", "deleteOne", "hasFrequency"]
// [[], [1], [1], [1]]
// 输出
// [null, null, null, false]
//
// 解释
// FrequencyTracker frequencyTracker = new FrequencyTracker();
// frequencyTracker.add(1); // 数据结构现在包含 [1]
// frequencyTracker.deleteOne(1); // 数据结构现在为空 []
// frequencyTracker.hasFrequency(1); // 返回 false ，因为数据结构为空
//
//
// 示例 3：
//
//
// 输入
// ["FrequencyTracker", "hasFrequency", "add", "hasFrequency"]
// [[], [2], [3], [1]]
// 输出
// [null, false, null, true]
//
// 解释
// FrequencyTracker frequencyTracker = new FrequencyTracker();
// frequencyTracker.hasFrequency(2); // 返回 false ，因为数据结构为空
// frequencyTracker.add(3); // 数据结构现在包含 [3]
// frequencyTracker.hasFrequency(1); // 返回 true ，因为 3 出现 1 次
//
//
//
//
// 提示：
//
//
// 1 <= number <= 10⁵
// 1 <= frequency <= 10⁵
// 最多调用 add、deleteOne 和 hasFrequency 共计 2 * 10⁵ 次
//
//
// Related Topics 设计 哈希表 👍 34 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} *hash_t;
hash_t hash_find(hash_t t, int key) {
    hash_t find = NULL;
    HASH_FIND_INT(t, &key, find);
    return find;
}
bool hash_exist(hash_t t, int key) {
    hash_t find = hash_find(t, key);
    return find && find->count > 0;
}
int hash_record(hash_t *t, int key, int plus) {
    hash_t cur = hash_find(*t, key);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->key = key, cur->count = 0;
        HASH_ADD_INT(*t, key, cur);
    }
    return cur->count += plus;
}
void hash_destroy(hash_t *t) {
    hash_t cur, next;
    HASH_ITER(hh, *t, cur, next) {
        HASH_DEL(*t, cur);
        free(cur);
    }
}
typedef struct {
    hash_t freq, record;
} FrequencyTracker;
FrequencyTracker *frequencyTrackerCreate() {
    return calloc(1, sizeof(FrequencyTracker));
}
void frequencyTrackerAdd(FrequencyTracker *tracker, int number) {
    int new = hash_record(&tracker->record, number, 1);
    hash_record(&tracker->freq, new, 1);
    if (new > 1) hash_record(&tracker->freq, new - 1, -1);
}
void frequencyTrackerDeleteOne(FrequencyTracker *tracker, int number) {
    if (!hash_exist(tracker->record, number)) return;
    int new = hash_record(&tracker->record, number, -1);
    if (new > 0) hash_record(&tracker->freq, new, 1);
    hash_record(&tracker->freq, new + 1, -1);
}
bool frequencyTrackerHasFrequency(FrequencyTracker *tracker, int frequency) {
    return hash_exist(tracker->freq, frequency);
}
void frequencyTrackerFree(FrequencyTracker *tracker) {
    hash_destroy(&tracker->freq);
    hash_destroy(&tracker->record);
    free(tracker);
}