// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
//
//
//
// 示例 1：
//
//
// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]
//
//
// 示例 2：
//
//
// 输入：head = []
// 输出：[]
//
//
// 示例 3：
//
//
// 输入：head = [1]
// 输出：[1]
//
//
//
//
// 提示：
//
//
// 链表中节点的数目在范围 [0, 100] 内
// 0 <= Node.val <= 100
//
//
// Related Topics 递归 链表 👍 1931 👎 0

struct ListNode *swapPairs(struct ListNode *l) {
    if (!l || !l->next) return l;

    struct ListNode *ans = l->next, *tail = swapPairs(l->next->next);
    ans->next = l, l->next = tail;

    return ans;
}
