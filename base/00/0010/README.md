# 正则表达式匹配

使用动态规划可解。

定义`dp[i][j]`标识字符串前`ｉ`个字符是否匹配正则前`ｊ`个字符，状态转移方程为：

<table>
<thead>
<tr>
<td colspan="2">条件</td>
<td>结果</td>
<td>解析</td>
</tr>
</thead>
<tbody>
<tr>
<td rowspan="2">p[j] != '*'</td>
<td>s[i] != p[j]</td>
<td>dp[i][j] = false</td>
<td>当前字符与正则不匹配，结果必然不匹配</td>
</tr>
<tr>
<td>s[i] == p[j]</td>
<td>dp[i][j] = dp[i-1][j-1]</td>
<td>当前字符与正则匹配，结果等于截取最后一位的匹配</td>
</tr>
<tr>
<td rowspan="5">p[j] == '*'</td>
<td>s[i] != p[j-1]</td>
<td>dp[i][j] = dp[i][j-2]</td>
<td>星号与前一个字符在源串中占用宽度为0，不匹配任意字符。</td>
</tr>
<tr>
<td>s[i] == p[j-1]</td>
<td>dp[i][j] = dp[i][j-1]</td>
<td>星号与前一个字符在源串中占用宽度为1，可以匹配1个字符。</td>
</tr>
<tr>
<td>s[i] == p[j-1] && s[i-1] == p[j-1]</td>
<td>dp[i][j] = any(dp[i-1][j-1], dp[i][j-1])</td>
<td>星号与前一个字符在源串中占用宽度为2，可以匹配多2个字符。</td>
</tr>
<tr>
<td>...</td>
<td>...</td>
<td>...</td>
</tr>
<tr>
<td>s[n...i] == p[j-1]</td>
<td>dp[i][j] = any(dp[n...i][j-1])</td>
<td>星号与前一个字符在源串中占用宽度为n，可以匹配多个字符。</td>
</tr>
</tbody>
</table>

耗时只击败了`28%`的用户，内存更是只有`6%`，还有巨大的提升空间。

## 优化

当`p[j] == '*'` 时，将`p[j]`与其前一个字符`p[j - 1]`构成一个整体考虑，

有以下可能的情况。

<table>
<thead>
<tr>
<td colspan="2">条件</td>
<td>结果</td>
<td>解析</td>
</tr>
</thead>
<tbody>
<tr>
<td rowspan="4">p[j] == '*'</td>
<td>s.match(p[j-1,j]) == 0</td>
<td>dp[i][j] = dp[i][j-2]</td>
<td>星号与前一个字符在源串中占用宽度为0，不匹配任意字符。</td>
</tr>
<tr>
<td>s.match(p[j-1,j]) >= 1</td>
<td>dp[i][j] = dp[i-1][j]</td>
<td>星号与前一个字符在源串中占用宽度，至少可以匹配1个字符。</td>
</tr>
</tbody>
</table>