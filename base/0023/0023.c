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

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    int pos              = -1;
    struct ListNode *min = NULL;
    for (int i = 0; i < listsSize; ++i) {
        if (!min || lists[i] && min->val > lists[i]->val) {
            pos = i;
            min = lists[i];
        }
    }

    if (min) {
        lists[pos] = lists[pos]->next;
        min->next  = mergeKLists(lists, listsSize);
    }

    return min;
}