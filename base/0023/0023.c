// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//
// 示例:
//
// 输入:
// [
//  1->4->5,
//  1->3->4,
//  2->6
// ]
// 输出: 1->1->2->3->4->4->5->6
// Related Topics 堆 链表 分治算法
// 👍 835 👎 0

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (!listsSize) return NULL;
    if (listsSize == 1) return lists[0];

    int mid = listsSize / 2;
    struct ListNode *left = mergeKLists(lists, mid);
    struct ListNode *right = mergeKLists(lists + mid, listsSize - mid);
    return mergeTwoLists(left, right);
}