// 给你一支股票价格的数据流。数据流中每一条记录包含一个 时间戳 和该时间点股票对应的 价格 。
//
// 不巧的是，由于股票市场内在的波动性，股票价格记录可能不是按时间顺序到来的。某些情况下，有的记录可能是错的。
// 如果两个有相同时间戳的记录出现在数据流中，前一条记录视为错误记录，后出现的记录 更正 前一条错误的记录。
//
// 请你设计一个算法，实现：
//
//
// 更新 股票在某一时间戳的股票价格，如果有之前同一时间戳的价格，这一操作将 更正 之前的错误价格。
// 找到当前记录里 最新股票价格 。最新股票价格 定义为时间戳最晚的股票价格。
// 找到当前记录里股票的 最高价格 。
// 找到当前记录里股票的 最低价格 。
//
//
// 请你实现 StockPrice 类：
//
//
// StockPrice() 初始化对象，当前无股票价格记录。
// void update(int timestamp, int price) 在时间点 timestamp 更新股票价格为 price 。
// int current() 返回股票 最新价格 。
// int maximum() 返回股票 最高价格 。
// int minimum() 返回股票 最低价格 。
//
//
//
//
// 示例 1：
//
// 输入：
// ["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
// [[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
// 输出：
// [null, null, null, 5, 10, null, 5, null, 2]
//
// 解释：
// stockPrice stockPrice = new StockPrice();
// stockPrice.update(1, 10); // 时间戳为 [1] ，对应的股票价格为 [10] 。
// stockPrice.update(2, 5);  // 时间戳为 [1,2] ，对应的股票价格为 [10,5] 。
// stockPrice.current();     // 返回 5 ，最新时间戳为 2 ，对应价格为 5 。
// stockPrice.maximum();     // 返回 10 ，最高价格的时间戳为 1 ，价格为 10 。
// stockPrice.update(1, 3);  // 之前时间戳为 1 的价格错误，价格更新为 3 。
//                          // 时间戳为 [1,2] ，对应股票价格为 [3,5] 。
// stockPrice.maximum();     // 返回 5 ，更正后最高价格为 5 。
// stockPrice.update(4, 2);  // 时间戳为 [1,2,4] ，对应价格为 [3,5,2] 。
// stockPrice.minimum();     // 返回 2 ，最低价格时间戳为 4 ，价格为 2 。
//
//
//
//
// 提示：
//
//
// 1 <= timestamp, price <= 10⁹
// update，current，maximum 和 minimum 总 调用次数不超过 10⁵ 。
// current，maximum 和 minimum 被调用时，update 操作 至少 已经被调用过 一次 。
//
//
// Related Topics 设计 哈希表 数据流 有序集合 堆（优先队列） 👍 157 👎 0

typedef struct {
    int key, val;
    UT_hash_handle hh;
} *hash_t;
static hash_t hash_find(hash_t t, int key) {
    hash_t find = NULL;
    HASH_FIND_INT(t, &key, find);
    return find;
}
static void hash_record(hash_t *t, int key, int val) {
    hash_t find = hash_find(*t, key);
    if (!find) {
        find = calloc(1, sizeof(*find)), find->key = key;
        HASH_ADD_INT(*t, key, find);
    }
    find->val = val;
}
static void hash_destroy(hash_t t) {
    hash_t cur, next;
    HASH_ITER(hh, t, cur, next) {
        HASH_DEL(t, cur);
        free(cur);
    }
}

typedef struct {
    bool (*cmp)(int a, int b);
    int size;
    hash_t del;
    int data[];
} *heap_t;
static bool max(int a, int b) {
    return a > b;
}
static bool min(int a, int b) {
    return a < b;
}
static void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
static heap_t heap_init(int capacity, bool (*cmp)(int, int)) {
    heap_t ans = malloc(sizeof(*ans) + capacity * sizeof(int));
    ans->size = 0, ans->cmp = cmp, ans->del = NULL;
    return ans;
}
static void heap_adjust(heap_t heap, int pos) {
    int new_pos = pos;
    if (2 * pos + 1 < heap->size && !heap->cmp(heap->data[new_pos], heap->data[2 * pos + 1])) new_pos = 2 * pos + 1;
    if (2 * pos + 2 < heap->size && !heap->cmp(heap->data[new_pos], heap->data[2 * pos + 2])) new_pos = 2 * pos + 2;
    if (new_pos != pos) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
static void heap_add(heap_t heap, int val) {
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->cmp(heap->data[parent], heap->data[pos])) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
static void heap_pop(heap_t heap) {
    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
}
static void heap_del(heap_t heap, int val) {
    hash_t find = hash_find(heap->del, val);
    if (!find) {
        hash_record(&heap->del, val, 1);
    } else {
        find->val += 1;
    }
}
static int heap_top(heap_t heap) {
    for (hash_t find = NULL;; find->val -= 1) {
        find = hash_find(heap->del, heap->data[0]);
        if (!find || !find->val) return heap->data[0];
        heap_pop(heap);
    }
}
static void heap_destroy(heap_t heap) {
    hash_destroy(heap->del);
    free(heap);
}

#define N 100000
typedef struct {
    int max_timestamp;
    hash_t hash;
    heap_t min, max;
} StockPrice;
StockPrice *stockPriceCreate() {
    StockPrice *stock = calloc(1, sizeof(StockPrice));
    stock->min        = heap_init(N, min);
    stock->max        = heap_init(N, max);
    return stock;
}
void stockPriceUpdate(StockPrice *stock, int timestamp, int price) {
    hash_t find = hash_find(stock->hash, timestamp);
    if (find) {
        heap_del(stock->min, find->val);
        heap_del(stock->max, find->val);
        find->val = price;
    } else {
        hash_record(&stock->hash, timestamp, price);
    }
    heap_add(stock->min, price);
    heap_add(stock->max, price);
    stock->max_timestamp = fmax(stock->max_timestamp, timestamp);
}
int stockPriceCurrent(StockPrice *stock) {
    hash_t find = hash_find(stock->hash, stock->max_timestamp);
    return find->val;
}
int stockPriceMaximum(StockPrice *stock) {
    return heap_top(stock->max);
}
int stockPriceMinimum(StockPrice *stock) {
    return heap_top(stock->min);
}
void stockPriceFree(StockPrice *stock) {
    heap_destroy(stock->min);
    heap_destroy(stock->max);
    hash_destroy(stock->hash);
    free(stock);
}