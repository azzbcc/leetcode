// 给你一个链表的头节点 head 。
//
// 移除每个右侧有一个更大数值的节点。
//
// 返回修改后链表的头节点 head 。
//
//
//
// 示例 1：
//
//
//
//
// 输入：head = [5,2,13,3,8]
// 输出：[13,8]
// 解释：需要移除的节点是 5 ，2 和 3 。
// - 节点 13 在节点 5 右侧。
// - 节点 13 在节点 2 右侧。
// - 节点 8 在节点 3 右侧。
//
//
// 示例 2：
//
//
// 输入：head = [1,1,1,1]
// 输出：[1,1,1,1]
// 解释：每个节点的值都是 1 ，所以没有需要移除的节点。
//
//
//
//
// 提示：
//
//
// 给定列表中的节点数目在范围 [1, 10⁵] 内
// 1 <= Node.val <= 10⁵
//
//
// Related Topics 栈 递归 链表 单调栈 👍 45 👎 0

#if 0
struct ListNode *removeNodes(struct ListNode *head) {
    if (!head) return head;
    struct ListNode *next = removeNodes(head->next);
    if (next && next->val > head->val) {
        free(head);
        return next;
    }
    head->next = next;
    return head;
}
#else
#define MAXN 100000
struct ListNode *removeNodes(struct ListNode *head) {
    int top = -1;
    struct ListNode *stack[MAXN], *ans = NULL;
    for (struct ListNode *cur = head; cur; cur = cur->next) {
        for (; top >= 0 && stack[top]->val < cur->val; free(stack[top--])) {}
        stack[++top] = cur;
    }
    for (; top >= 0; stack[top]->next = ans, ans = stack[top--]) {}
    return ans;
}
#endif