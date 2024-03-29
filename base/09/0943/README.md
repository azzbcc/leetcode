## 最短超级串

## 解题思路

先求次要解：求解最短超级串长度，等价于求解最大重合字符串长度之和(疑问1)

将每一个字符串视为有向图中一个节点，有向路径`A->B`表示在字符串`A`后追加字符串`B`，则`A->B`权值为`A`与`B`的最大重合长度(疑问2)。

此时需要思考以下两个问题：

1. 每个节点必须至少经过一次，是否存在某个节点经过多次，最终长度反而更小？
答：对于`A->B->C`，定义在字符串`B`中，与`A`重合的最后一个位置为`a`，与`C`重合的第一个位置为`c`，则`a`与`c`大小关系有以下三种可能：
1.1 `a < c`，在最坏(`A`与`C`没有重合部分)的情形下，`R(A->B->C) = len(A) + (c - a) + len(C)`，必然大于`R(A->C) = len(A) + len(C)`
1.2 `a == c`，同理，最坏的情形时`R(A->B->C) = len(A) + len(C) == R(A->C)`
1.3 `a > c`，此时，`A`与`C`的重合长度至少为`c - a`，最坏的情形同样有`R(A->B->C) == R(A->C)`
所以不存在某个节点使用多次，使最终结果更好的情况。

2. 边权值一定等于最大重合长度吗？考虑`A->B->C`三个字符串连接的情况，是否存在一种可能，在`A->B`不取最大值时，使`(A->B)->C`扩张，甚至超过`B`与`C`的最大重合长度，导致最终长度更小？
答：当且仅当`B`是`C`的字串时，可以将`C`扩张超过`B`然后与部分`A`重合，最终导致在`A->B`不取最大值时，使`(A->B)->C`更大。
但是题目规避了这种情况。

所以可以将问题转化为旅行商问题，每个节点经过一次的最大路径，可以动态规划求解

## 动态规划

定义`V(a, b)`，表示`A->B`的最大重合长度。
定义`dp[S][k]`，表示在集合`S`(包含多个节点，且必然包含节点`k`)中，节点`k`为最后一个节点的最大值。

有状态转移方程: 
`dp[s][k] = min(
    dp[S-k][0] + V(0, k),
    dp[S-k][1] + V(1, k),
    dp[S-k][2] + V(2, k),
    ...
    dp[S-k][i] + V(i, k)
)`，其中`0,1,2,..i`分别代表集合`S`中某个节点.

## 状态压缩

集合表示可以使用位运算；考虑`S = 10`，其二进制表示为`S = 1010(2)`，表示同时包含`1`号位和`3`号位节点的集合。

## 递推求解

考虑到从集合中剔除某个点的结果`S-k`必然小于`S`，所以可以在区域`[0x3, 0x1<<ASize]`中从小到大依次遍历并求解。

最终结果`dp[11...1(2)]`数组中的最小值即为最终结果。

## 求解最短超级串

首先，数组`dp[11...1(2)]`最小值的下标为最后一次的字符串选择。

基于已知数据`dp[S][n]`与已知下一次选择`p`，可以穷举上一次选择`k`，并根据`dp[S-p][k] + V(k, p) == dp[S][p]`逆推每次可能的选择之一，继而还原选择顺序。

也可以在`dp`求解的过程中，记录好从`dp[S-k]`转移到`dp[S]`时，节点ｋ的前驱，最终还原选择顺序。
