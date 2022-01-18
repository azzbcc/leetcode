// 给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
//
//
//
// 示例 1：
//
//
// 输入：timePoints = ["23:59","00:00"]
// 输出：1
//
//
// 示例 2：
//
//
// 输入：timePoints = ["00:00","23:59","00:00"]
// 输出：0
//
//
//
//
// 提示：
//
//
// 2 <= timePoints <= 2 * 10⁴
// timePoints[i] 格式为 "HH:MM"
//
// Related Topics 数组 数学 字符串 排序 👍 143 👎 0

int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int findMinDifference(char **points, int size) {
    int times[size];
    memset(times, 0, sizeof(times));
    for (int i = 0; i < size; ++i) {
        times[i] += (points[i][0] - '0') * 600;
        times[i] += (points[i][1] - '0') * 60;
        times[i] += (points[i][3] - '0') * 10;
        times[i] += points[i][4] - '0';
    }
    qsort(times, size, sizeof(int), cmp);

    int ans = times[0] + 24 * 60 - times[size - 1];
    for (int i = 1; i < size; ++i) {
        ans = fmin(ans, times[i] - times[i - 1]);
        if (ans == 0) break;
    }
    return ans;
}