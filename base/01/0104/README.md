# 二叉树的最大深度

这道题本来很简单，递归计算左子树和右子树的深度，取较大值+1即可解决。但是第一次提交超时了，因为使用了自定义MAX宏，导致每个节点的深度被计算了两次。

`MAX(a, b) (a) > (b) ? (a) : (b)`

虽然使用递推+循环队列解决了，但还是记录一下，使用宏需要谨慎。
