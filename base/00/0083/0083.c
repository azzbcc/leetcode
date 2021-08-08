// 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。
//
// 返回同样按升序排列的结果链表。
//
//
//
// 示例 1：
//
//
// 输入：head = [1,1,2]
// 输出：[1,2]
//
//
// 示例 2：
//
//
// 输入：head = [1,1,2,3,3]
// 输出：[1,2,3]
//
//
//
//
// 提示：
//
//
// 链表中节点数目在范围 [0, 300] 内
// -100 <= Node.val <= 100
// 题目数据保证链表已经按升序排列
//
// Related Topics 链表
// 👍 523 👎 0

struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (!head) return head;
    for (struct ListNode *prev = head, *cur = head->next, *next; cur; cur = next) {
        next = cur->next;
        if (cur->val == prev->val) {
            free(cur);
            prev->next = next;
        } else {
            prev = cur;
        }
    }
    return head;
}
