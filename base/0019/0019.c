// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
//
// 示例：
//
// 给定一个链表: 1->2->3->4->5, 和 n = 2.
//
// 当删除了倒数第二个节点后，链表变为 1->2->3->5.
//
//
// 说明：
//
// 给定的 n 保证是有效的。
//
// 进阶：
//
// 你能尝试使用一趟扫描实现吗？
// Related Topics 链表 双指针
// 👍 926 👎 0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode *tail = head, *prev = head;

    while (n--) tail = tail->next;
    while (tail && tail->next) {
        prev = prev->next;
        tail = tail->next;
    }

    struct ListNode *next = prev->next;
    if (!tail) {
        free(head);
        return next;
    }

    prev->next = next->next;
    free(next);

    return head;
}
