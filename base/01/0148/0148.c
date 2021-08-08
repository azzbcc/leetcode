// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
//
// 进阶：
//
//
// 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
//
//
//
//
// 示例 1：
//
//
// 输入：head = [4,2,1,3]
// 输出：[1,2,3,4]
//
//
// 示例 2：
//
//
// 输入：head = [-1,5,3,4,0]
// 输出：[-1,0,3,4,5]
//
//
// 示例 3：
//
//
// 输入：head = []
// 输出：[]
//
//
//
//
// 提示：
//
//
// 链表中节点的数目在范围 [0, 5 * 104] 内
// -105 <= Node.val <= 105
//
// Related Topics 排序 链表
// 👍 869 👎 0

struct ListNode *sortList(struct ListNode *head) {
    if (!head) return NULL;
    struct ListNode ans = { .next = head };
    for (int len = 1;; len *= 2) {
        for (struct ListNode *prev = &ans, *h1 = prev->next, *h2, *next; h1; h1 = next) {
            next = h1, h2 = NULL;
            for (int i = 0; i < len * 2 && next; ++i) {
                if (i == len) h2 = next;
                next = next->next;
            }
            if (!h2) {
                if (h1 == ans.next) return h1;
                break;
            }

            // merge
            for (struct ListNode *record = h2; h1 != record || h2 != next; prev = prev->next) {
                if (h1 == record) {
                    prev->next = h2, h2 = h2->next;
                } else if (h2 == next || h1->val < h2->val) {
                    prev->next = h1, h1 = h1->next;
                } else {
                    prev->next = h2, h2 = h2->next;
                }
            }
            prev->next = next;
        }
    }
}
