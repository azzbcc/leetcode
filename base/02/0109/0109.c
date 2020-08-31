// 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
//
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//
// 示例:
//
// 给定的有序链表： [-10, -3, 0, 5, 9],
//
// 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5
//
// Related Topics 深度优先搜索 链表
// 👍 307 👎 0

struct TreeNode *createBST(struct ListNode *l, int len) {
    if (len <= 0) return NULL;

    struct ListNode *mid = l;
    struct TreeNode *t   = calloc(1, sizeof(struct TreeNode));

    for (int i = len / 2; i > 0; --i) {
        mid = mid->next;
    }

    t->val   = mid->val;
    t->left  = createBST(l, len / 2);
    t->right = createBST(mid->next, (len - 1) / 2);

    return t;
}

struct TreeNode *sortedListToBST_01(struct ListNode *head) {
    if (!head) return NULL;

    int len = 0;
    for (struct ListNode *p = head; p; p = p->next, len += 1) {}

    return createBST(head, len);
}

struct TreeNode *preCreateBST(struct ListNode **l, int len) {
    if (len <= 0) return NULL;

    struct TreeNode *t = calloc(1, sizeof(struct TreeNode));

    t->left  = preCreateBST(l, len / 2);
    t->val   = (*l)->val;
    *l       = (*l)->next;
    t->right = preCreateBST(l, (len - 1) / 2);

    return t;
}

struct TreeNode *sortedListToBST_02(struct ListNode *head) {
    if (!head) return NULL;

    int len = 0;
    for (struct ListNode *p = head; p; p = p->next, len += 1) {}

    return preCreateBST(&head, len);
}

struct TreeNode *(*sortedListToBST)(struct ListNode *) = sortedListToBST_02;