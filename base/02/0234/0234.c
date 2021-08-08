// 请判断一个链表是否为回文链表。
//
// 示例 1:
//
// 输入: 1->2
// 输出: false
//
// 示例 2:
//
// 输入: 1->2->2->1
// 输出: true
//
//
// 进阶：
// 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
// Related Topics 链表 双指针
// 👍 708 👎 0

struct ListNode *reverse(struct ListNode *l) {
    struct ListNode *prev = NULL;
    for (struct ListNode *next; l; next = l->next, l->next = prev, prev = l, l = next) {}
    return prev;
}
bool isPalindrome(struct ListNode *l) {
    bool ans              = true;
    struct ListNode *prev = NULL, *l2 = l;

    for (struct ListNode *fast = l; fast;) {
        prev = l2, l2 = l2->next, fast = fast->next;
        if (fast) fast = fast->next;
    }

    l2 = reverse(l2);
    for (struct ListNode *tmp = l2; tmp; tmp = tmp->next, l = l->next) {
        if (!(ans = tmp->val == l->val)) goto end;
    }

end:
    if (prev) prev->next = reverse(l2);
    return ans;
}
