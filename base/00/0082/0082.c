// 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中
// 没有重复出现 的数字。
//
// 返回同样按升序排列的结果链表。
//
//
//
// 示例 1：
//
//
// 输入：head = [1,2,3,3,4,4,5]
// 输出：[1,2,5]
//
//
// 示例 2：
//
//
// 输入：head = [1,1,1,2,3]
// 输出：[2,3]
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
// 👍 537 👎 0

struct ListNode *deleteDuplicates(struct ListNode *l) {
    if (!l) return l;
    struct ListNode head[1] = { { .next = l } }, *prev = head;

    for (struct ListNode *cur = l, *next; cur;) {
        next = cur->next;
        if (next && cur->val == next->val) {
            for (int val = cur->val; cur && cur->val == val; cur = next) {
                next = cur->next;
                free(cur);
                prev->next = next;
            }
        } else {
            prev = cur, cur = next;
        }
    }
    return head->next;
}
