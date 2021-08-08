// 给你一个整数数组 jobs ，其中 jobs[i] 是完成第 i 项工作要花费的时间。
//
// 请你将这些工作分配给 k 位工人。所有工作都应该分配给工人，且每项工作只能分配给一位工人。工人的 工作时间
// 是完成分配给他们的所有工作花费时间的总和。请你 设计一套最佳的工作分配方案，使工人的 最大工作时间 得以 最小化 。
//
// 返回分配方案中尽可能 最小 的 最大工作时间 。
//
//
//
// 示例 1：
//
//
// 输入：jobs = [3,2,3], k = 3
// 输出：3
// 解释：给每位工人分配一项工作，最大工作时间是 3 。
//
//
// 示例 2：
//
//
// 输入：jobs = [1,2,4,7,8], k = 2
// 输出：11
// 解释：按下述方式分配工作：
// 1 号工人：1、2、8（工作时间 = 1 + 2 + 8 = 11）
// 2 号工人：4、7（工作时间 = 4 + 7 = 11）
// 最大工作时间是 11 。
//
//
//
// 提示：
//
//
// 1 <= k <= jobs.length <= 12
// 1 <= jobs[i] <= 107
//
// Related Topics 递归 回溯算法
// 👍 113 👎 0

#if 0
int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int minimumTimeRequired(int *jobs, int size, int k) {
    int dp[2][0x1 << size], one[0x1 << size], cur = 0;

    for (int i = 0; i < 0x1 << size; i++) {
        int sum = 0;
        for (int j = 0; j < size; j++) {
            if ((i | 0x1 << j) == i) sum += jobs[j];
        }
        dp[0][i] = one[i] = sum;
    }

    for (int i = 1; i < k; i++) {
        cur = 1 - cur;
        memcpy(dp[cur], dp[1 - cur], sizeof(dp[cur]));
        for (int j = 0; j < 0x1 << size; j++) {
            for (int l = j + 1; l < 0x1 << size; l++) {
                if (j & l) continue;
                dp[cur][j | l] = min(dp[cur][j | l], max(one[j], dp[1 - cur][l]));
                dp[cur][j | l] = min(dp[cur][j | l], max(one[l], dp[1 - cur][j]));
            }
        }
    }

    return dp[cur][(0x1 << size) - 1];
}
#else
bool dfs(int jobs[], int size, int res[], int k, int target) {
    if (!size) return true;
    for (int i = 0; i < k; ++i) {
        if (res[i] + *jobs > target) continue;
        res[i] += *jobs;
        if (dfs(jobs + 1, size - 1, res, k, target)) return true;
        res[i] -= *jobs;
        if (!res[i]) break;
    }
    return false;
}
bool check(int jobs[], int size, int k, int target) {
    int res[12] = { 0 };
    return dfs(jobs, size, res, k, target);
}
int cmp(const void *a, const void *b) {
    return *( int * )b - *( int * )a;
}
int minimumTimeRequired(int *jobs, int size, int k) {
    int min = 0, max = 0;
    qsort(jobs, size, sizeof(int), cmp);
    for (int i = 0; i < size; ++i) {
        if (min < jobs[i]) min = jobs[i];
        max += jobs[i];
    }
    while (min <= max) {
        int mid = (min + max) / 2;
        if (check(jobs, size, k, mid)) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }
    return min;
}
#endif