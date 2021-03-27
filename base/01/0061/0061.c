// 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
//
//
//
// 示例 1：
//
//
// 输入：head = [1,2,3,4,5], k = 2
// 输出：[4,5,1,2,3]
//
//
// 示例 2：
//
//
// 输入：head = [0,1,2], k = 4
// 输出：[2,0,1]
//
//
//
//
// 提示：
//
//
// 链表中节点的数目在范围 [0, 500] 内
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109
//
// Related Topics 链表 双指针
// 👍 495 👎 0

#define MAXN 500
struct ListNode *help[MAXN];
struct ListNode *rotateRight(struct ListNode *head, int k) {
    int len = 0;
    if (!head) return head;
    for (struct ListNode *p = head; p; help[len++] = p, p = p->next) {}
    k %= len, help[len - 1]->next = help[0], help[len - 1 - k]->next = NULL;
    return help[(len - k) % len];
}