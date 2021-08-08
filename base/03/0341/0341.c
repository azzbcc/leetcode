// 给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
//
// 列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。
//
//
//
// 示例 1:
//
// 输入: [[1,1],2,[1,1]]
// 输出: [1,1,2,1,1]
// 解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
//
// 示例 2:
//
// 输入: [1,[4,[6]]]
// 输出: [1,4,6]
// 解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。
//
// Related Topics 栈 设计
// 👍 253 👎 0

#define INIT_SIZE 0x100
#define INCR_SIZE 0x10

typedef struct NestedIterator {
    int top, size;
    struct NestedInteger **data;
} iter_t;
static void stack_push(iter_t *iter, struct NestedInteger *val) {
    if (++iter->top >= iter->size) {
        iter->size += INCR_SIZE;
        iter->data = realloc(iter->data, iter->size * sizeof(struct NestedInteger *));
    }
    iter->data[iter->top] = val;
}
static void stack_format(struct NestedIterator *iter) {
    if (iter->top == -1 || NestedIntegerIsInteger(iter->data[iter->top])) return;

    struct NestedInteger *top = iter->data[iter->top--], **list = NestedIntegerGetList(top);
    for (int i = NestedIntegerGetListSize(top) - 1; i >= 0; --i) {
        stack_push(iter, list[i]);
    }
    return stack_format(iter);
}
struct NestedIterator *nestedIterCreate(struct NestedInteger **list, int size) {
    iter_t *iter = malloc(sizeof(iter_t));

    iter->top = -1, iter->size = INIT_SIZE;
    iter->data = malloc(INIT_SIZE * sizeof(struct NestedInteger *));

    for (int i = size - 1; i >= 0; --i) {
        stack_push(iter, list[i]);
    }
    return iter;
}
bool nestedIterHasNext(struct NestedIterator *iter) {
    stack_format(iter);
    return iter->top > -1;
}
int nestedIterNext(struct NestedIterator *iter) {
    stack_format(iter);
    return NestedIntegerGetInteger(iter->data[iter->top--]);
}
void nestedIterFree(struct NestedIterator *iter) {
    free(iter->data);
    free(iter);
}
