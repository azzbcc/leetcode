// 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],
//
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//
// 返回锯齿形层序遍历如下：
//
//
// [
//  [3],
//  [20,9],
//  [15,7]
// ]
//
// Related Topics 栈 树 广度优先搜索
// 👍 328 👎 0

#define MAXN      0x100
#define INIT_SIZE 0x100
#define INCR_SIZE 0x10

typedef struct {
    int top, size;
    void *base[];
} * stack_t;
stack_t stack_create() {
    stack_t stack = malloc(sizeof(*stack) + INIT_SIZE * sizeof(void *));
    stack->top = -1, stack->size = INIT_SIZE;
    return stack;
}
int stack_size(stack_t s) {
    return s->top + 1;
}
void stack_push(stack_t *stack, void *val) {
    stack_t s = *stack;
    if (++s->top >= s->size) *stack = s = realloc(s, sizeof(*s) + (s->size += INCR_SIZE) * sizeof(void *));
    s->base[s->top] = val;
}
void *stack_pop(stack_t s) {
    assert(s->top >= 0);
    return s->base[s->top--];
}
void stack_free(stack_t s) {
    free(s);
}
int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    int len = 0, **ans = malloc(MAXN * sizeof(int *));
    stack_t s[2] = { stack_create(), stack_create() };

    if (root) stack_push(&s[0], root);
    *returnColumnSizes = malloc(MAXN * sizeof(int));

    for (int cur = 0, size = stack_size(s[0]); size; len++, cur = 1 - cur, size = stack_size(s[cur])) {
        (*returnColumnSizes)[len] = size, ans[len] = malloc(size * sizeof(int));
        for (struct TreeNode *now; size--;) {
            now = stack_pop(s[cur]);
            if (cur) {
                if (now->left) stack_push(&s[1 - cur], now->left);
                if (now->right) stack_push(&s[1 - cur], now->right);
            } else {
                if (now->right) stack_push(&s[1 - cur], now->right);
                if (now->left) stack_push(&s[1 - cur], now->left);
            }
            ans[len][size] = now->val;
        }
    }

    stack_free(s[0]);
    stack_free(s[1]);
    *returnSize = len;

    return ans;
}
