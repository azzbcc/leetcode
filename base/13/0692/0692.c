// 给一非空的单词列表，返回前 k 个出现次数最多的单词。
//
// 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
//
// 示例 1：
//
//
// 输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// 输出: ["i", "love"]
// 解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//    注意，按字母顺序 "i" 在 "love" 之前。
//
//
//
//
// 示例 2：
//
//
// 输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// 输出: ["the", "is", "sunny", "day"]
// 解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
//     出现次数依次为 4, 3, 2 和 1 次。
//
//
//
//
// 注意：
//
//
// 假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
// 输入的单词均由小写字母组成。
//
//
//
//
// 扩展练习：
//
//
// 尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。
//
// Related Topics 堆 字典树 哈希表
// 👍 329 👎 0

typedef struct {
    char *str;
    int count;
    UT_hash_handle hh;
} * hash_t, node_t;
int cmp(node_t *a, node_t *b) {
    if (a->count == b->count) return strcmp(a->str, b->str);
    return b->count - a->count;
}
void swap(node_t data[], int a, int b) {
    if (a == b) return;
    node_t tmp = data[a];
    data[a] = data[b], data[b] = tmp;
}
void heap_adjust(node_t data[], int size, int pos) {
    int l = 2 * pos + 1, r = 2 * pos + 2, new_pos = pos;
    if (l < size && cmp(&data[new_pos], &data[l]) < 0) new_pos = l;
    if (r < size && cmp(&data[new_pos], &data[r]) < 0) new_pos = r;
    if (new_pos != pos) {
        swap(data, pos, new_pos);
        heap_adjust(data, size, new_pos);
    }
}
char **topKFrequent(char **words, int size, int k, int *returnSize) {
    int count = 0;
    node_t data[size];
    hash_t hash = NULL, cur;
    char **ans  = malloc((*returnSize = k) * sizeof(char *));
    for (int i = 0; i < size; ++i) {
        HASH_FIND_STR(hash, words[i], cur);
        if (!cur) {
            cur = &data[count++], cur->str = words[i], cur->count = 0;
            HASH_ADD_STR(hash, str, cur);
        }
        cur->count += 1;
    }
    HASH_CLEAR(hh, hash);
    for (int i = k / 2 - 1; i >= 0; heap_adjust(data, k, i--)) {}
    for (int i = k; i < count; ++i) {
        if (cmp(&data[i], data) >= 0) continue;
        data[0] = data[i];
        heap_adjust(data, k, 0);
    }
    for (int i = k - 1; i >= 0; --i) {
        ans[i] = data->str, data[0] = data[i];
        heap_adjust(data, i, 0);
    }
    return ans;
}