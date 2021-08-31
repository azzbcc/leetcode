# 移除盒子

## 解析+定义

将数列中的一组连续数字修改为`值+重复次数`的形式，便于处理。另定义`repeats[n]`表示颜色`n`在数列中出现连续的次数

## 思路

首先考虑递推状态压缩，因为一共有100种颜色，随机抽取放到100个位置。颜色顺序不会影响结果。

将题目转化为101个小球添加n个隔板，并将第一段舍去，剩下的n段依次着色。

一共有`C(100, n) 1 <= n <= 100` = `2^100 - 1`种可能的排列，超过`int`范围。所以舍弃此方案。 

## 深搜

使用深搜，检索所有可能的移除顺序，获取结果。

## 剪枝

掐头去尾，优先移除数列中间部分。

如果某个数只连续出现过一次，可以优先处理，不影响结果。

然而加上剪枝还是超时了。 

## 动态规划

定义`dp[j][i]`表示从`j`到`i`能获得的最大值。

对于第`i`个连续位置，有以下可能：
1. 当前数第一次出现，则`dp[j][i] = dp[j][i-1] + K(i)`
2. 当前数第二次出现，第一次出现位置为`m`，再次划分：
2.1 优先处理`m`位置，即不合并处理，`dp[j][i] = dp[j][i-1] + K(i)`
2.2 优先处理`(m, i)`位置的数据，然后将`m`与`i`合并为新的连续数，一次处理，此时`dp[j][i] = dp[j][m-1] + dp[m+1][i-1] + K(m+i)`
3. 当前数第K次出现，出现过的位置依次为`ma`...`mk`，再次划分:
3.1 当前位置单独处理，不与之前合并，`dp[j][i] = dp[j][i-1] + K(i)`
3.2 优先处理`(mk, i)`位置的数据，然后将`mk`与`i`合并为新的连续数，一次处理，此时`dp[j][i] = dp[j][mk-1] + dp[mk+1][i-1] + K(mk+i)`
3.3 优先处理`(mj, mk)`与`(mk, i)`位置的数据，然后将`mj`、`mk`以及`i`合并为新的连续数，一次处理，此时`dp[j][i] = dp[j][mj-1] + dp[mj+1][mk-1] + dp[mk+1][i-1] + K(mj+mk+i)`

综上，有状态转移方程

`dp[j][i] = max(dp[j][i-1]+K(i), dp[j][m-1]+dp[m+1][i-1]+K(m+i), ...)`

竟然WA了，还需要思考思考。

## 动态规划错误定位

在`3.3`中，还可以直接处理`(mj, i)`，然后将`mj`与`i`合并为新的连续数处理，此时`dp[j][i] = dp[j][mj-1] + dp[mj+1][i-1] + K(mj+i)`

即对于情况`3`，某一次重复位置可以跳过，所有的可能变为从前面重复的`K`个位置中，随机抽取`0-k`个位置，与`i`组成新的连续数组，一共有`2^K`种选择。

K最大值为49，此时选择结果比较大，需要优化。

## 重新动态规划

记 `V = nums[i].val, C = nums[i].count`，定义`dp[i][j][n]`表示在`i`左侧保证`n`个`V`连续的前提下，从`V1`到`j`构成的子数组能获得的最大值。

对于任意`dp[i][j][n]`，假设`[i, j]`区间有`k`个`V`，座标分别为`P1`，`P2`...`Pk`，其中`P1 = i`。

对于左侧`n`个`V`来说，可以分为`k`种策略：

0. 删除连续的n+1个V，此时`dp[i][j][n] = (n+C)^2 + dp[i+1][j][0] `
1. 优先取`(P1, P2)` 连接`n+1`个`V`与后面`K-1`个`V`，此时`dp[i][j][n] = dp[P1+1][P2-1][0] + dp[P2][j][n+C]`
2. 优先取`(P1, P3)` 连接`n+1`个`V`与后面`K-2`个`V`，此时`dp[i][j][n] = dp[P1+1][P3-1][0] + dp[P3][j][n+C]`
...
k. 优先取`(P1, Pk)` 连接`n+1`个`V`与最后1个`V`，此时`dp[i][j][n] = dp[P1+1][Pk-1][0] + dp[Pk][j][n+C]`