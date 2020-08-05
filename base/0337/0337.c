// 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
// 除了“根”之外，每栋房子有且只有一个“父“
// 房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
// 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
//
// 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
//
// 示例 1:
//
// 输入: [3,2,3,null,3,null,1]
//
//     3
//    / \
//   2   3
//    \   \
//     3   1
//
// 输出: 7
// 解释:小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
//
// 示例 2:
//
// 输入: [3,4,5,1,3,null,1]
//
//     3
//    / \
//   4   5
//  / \   \
// 1   3   1
//
// 输出: 9
// 解释:小偷一晚能够盗取的最高金额= 4 + 5 = 9.
//
// Related Topics 树 深度优先搜索
// 👍 477 👎 0

int max(struct TreeNode *root, bool use) {
    if (!root) return 0;

    int max_ans = 0;
    if (use) max_ans = root->val;

    int left  = max(root->left, false);
    int right = max(root->right, false);

    if (!use) {
        int t_left  = max(root->left, true);
        int t_right = max(root->right, true);

        if (left < t_left) left = t_left;
        if (right < t_right) right = t_right;
    }

    return max_ans + left + right;
}

int rob(struct TreeNode *root) {
    int max1 = max(root, true);
    int max2 = max(root, false);

    return max1 > max2 ? max1 : max2;
}