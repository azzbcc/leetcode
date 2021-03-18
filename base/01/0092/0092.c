// 给你单链表的头节点 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right
// 的链表节点，返回 反转后的链表 。
//
//
// 示例 1：
//
//
// 输入：head = [1,2,3,4,5], left = 2, right = 4
// 输出：[1,4,3,2,5]
//
//
// 示例 2：
//
//
// 输入：head = [5], left = 1, right = 1
// 输出：[5]
//
//
//
//
// 提示：
//
//
// 链表中节点数目为 n
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n
//
//
//
//
// 进阶： 你可以使用一趟扫描完成反转吗？
// Related Topics 链表
// 👍 766 👎 0

struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    struct ListNode node = { .next = head };
    struct ListNode *cur = &node, *lprev = NULL, *last, *next;
    for (int i = 0; i <= right; ++i, last = cur, cur = next) {
        next = cur->next;
        if (i + 1 == left) {
            lprev = cur;
        } else if (i > left) {
            cur->next = last;
        }
    }
    lprev->next->next = next, lprev->next = last;
    return node.next;
}