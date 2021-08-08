// 不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
//
// 实现 MyHashSet 类：
//
//
// void add(key) 向哈希集合中插入值 key 。
// bool contains(key) 返回哈希集合中是否存在这个值 key 。
// void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
//
//
//
// 示例：
//
//
// 输入：
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
// [[], [1], [2], [1], [3], [2], [2], [2], [2]]
// 输出：
// [null, null, null, true, false, null, true, null, false]
//
// 解释：
// MyHashSet myHashSet = new MyHashSet();
// myHashSet.add(1);      // set = [1]
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(1); // 返回 True
// myHashSet.contains(3); // 返回 False ，（未找到）
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(2); // 返回 True
// myHashSet.remove(2);   // set = [1]
// myHashSet.contains(2); // 返回 False ，（已移除）
//
//
//
// 提示：
//
//
// 0 <= key <= 106
// 最多调用 104 次 add、remove 和 contains 。
//
//
//
//
// 进阶：你可以不使用内建的哈希集合库解决此问题吗？
// Related Topics 设计 哈希表
// 👍 123 👎 0

#define SIZE 9973

typedef struct node {
    int key;
    struct node *next;
} *node_t, *MyHashSet;

static uint32_t h(int key) {
    return key %= SIZE;
}
static void node_free(node_t l) {
    if (!l) return;
    node_free(l->next);
    free(l);
}
MyHashSet *myHashSetCreate() {
    return calloc(SIZE, sizeof(node_t));
}
bool myHashSetContains(MyHashSet *hash, int key) {
    node_t cur = hash[h(key)];
    while (cur && cur->key < key) {
        cur = cur->next;
    }
    return cur && cur->key == key;
}
void myHashSetAdd(MyHashSet hash[], int key) {
    if (myHashSetContains(hash, key)) return;

    node_t cur = hash[h(key)], n = malloc(sizeof(*n));
    if (!cur || cur->key > key) {
        n->next = cur, hash[h(key)] = n;
    } else {
        while (cur->next && cur->next->key < key) {
            cur = cur->next;
        }
        n->next = cur->next, cur->next = n;
    }
    n->key = key;
}
void myHashSetRemove(MyHashSet *hash, int key) {
    if (!myHashSetContains(hash, key)) return;

    node_t cur = hash[h(key)], del;
    if (cur->key == key) {
        del = cur, hash[h(key)] = cur->next;
    } else {
        while (cur->next->key < key) {
            cur = cur->next;
        }
        del = cur->next, cur->next = del->next;
    }
    free(del);
}
void myHashSetFree(MyHashSet *hash) {
    for (int i = 0; i < SIZE; ++i) {
        node_free(hash[i]);
    }
    free(hash);
}