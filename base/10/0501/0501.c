// 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
//
// 假定 BST 有如下定义：
//
//
// 结点左子树中所含结点的值小于等于当前结点的值
// 结点右子树中所含结点的值大于等于当前结点的值
// 左子树和右子树都是二叉搜索树
//
//
// 例如：
// 给定 BST [1,null,2,2],
//
//    1
//    \
//     2
//    /
//   2
//
//
// 返回[2].
//
// 提示：如果众数超过1个，不需考虑输出顺序
//
// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
// Related Topics 树
// 👍 181 👎 0
#define MAX 0x1000
typedef struct node {
    int last_val;
    int cur_count;
    int max_count;
    int mode_count;
    int modes[MAX];
} help_t;
void cal(int val, help_t *h) {
    if (val != h->last_val) {
        h->cur_count = 1;
    } else {
        h->cur_count += 1;
    }
    if (h->cur_count == h->max_count) {
        h->modes[h->mode_count++] = val;
    } else if (h->cur_count > h->max_count) {
        h->mode_count = 0;
        h->max_count = h->cur_count;
        h->modes[h->mode_count++] = val;
    }
    h->last_val = val;
}
void dfs(struct TreeNode *root, help_t *h) {
    if (!root) return;
    dfs(root->left, h);
    cal(root->val, h);
    dfs(root->right, h);
}

int *findMode(struct TreeNode *root, int *returnSize) {
    int *ans;
    help_t help = {0};

    dfs(root, &help);

    *returnSize = help.mode_count, ans = calloc(help.mode_count, sizeof(int));
    memcpy(ans, help.modes, help.mode_count * sizeof(int));

    return ans;
}