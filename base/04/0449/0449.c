// 序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
//
// 设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。
// 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
//
// 编码的字符串应尽可能紧凑。
//
//
//
// 示例 1：
//
//
// 输入：root = [2,1,3]
// 输出：[2,1,3]
//
//
// 示例 2：
//
//
// 输入：root = []
// 输出：[]
//
//
//
//
// 提示：
//
//
// 树中节点数范围是 [0, 10⁴]
// 0 <= Node.val <= 10⁴
// 题目数据 保证 输入的树是一棵二叉搜索树。
//
//
// Related Topics 树 深度优先搜索 广度优先搜索 设计 二叉搜索树 字符串 二叉树 👍 464 👎 0

#define MAX 100000
void ser(struct TreeNode *root, char **res) {
    **res = '(', ++*res;
    if (root) {
        ser(root->left, res);
        *res += sprintf(*res, ",%d,", root->val);
        ser(root->right, res);
    }
    **res = ')', ++*res, **res = '\0';
}
char *serialize(struct TreeNode *root) {
    char help[MAX], *str = help;
    ser(root, &str);
    return strdup(help);
}
struct TreeNode *des(char **str) {
    struct TreeNode *cur = NULL;
    if (*++*str == '(') {
        cur = malloc(sizeof(*cur));
        for (cur->val = 0, cur->left = des(str); isdigit(*++*str);) {
            cur->val *= 10, cur->val += **str - '0';
        }
        cur->right = des((++*str, str));
    }
    ++*str;
    return cur;
}
struct TreeNode *deserialize(char *data) {
    return des(&data);
}
