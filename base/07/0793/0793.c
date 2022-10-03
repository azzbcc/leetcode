// f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。
//
//
// 例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
//
//
// 给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。
//
//
//
// 示例 1：
//
//
// 输入：k = 0
// 输出：5
// 解释：0!, 1!, 2!, 3!, 和 4! 均符合 k = 0 的条件。
//
//
// 示例 2：
//
//
// 输入：k = 5
// 输出：0
// 解释：没有匹配到这样的 x!，符合 k = 5 的条件。
//
// 示例 3:
//
//
// 输入: k = 3
// 输出: 5
//
//
//
//
// 提示:
//
//
// 0 <= k <= 10⁹
//
//
// Related Topics 数学 二分查找 👍 168 👎 0

int count(long n) {
    int ans = 0;
    for (; n /= 5; ans += n) {}
    return ans;
}
long left(int k) {
    long l = k, r = 5L * k;
    for (long mid; l <= r;) {
        mid = (l + r) / 2;
        if (count(mid) >= k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int preimageSizeFZF(int k) {
    return left(k + 1) - left(k);
}
