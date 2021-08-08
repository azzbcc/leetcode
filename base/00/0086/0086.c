// 给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。
//
// 你应当保留两个分区中每个节点的初始相对位置。
//
//
//
// 示例：
//
//
// 输入：head = 1->4->3->2->5->2, x = 3
// 输出：1->2->2->4->3->5
//
// Related Topics 链表 双指针
// 👍 296 👎 0

struct ListNode *partition(struct ListNode *head, int x) {
    struct ListNode left = { 0 }, right = { 0 }, *l = &left, *r = &right;

    for (struct ListNode *cur = head; cur; cur = cur->next) {
        if (cur->val < x) {
            l->next = cur, l = cur;
        } else {
            r->next = cur, r = cur;
        }
    }
    l->next = right.next, r->next = NULL;

    return left.next;
}
