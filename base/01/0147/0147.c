// 对链表进行插入排序。
//
//
// 插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
// 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
//
//
//
// 插入排序算法：
//
//
// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
// 重复直到所有输入数据插入完为止。
//
//
//
//
// 示例 1：
//
// 输入: 4->2->1->3
// 输出: 1->2->3->4
//
//
// 示例 2：
//
// 输入: -1->5->3->4->0
// 输出: -1->0->3->4->5
//
// Related Topics 排序 链表
// 👍 318 👎 0

struct ListNode *insertionSortList(struct ListNode *head) {
    if (!head) return head;

    struct ListNode ans = { .next = head };
    for (struct ListNode *prev = head, *cur = head->next, *next; cur; cur = next) {
        next = cur->next;
        if (prev->val <= cur->val) {
            prev = cur;
            continue;
        }
        prev->next = next;

        struct ListNode *now = &ans;
        for (; now->next->val < cur->val; now = now->next) {}
        cur->next = now->next, now->next = cur;
    }
    return ans.next;
}