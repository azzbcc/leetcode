// 实现一个MyQueue类，该类用两个栈来实现一个队列。 示例： MyQueue queue = new MyQueue(); queue.push(1);
// queue.push(2); queue.peek();  // 返回 1 queue.pop();   // 返回 1 queue.empty(); // 返
// 回 false 说明： 你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size 和 is empty
// 操作是合法的。 你所使用的语言也许不支持栈。你可以使用 list 或者
// deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。 假设所有操作都是有效的
//（例如，一个空的队列不会调用 pop 或者 peek 操作）。 Related Topics 栈
// 👍 17 👎 0

#define INIT_SIZE 100
#define INCR_SIZE 10

typedef struct {
    int *base;
    int top;
    int size;
} * sstack_t;

sstack_t stack_create() {
    sstack_t stack = calloc(1, sizeof(*stack));

    stack->top  = -1;
    stack->size = INIT_SIZE;
    stack->base = calloc(INIT_SIZE, sizeof(int));

    return stack;
}

bool stack_empty(sstack_t s) {
    return s->top < 0;
}

void stack_push(sstack_t s, int val) {
    if (s->top == s->size) s->base = realloc(s->base, (s->size += INCR_SIZE) * sizeof(int));
    s->base[++s->top] = val;
}

int stack_pop(sstack_t s) {
    assert(s->top >= 0);
    return s->base[s->top--];
}

int stack_peek(sstack_t s) {
    assert(s->top >= 0);
    return s->base[s->top];
}

void stack_free(sstack_t s) {
    free(s->base);
    free(s);
}

typedef struct {
    sstack_t in;
    sstack_t out;
} MyQueue;

/** Initialize your data structure here. */
MyQueue *myQueueCreate() {
    MyQueue *queue = calloc(1, sizeof(MyQueue));

    queue->in  = stack_create();
    queue->out = stack_create();

    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue *queue, int x) {
    stack_push(queue->in, x);
}

static void myQueueMigrate(sstack_t from, sstack_t to) {
    if (!stack_empty(to)) return;

    while (!stack_empty(from)) {
        stack_push(to, stack_pop(from));
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue *queue) {
    myQueueMigrate(queue->in, queue->out);
    return stack_pop(queue->out);
}

/** Get the front element. */
int myQueuePeek(MyQueue *queue) {
    myQueueMigrate(queue->in, queue->out);
    return stack_peek(queue->out);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue *queue) {
    return stack_empty(queue->in) && stack_empty(queue->out);
}

void myQueueFree(MyQueue *queue) {
    stack_free(queue->in);
    stack_free(queue->out);
    free(queue);
}
