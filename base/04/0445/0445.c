// 给你两个 非空
// 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//
//
//
// 示例1：
//
//
//
//
// 输入：l1 = [7,2,4,3], l2 = [5,6,4]
// 输出：[7,8,0,7]
//
//
// 示例2：
//
//
// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[8,0,7]
//
//
// 示例3：
//
//
// 输入：l1 = [0], l2 = [0]
// 输出：[0]
//
//
//
//
// 提示：
//
//
// 链表的长度范围为 [1, 100]
// 0 <= node.val <= 9
// 输入数据保证链表代表的数字无前导 0
//
//
//
//
// 进阶：如果输入链表不能翻转该如何解决？
//
// Related Topics 栈 链表 数学 👍 646 👎 0

#define MAXN 100
typedef struct {
    int top, data[MAXN];
} stack_t;
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    stack_t s1 = { 0 }, s2 = { 0 };
    struct ListNode *head = NULL, *tmp;
    for (; l1; s1.data[s1.top++] = l1->val, l1 = l1->next) {}
    for (; l2; s2.data[s2.top++] = l2->val, l2 = l2->next) {}
    for (int val = 0; val || s1.top || s2.top; head = tmp, val /= 10) {
        if (s1.top) val += s1.data[--s1.top];
        if (s2.top) val += s2.data[--s2.top];
        tmp = malloc(sizeof(*tmp)), tmp->val = val % 10, tmp->next = head;
    }
    return head;
}