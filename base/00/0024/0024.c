//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//
//
// 示例:
//
// 给定 1->2->3->4, 你应该返回 2->1->4->3.
//
// Related Topics 链表
// 👍 583 👎 0

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *swapPairs(struct ListNode *l) {
    if (!l) return NULL;
    if (!l->next) return l;

    struct ListNode *next = l->next, *tail = swapPairs(l->next->next);
    next->next = l;
    l->next    = tail;

    return next;
}
