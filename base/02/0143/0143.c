// 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
// 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
// 示例 1:
//
// 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
//
// 示例 2:
//
// 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
// Related Topics 链表
// 👍 370 👎 0

struct ListNode *reserve(struct ListNode *l) {
    if (!l || !l->next) return l;
    struct ListNode *tail = l->next, *next = reserve(l->next);
    l->next = NULL, tail->next = l;
    return next;
}
void reorderList(struct ListNode *l) {
    if (!l) return;
    struct ListNode *l2 = l, *fast = l, *prev;
    while (fast) {
        prev = l2, l2 = l2->next, fast = fast->next;
        if (fast) fast = fast->next;
    }
    prev->next = NULL;

    l2 = reserve(l2);
    for (struct ListNode *next; l2; l = l->next->next, l2 = next) {
        next = l2->next, l2->next = l->next, l->next = l2;
    }
}
