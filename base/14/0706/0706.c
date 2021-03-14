// 不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
//
// 实现 MyHashMap 类：
//
//
// MyHashMap() 用空映射初始化对象
// void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值
// value 。 int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。 void remove(key)
// 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。
//
//
//
//
// 示例：
//
//
// 输入：
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
// [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
// 输出：
// [null, null, null, 1, -1, null, 1, null, -1]
//
// 解释：
// MyHashMap myHashMap = new MyHashMap();
// myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
// myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
// myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
// myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
// myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
// myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
// myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
// myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
//
//
//
//
// 提示：
//
//
// 0 <= key, value <= 106
// 最多调用 104 次 put、get 和 remove 方法
//
//
//
//
// 进阶：你能否不使用内置的 HashMap 库解决此问题？
// Related Topics 设计 哈希表
// 👍 155 👎 0

#define SIZE 9973

typedef struct node {
    int key, value;
    struct node *next;
} *node_t, *MyHashMap;

static uint32_t h(int key) {
    return key %= SIZE;
}
static void node_free(node_t l) {
    if (!l) return;
    node_free(l->next);
    free(l);
}
node_t hash_find(MyHashMap hash[], int key) {
    node_t cur = hash[h(key)];
    while (cur && cur->key < key) {
        cur = cur->next;
    }
    return cur && cur->key == key ? cur : NULL;
}
MyHashMap *myHashMapCreate() {
    return calloc(SIZE, sizeof(node_t));
}
void myHashMapPut(MyHashMap *hash, int key, int value) {
    node_t find = hash_find(hash, key);
    if (find) {
        find->value = value;
        return;
    }
    node_t cur = hash[h(key)], n = malloc(sizeof(*n));
    if (!cur || cur->key > key) {
        n->next = cur, hash[h(key)] = n;
    } else {
        while (cur->next && cur->next->key < key) {
            cur = cur->next;
        }
        n->next = cur->next, cur->next = n;
    }
    n->key = key, n->value = value;
}
int myHashMapGet(MyHashMap *hash, int key) {
    node_t find = hash_find(hash, key);
    return find ? find->value : -1;
}
void myHashMapRemove(MyHashMap *hash, int key) {
    node_t cur = hash[h(key)], del = NULL;
    if (!cur) return;
    if (cur->key == key) {
        del = cur, hash[h(key)] = del->next;
    } else {
        while (cur->next && cur->next->key < key) {
            cur = cur->next;
        }
        if (cur->next && cur->next->key == key) {
            del = cur->next, cur->next = del->next;
        }
    }
    if (del) free(del);
}
void myHashMapFree(MyHashMap *hash) {
    for (int i = 0; i < SIZE; ++i) {
        node_free(hash[i]);
    }
    free(hash);
}