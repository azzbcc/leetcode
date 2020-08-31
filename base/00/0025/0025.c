// 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//
// k 是一个正整数，它的值小于或等于链表的长度。
//
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//
//
// 示例：
//
// 给你这个链表：1->2->3->4->5
//
// 当 k = 2 时，应当返回: 2->1->4->3->5
//
// 当 k = 3 时，应当返回: 3->2->1->4->5
//
//
//
// 说明：
//
//
// 你的算法只能使用常数的额外空间。
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
//
// Related Topics 链表
// 👍 672 👎 0

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverse(struct ListNode *l, int k, int now, bool *flag) {
    if (now <= 1 || !l || !l->next) {
        if (l && l->next) l->next = reverse(l->next, k, k, flag);
        if (!*flag && now <= 1) *flag = true;
        return l;
    }

    struct ListNode *tail = reverse(l->next, k, now - 1, flag);
    if (*flag) {
        struct ListNode *next = l->next;
        l->next = next->next, next->next = l;

        return tail;
    }
    return l;
}
struct ListNode *reverseKGroup(struct ListNode *l, int k) {
    if (k <= 1) return l;

    bool flag = false;
    return reverse(l, k, k, &flag);
}
