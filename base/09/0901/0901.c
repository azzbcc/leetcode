// 设计一个算法收集某些股票的每日报价，并返回该股票当日价格的 跨度 。
//
// 当日股票价格的 跨度 被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。
//
//
// 例如，如果未来 7 天股票的价格是 [100,80,60,70,60,75,85]，那么股票跨度将是 [1,1,1,2,1,4,6] 。
//
//
// 实现 StockSpanner 类：
//
//
// StockSpanner() 初始化类对象。
// int next(int price) 给出今天的股价 price ，返回该股票当日价格的 跨度 。
//
//
//
//
// 示例：
//
//
// 输入：
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// 输出：
// [null, 1, 1, 1, 2, 1, 4, 6]
//
// 解释：
// stockSpanner stockSpanner = new StockSpanner();
// stockSpanner.next(100); // 返回 1
// stockSpanner.next(80);  // 返回 1
// stockSpanner.next(60);  // 返回 1
// stockSpanner.next(70);  // 返回 2
// stockSpanner.next(60);  // 返回 1
// stockSpanner.next(75);  // 返回 4 ，因为截至今天的最后 4 个股价 (包括今天的股价 75) 都小于或等于今天的股价。
// stockSpanner.next(85);  // 返回 6
//
//
//
//
// 提示：
//
//
// 1 <= price <= 10⁵
// 最多调用 next 方法 10⁴ 次
//
//
// Related Topics 栈 设计 数据流 单调栈 👍 367 👎 0

typedef struct __tag_node *list_t;
struct __tag_node {
    int price, index;
    list_t next;
};
typedef struct {
    int idx;
    list_t stack;
} StockSpanner;
StockSpanner *stockSpannerCreate() {
    StockSpanner *spanner = calloc(1, sizeof(StockSpanner));
    spanner->stack        = calloc(1, sizeof(*spanner->stack));
    spanner->stack->price = INT32_MAX, spanner->stack->index = -1;
    return spanner;
}
int stockSpannerNext(StockSpanner *spanner, int price) {
    list_t add = NULL;
    for (; price >= spanner->stack->price; add = spanner->stack, spanner->stack = add->next) {
        if (add) free(add);
    }
    if (!add) add = malloc(sizeof(*add));
    add->next = spanner->stack, spanner->stack = add;
    add->price = price, add->index = spanner->idx++;
    return add->index - add->next->index;
}
void stockSpannerFree(StockSpanner *spanner) {
    for (list_t now = spanner->stack, next; now; now = next) {
        next = now->next;
        free(now);
    }
    free(spanner);
}