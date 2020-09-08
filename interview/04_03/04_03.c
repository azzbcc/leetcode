//给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D
//个链表）。返回一个包含所有深度的链表的数组。
//
//
//
// 示例：
//
// 输入：[1,2,3,4,5,null,7,8]
//
//        1
//       /  \
//      2    3
//     / \    \
//    4   5    7
//   /
//  8
//
//输出：[[1],[2,3],[4,5,7],[8]]
//
// Related Topics 树 广度优先搜索
// 👍 19 👎 0
#define MAXN 0x100
int help_len                = 0;
struct ListNode *help[MAXN] = { NULL };

void list_append(int index, int val) {
    struct ListNode *l = calloc(1, sizeof(struct ListNode));

    l->val = val;
    if (!help[index]) {
        help[index] = l->next = l;
    } else {
        l->next           = help[index]->next;
        help[index]->next = l;
        help[index]       = l;
    }
}
void dfs(struct TreeNode *root, int depth) {
    if (!root) return;
    if (help_len < depth) help_len = depth;
    list_append(depth - 1, root->val);
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
struct ListNode **listOfDepth(struct TreeNode *tree, int *returnSize) {
    struct ListNode **ans;

    help_len = 0;
    memset(help, 0, sizeof(help));
    dfs(tree, 1);

    *returnSize = help_len, ans = calloc(help_len, sizeof(struct ListNode *));
    for (int i = 0; i < help_len; ++i) {
        ans[i] = help[i]->next, help[i]->next = NULL;
    }

    return ans;
}
