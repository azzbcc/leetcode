//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储
//一位 数字。
//
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
// 示例：
//
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
//
// Related Topics 链表 数学
// 👍 4646 👎 0

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int val               = 0;
    struct ListNode *head = NULL, *tail = NULL, *tmp = NULL;

    while (l1 || l2 || val) {
        if (l1) val += l1->val;
        if (l2) val += l2->val;

        tmp       = calloc(1, sizeof(struct ListNode));
        tmp->val  = val % 10;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
        } else {
            tail->next = tmp;
        }
        tail = tmp;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        val /= 10;
    }

    return head;
}
