//给定一个二叉树
//
// struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//}
//
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
//
// 初始状态下，所有 next 指针都被设置为 NULL。
//
//
//
// 进阶：
//
//
// 你只能使用常量级额外空间。
// 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
//
//
//
//
// 示例：
//
//
//
// 输入：root = [1,2,3,4,5,null,7]
//输出：[1,#,2,3,#,4,5,7,#]
//解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
//
//
//
// 提示：
//
//
// 树中的节点数小于 6000
// -100 <= node.val <= 100
//
//
//
//
//
//
// Related Topics 树 深度优先搜索
// 👍 247 👎 0
#if 0
void dfs(struct Node *root, struct Node *arr[], int depth) {
    if (!root) return;

    root->next = arr[depth], arr[depth] = root;
    dfs(root->right, arr, depth + 1);
    dfs(root->left, arr, depth + 1);
}
struct Node *connect(struct Node *root) {
    struct Node *arr[0x1000] = { NULL };

    dfs(root, arr, 0);

    return root;
}
#else
void resolve(struct Node **new_head, struct Node **prev, struct Node *next) {
    if (!next) return;
    if (!*new_head) *new_head = next;
    if (*prev) (*prev)->next = next;
    *prev = next;
}
struct Node *connect(struct Node *root) {
    for (struct Node *cur = root, *next; cur; cur = next) {
        next = NULL;
        for (struct Node *prev = NULL; cur; cur = cur->next) {
            resolve(&next, &prev, cur->left);
            resolve(&next, &prev, cur->right);
        }
    }

    return root;
}
#endif
