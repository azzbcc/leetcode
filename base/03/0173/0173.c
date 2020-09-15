// 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
//
// 调用 next() 将返回二叉搜索树中的下一个最小的数。
//
//
//
// 示例：
//
//
//
// BSTIterator iterator = new BSTIterator(root);
// iterator.next();    // 返回 3
// iterator.next();    // 返回 7
// iterator.hasNext(); // 返回 true
// iterator.next();    // 返回 9
// iterator.hasNext(); // 返回 true
// iterator.next();    // 返回 15
// iterator.hasNext(); // 返回 true
// iterator.next();    // 返回 20
// iterator.hasNext(); // 返回 false
//
//
//
// 提示：
//
//
// next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。
// 你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 中至少存在一个下一个最小的数。
//
// Related Topics 栈 树 设计
// 👍 248 👎 0
#define INIT_SIZE 100
#define INCR_SIZE 10

typedef struct {
    void **base;
    int top;
    int size;
} * stack_t;

stack_t stack_create() {
    stack_t stack = calloc(1, sizeof(*stack));

    stack->top  = -1;
    stack->size = INIT_SIZE;
    stack->base = calloc(INIT_SIZE, sizeof(void *));

    return stack;
}

bool stack_empty(stack_t s) {
    return s->top < 0;
}

void stack_push(stack_t s, void *val) {
    if (s->top == s->size) s->base = realloc(s->base, (s->size += INCR_SIZE) * sizeof(void *));
    s->base[++s->top] = val;
}

void *stack_pop(stack_t s) {
    assert(s->top >= 0);
    return s->base[s->top--];
}

void stack_free(stack_t s) {
    free(s->base);
    free(s);
}

typedef struct {
    stack_t stack;
} BSTIterator;

BSTIterator *bSTIteratorCreate(struct TreeNode *root) {
    BSTIterator *iter = calloc(1, sizeof(*iter));

    iter->stack = stack_create();
    while (root) {
        stack_push(iter->stack, root);
        root = root->left;
    }

    return iter;
}

int bSTIteratorNext(BSTIterator *iter) {
    struct TreeNode *top = stack_pop(iter->stack);
    for (struct TreeNode *tmp = top->right; tmp; tmp = tmp->left) {
        stack_push(iter->stack, tmp);
    }

    return top->val;
}

bool bSTIteratorHasNext(BSTIterator *iter) {
    return !stack_empty(iter->stack);
}

void bSTIteratorFree(BSTIterator *iter) {
    stack_free(iter->stack);
    free(iter);
}
