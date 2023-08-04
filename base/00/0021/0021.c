// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//
//
// 示例 1：
//
//
// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]
//
//
// 示例 2：
//
//
// 输入：l1 = [], l2 = []
// 输出：[]
//
//
// 示例 3：
//
//
// 输入：l1 = [], l2 = [0]
// 输出：[0]
//
//
//
//
// 提示：
//
//
// 两个链表的节点数目范围是 [0, 50]
// -100 <= Node.val <= 100
// l1 和 l2 均按 非递减顺序 排列
//
//
// Related Topics 递归 链表 👍 3206 👎 0

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode head = { .next = NULL }, *cur = &head;
    for (; l1 || l2; cur = cur->next) {
        if (l1 && l2 && l1->val < l2->val || !l2) {
            cur->next = l1, l1 = l1->next;
        } else {
            cur->next = l2, l2 = l2->next;
        }
    }
    return head.next;
}