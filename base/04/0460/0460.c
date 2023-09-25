// 请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。
//
// 实现 LFUCache 类：
//
//
// LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
// int get(int key) - 如果键 key 存在于缓存中，则获取键的值，否则返回 -1 。
// void put(int key, int value) - 如果键 key 已存在，则变更其值；如果键不存在，请插入键值对。
// 当缓存达到其容量capacity 时，则应该在插入新项之前，移除最不经常使用的项。在此问题中，
// 当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最近最久未使用 的键。
//
//
// 为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。
//
// 当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put
// 操作，使用计数器的值将会递增。
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
//
//
//
// 示例：
//
//
// 输入：
// ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
// 输出：
// [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
//
// 解释：
// // cnt(x) = 键 x 的使用计数
// // cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
// LFUCache lfu = new LFUCache(2);
// lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
// lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
// lfu.get(1);      // 返回 1
//                  // cache=[1,2], cnt(2)=1, cnt(1)=2
// lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
//                  // cache=[3,1], cnt(3)=1, cnt(1)=2
// lfu.get(2);      // 返回 -1（未找到）
// lfu.get(3);      // 返回 3
//                  // cache=[3,1], cnt(3)=2, cnt(1)=2
// lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
//                  // cache=[4,3], cnt(4)=1, cnt(3)=2
// lfu.get(1);      // 返回 -1（未找到）
// lfu.get(3);      // 返回 3
//                  // cache=[3,4], cnt(4)=1, cnt(3)=3
// lfu.get(4);      // 返回 4
//                  // cache=[3,4], cnt(4)=2, cnt(3)=3
//
//
//
// 提示：
//
//
// 1 <= capacity <= 10⁴
// 0 <= key <= 10⁵
// 0 <= value <= 10⁹
// 最多调用 2 * 10⁵ 次 get 和 put 方法
//
//
// Related Topics 设计 哈希表 链表 双向链表 👍 730 👎 0

typedef struct node {
    int key, value, freq;
    struct node *prev, *next;
    UT_hash_handle hh;
} *hash_node_t, *list_t;
typedef struct {
    int freq;
    list_t list;
    UT_hash_handle hh;
} *hash_freq_t;
typedef struct {
    int min_freq;
    hash_node_t hash;
    hash_freq_t freq;
    int used, capacity;
} LFUCache;
static hash_node_t hash_node_find(hash_node_t t, int key) {
    hash_node_t cur;
    HASH_FIND_INT(t, &key, cur);
    return cur;
}
static hash_freq_t hash_freq_find(hash_freq_t t, int key) {
    hash_freq_t cur;
    HASH_FIND_INT(t, &key, cur);
    return cur;
}
LFUCache *lFUCacheCreate(int capacity) {
    LFUCache *cache = calloc(1, sizeof(LFUCache));
    cache->capacity = capacity;
    return cache;
}
static void list_append(list_t *l, list_t node) {
    list_t head = *l;
    if (!head) {
        *l = node, node->prev = node->next = node;
    } else {
        node->prev = head->prev, node->next = head;
        head->prev->next = node, head->prev = node;
    }
}
static list_t list_remove(list_t *l, list_t node) {
    if (*l == node) *l = node == node->next ? NULL : node->next;
    node->next->prev = node->prev, node->prev->next = node->next;
    node->prev = node->next = NULL;
    return node;
}
static void freq_append(LFUCache *cache, list_t cur) {
    // 找到待插入表
    hash_freq_t freq = hash_freq_find(cache->freq, cur->freq);
    if (!freq) {
        freq = calloc(1, sizeof(*freq)), freq->freq = cur->freq;
        HASH_ADD_INT(cache->freq, freq, freq);
    }
    list_append(&freq->list, cur);
}
static void freq_remove(LFUCache *cache, list_t cur) {
    // 从旧频率表删除
    hash_freq_t freq = hash_freq_find(cache->freq, cur->freq);
    // 从链表删除该节点
    list_remove(&freq->list, cur);
    if (!freq->list) {
        if (cache->min_freq == cur->freq) cache->min_freq += 1;
        // 只有一个最小频率节点
        HASH_DEL(cache->freq, freq);
        free(freq);
    }
}
int lFUCacheGet(LFUCache *cache, int key) {
    hash_node_t cur = hash_node_find(cache->hash, key);
    if (!cur) return -1;

    freq_remove(cache, cur);
    cur->freq++;
    freq_append(cache, cur);

    return cur->value;
}
void lFUCachePut(LFUCache *cache, int key, int value) {
    hash_node_t cur = hash_node_find(cache->hash, key);
    if (cur) {
        // 更新值
        cur->value = value;
        lFUCacheGet(cache, key);
    } else {
        // 能否扩容
        if (cache->used < cache->capacity) {
            // 可以直接扩容
            cache->used++;
            cur = calloc(1, sizeof(*cur));
        } else {
            // 查找最小频率节点
            hash_freq_t freq = hash_freq_find(cache->freq, cache->min_freq);
            // 从链表删除该节点，并返回删除节点
            freq_remove(cache, cur = freq->list);
            HASH_DEL(cache->hash, cur);
        }
        // 加入纪录表
        cur->key = key, cur->value = value, cur->freq = cache->min_freq = 1;
        HASH_ADD_INT(cache->hash, key, cur);
        freq_append(cache, cur);
    }
}
void lFUCacheFree(LFUCache *cache) {
    hash_freq_t freq_cur, freq_next;
    hash_node_t node_cur, node_next;
    HASH_ITER(hh, cache->freq, freq_cur, freq_next) {
        HASH_DEL(cache->freq, freq_cur);
        free(freq_cur);
    }
    HASH_ITER(hh, cache->hash, node_cur, node_next) {
        HASH_DEL(cache->hash, node_cur);
        free(node_cur);
    }
    free(cache);
}