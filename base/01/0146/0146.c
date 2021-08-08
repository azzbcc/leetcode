// 运用你所掌握的数据结构，设计和实现一个 LRU (最近最少使用) 缓存机制 。
//
//
//
// 实现 LRUCache 类：
//
//
// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value)
// 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上
// 限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
//
//
//
//
//
//
// 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
//
//
//
// 示例：
//
//
// 输入
//  ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//  [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// 输出
//  [null, null, null, 1, null, -1, null, -1, 3, 4]
//
// 解释
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // 缓存是 {1=1}
// lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
// lRUCache.get(1);    // 返回 1
// lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
// lRUCache.get(2);    // 返回 -1 (未找到)
// lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
// lRUCache.get(1);    // 返回 -1 (未找到)
// lRUCache.get(3);    // 返回 3
// lRUCache.get(4);    // 返回 4
//
//
//
//
// 提示：
//
//
// 1 <= capacity <= 3000
// 0 <= key <= 3000
// 0 <= value <= 104
// 最多调用 3 * 104 次 get 和 put
//
// Related Topics 设计
// 👍 1221 👎 0

typedef struct node {
    int key, value;
    struct node *prev, *next;
    UT_hash_handle hh;
} hash_t, list_t;
typedef struct {
    hash_t *hash;
    list_t *list;
    int used, capacity;
} LRUCache;
static hash_t *hash_find(hash_t *t, int key) {
    hash_t *cur;
    HASH_FIND_INT(t, &key, cur);
    return cur;
}
static void list_append(list_t **l, list_t *node) {
    list_t *head = *l;
    if (!head) {
        *l = node, node->prev = node->next = node;
    } else if (node == head) {
        *l = head->next;
    } else if (node != head->prev) {
        if (node->next) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
        node->prev = head->prev, node->next = head;
        head->prev->next = node, head->prev = node;
    }
}
LRUCache *lRUCacheCreate(int capacity) {
    LRUCache *cache = malloc(sizeof(LRUCache));

    cache->hash = NULL, cache->list = NULL;
    cache->used = 0, cache->capacity = capacity;
    return cache;
}
int lRUCacheGet(LRUCache *cache, int key) {
    hash_t *cur = hash_find(cache->hash, key);
    if (!cur) return -1;
    list_append(&cache->list, cur);
    return cur->value;
}
void lRUCachePut(LRUCache *cache, int key, int value) {
    hash_t *cur = hash_find(cache->hash, key);
    if (!cur) {
        if (cache->used < cache->capacity) {
            cache->used++;
            cur = malloc(sizeof(list_t)), cur->prev = cur->next = NULL;
        } else {
            cur = cache->list;
            HASH_DEL(cache->hash, cur);
        }
        cur->key = key;
        HASH_ADD_INT(cache->hash, key, cur);
    }
    cur->value = value;
    list_append(&cache->list, cur);
}
void lRUCacheFree(LRUCache *cache) {
    hash_t *cur, *next;
    HASH_ITER(hh, cache->hash, cur, next) {
        HASH_DEL(cache->hash, cur);
        free(cur);
    }
    free(cache);
}