// 设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。
//
// 注意: 允许出现重复元素。
//
//
// insert(val)：向集合中插入元素 val。
// remove(val)：当 val 存在时，从集合中移除一个 val。
// getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。
//
//
// 示例:
//
// // 初始化一个空的集合。
// RandomizedCollection collection = new RandomizedCollection();
//
//// 向集合中插入 1 。返回 true 表示集合不包含 1 。
// collection.insert(1);
//
//// 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
// collection.insert(1);
//
//// 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
// collection.insert(2);
//
//// getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
// collection.getRandom();
//
//// 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
// collection.remove(1);
//
//// getRandom 应有相同概率返回 1 和 2 。
// collection.getRandom();
//
// Related Topics 设计 数组 哈希表
// 👍 137 👎 0

#define DYNAMIC_ARRAY_SIZE 128

typedef struct {
    int *data;
    int size, capacity;
} dynamic_array_t;
dynamic_array_t *dynamic_array_init() {
    dynamic_array_t *da = malloc(sizeof(dynamic_array_t));
    da->size = 0, da->capacity = DYNAMIC_ARRAY_SIZE;
    da->data = malloc(da->capacity * sizeof(int));
    return da;
}
void dynamic_array_destroy(dynamic_array_t *da) {
    free(da->data);
    free(da);
}
int dynamic_array_append(dynamic_array_t *da, int val) {
    if (da->size == da->capacity) da->data = realloc(da->data, (da->capacity += DYNAMIC_ARRAY_SIZE) * sizeof(int));
    da->data[da->size] = val;
    return da->size++;
}
int dynamic_array_random(dynamic_array_t *da) {
    return da->data[rand() % da->size];
}
int dynamic_array_pop(dynamic_array_t *da) {
    return da->data[--da->size];
}
int dynamic_array_size(dynamic_array_t *da) {
    return da->size;
}
void dynamic_array_set(dynamic_array_t *da, int index, int val) {
    da->data[index] = val;
}

typedef struct {
    int index;
    UT_hash_handle hh;
} hash_index_t;
void hash_index_add(hash_index_t **t, int val) {
    hash_index_t *index = malloc(sizeof(hash_index_t));
    index->index        = val;
    HASH_ADD_INT(*t, index, index);
}
int hash_index_pop(hash_index_t **t) {
    int ans             = (*t)->index;
    hash_index_t *index = *t;
    HASH_DEL(*t, index);
    free(index);
    return ans;
}
void hash_index_remove(hash_index_t **t, int val) {
    hash_index_t *index = NULL;
    HASH_FIND_INT(*t, &val, index);
    HASH_DEL(*t, index);
    free(index);
}

typedef struct {
    int key;
    hash_index_t *index_hash;
    UT_hash_handle hh;
} hash_t;
hash_t *hash_new(int key, int val) {
    hash_t *h = malloc(sizeof(hash_t));
    h->key = key, h->index_hash = NULL;

    hash_index_add(&h->index_hash, val);
    return h;
}
void hash_destroy(hash_t *h) {
    for (hash_index_t *cur = h->index_hash; cur; cur = h->index_hash) {
        HASH_DEL(h->index_hash, cur);
        free(cur);
    }
    free(h);
}

typedef struct {
    hash_t *hash;
    dynamic_array_t *array;
} RandomizedCollection;

/** Initialize your data structure here. */

RandomizedCollection *randomizedCollectionCreate() {
    RandomizedCollection *collection = malloc(sizeof(RandomizedCollection));

    collection->hash  = NULL;
    collection->array = dynamic_array_init();

    return collection;
}

/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
bool randomizedCollectionInsert(RandomizedCollection *collection, int val) {
    hash_t *cur = NULL;

    int index = dynamic_array_append(collection->array, val);
    HASH_FIND_INT(collection->hash, &val, cur);
    if (cur) {
        hash_index_add(&cur->index_hash, index);
        return false;
    } else {
        cur = hash_new(val, index);
        HASH_ADD_INT(collection->hash, key, cur);
        return true;
    }
}

/** Removes a value from the collection. Returns true if the collection contained the specified element. */
bool randomizedCollectionRemove(RandomizedCollection *collection, int val) {
    hash_t *cur = NULL;

    HASH_FIND_INT(collection->hash, &val, cur);
    if (!cur) return false;

    // 获取待移除下标
    int index = hash_index_pop(&cur->index_hash);
    // 获取数组最后一位下标
    int index_remove = dynamic_array_size(collection->array) - 1;
    // 需要处理得数据
    int val_change = dynamic_array_pop(collection->array);

    if (index != index_remove) {
        hash_t *change = NULL;

        // 设置数据新位置
        dynamic_array_set(collection->array, index, val_change);

        // 修改哈希表记录
        HASH_FIND_INT(collection->hash, &val_change, change);
        hash_index_add(&change->index_hash, index);
        hash_index_remove(&change->index_hash, index_remove);
    }

    if (HASH_COUNT(cur->index_hash) == 0) {
        HASH_DEL(collection->hash, cur);
        hash_destroy(cur);
    }

    return true;
}

/** Get a random element from the collection. */
int randomizedCollectionGetRandom(RandomizedCollection *collection) {
    return dynamic_array_random(collection->array);
}

void randomizedCollectionFree(RandomizedCollection *collection) {
    dynamic_array_destroy(collection->array);
    for (hash_t *cur = collection->hash; cur; cur = collection->hash) {
        HASH_DEL(collection->hash, cur);
        hash_destroy(cur);
    }
    free(collection);
}