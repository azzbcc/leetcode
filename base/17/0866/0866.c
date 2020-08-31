//求出大于或等于 N 的最小回文素数。
//
// 回顾一下，如果一个数大于 1，且其因数只有 1 和它自身，那么这个数是素数。
//
// 例如，2，3，5，7，11 以及 13 是素数。
//
// 回顾一下，如果一个数从左往右读与从右往左读是一样的，那么这个数是回文数。
//
// 例如，12321 是回文数。
//
//
//
// 示例 1：
//
// 输入：6
//输出：7
//
//
// 示例 2：
//
// 输入：8
//输出：11
//
//
// 示例 3：
//
// 输入：13
//输出：101
//
//
//
// 提示：
//
//
// 1 <= N <= 10^8
// 答案肯定存在，且小于 2 * 10^8。
//
//
//
//
//
// Related Topics 数学
// 👍 47 👎 0

#define COUNT 1230

int prime_count = 8;
int primes[COUNT] = { 2, 3, 5, 7, 11, 13, 17, 19 };
void initPrime() {
    for (int n = 23; prime_count < COUNT; n += 2) {
        bool flag = true;
        for (int i = 0; primes[i] * primes[i] <= n; ++i) {
            if (n % primes[i] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) primes[prime_count++] = n;
    }
}

bool isPrime(int N) {
    for (int i = 0; primes[i] * primes[i] <= N ; ++i) {
        if (N % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

int palindrome_count = 5;
int palindrome[COUNT] = {2, 3, 5, 7, 11};
void initPalindrome() {
    if (palindrome_count > 5) return;

    for (int i = 10; i <= 10003; ++i) {
        int m = i / 10, n = i;
        while (m) {
            n *= 10;
            n += m % 10;
            m /= 10;
        }
        if (isPrime(n)) {
            palindrome[palindrome_count++] = n;
        }
    }
}

int bs(int arr[], int len, int key) {
    int beg = 0, end = len;
    while (beg < end) {
        int mid = (beg + end) / 2;
        if (arr[mid] < key) beg = mid + 1;
        if (arr[mid] >= key) end = mid;
    }
    return beg;
}

int primePalindrome(int N) {
    initPrime();
    initPalindrome();
    return palindrome[bs(palindrome, palindrome_count, N)];
}
