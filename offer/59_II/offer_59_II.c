// 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front
// 的均摊时间复杂度都是O(1)。
//
// 若队列为空，pop_front 和 max_value 需要返回 -1
//
// 示例 1：
//
// 输入:
// ["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
// [[],[1],[2],[],[],[]]
// 输出: [null,null,null,2,1,2]
//
//
// 示例 2：
//
// 输入:
// ["MaxQueue","pop_front","max_value"]
// [[],[],[]]
// 输出: [null,-1,-1]
//
//
//
//
// 限制：
//
//
// 1 <= push_back,pop_front,max_value的总操作数 <= 10000
// 1 <= value <= 10^5
//
// Related Topics 设计 队列 单调队列 👍 283 👎 0

typedef struct item {
    int val;
    struct item *next, **prev;
} item_t;
typedef struct {
    item_t *first, **last;
} MaxQueue;
static void queue_push(MaxQueue *q, item_t *item) {
    item->next = NULL, item->prev = q->last, *q->last = item, q->last = &item->next;
}
static int queue_pop(MaxQueue *q) {
    item_t *first = q->first;

    int ans  = first->val;
    q->first = first->next, first->next ? (first->next->prev = first->prev) : (q->last = first->prev);
    free(first);

    return ans;
}
MaxQueue *maxQueueCreate() {
    MaxQueue *q = calloc(2, sizeof(MaxQueue));
    q[0].last = &q[0].first, q[1].last = &q[1].first;
    return q;
}
int maxQueueMax_value(MaxQueue *queue) {
    return queue[1].first ? queue[1].first->val : -1;
}
void maxQueuePush_back(MaxQueue *queue, int val) {
    item_t *item0 = malloc(sizeof(item_t)), *item1 = malloc(sizeof(item_t));

    item0->val = item1->val = val;
    for (item_t *last; last = *(( MaxQueue * )queue[1].last)->last, last && last->val < val;) {
        queue[1].last = last->prev, *last->prev = last->next;
        free(last);
    }
    queue_push(&queue[0], item0);
    queue_push(&queue[1], item1);
}
int maxQueuePop_front(MaxQueue *queue) {
    if (!queue->first) return -1;
    int ans = queue_pop(queue);
    if (ans == maxQueueMax_value(queue)) queue_pop(&queue[1]);
    return ans;
}
void maxQueueFree(MaxQueue *queue) {
    for (; queue[0].first; queue_pop(&queue[0])) {}
    for (; queue[1].first; queue_pop(&queue[1])) {}
    free(queue);
}