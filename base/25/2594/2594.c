// 给你一个整数数组 ranks ，表示一些机械工的 能力值 。ranksi 是第 i 位机械工的能力值。
// 能力值为 r 的机械工可以在 r * n² 分钟内修好 n 辆车。
//
// 同时给你一个整数 cars ，表示总共需要修理的汽车数目。
//
// 请你返回修理所有汽车 最少 需要多少时间。
//
// 注意：所有机械工可以同时修理汽车。
//
//
//
// 示例 1：
//
//
// 输入：ranks = [4,2,3,1], cars = 10
// 输出：16
// 解释：
// - 第一位机械工修 2 辆车，需要 4 * 2 * 2 = 16 分钟。
// - 第二位机械工修 2 辆车，需要 2 * 2 * 2 = 8 分钟。
// - 第三位机械工修 2 辆车，需要 3 * 2 * 2 = 12 分钟。
// - 第四位机械工修 4 辆车，需要 1 * 4 * 4 = 16 分钟。
// 16 分钟是修理完所有车需要的最少时间。
//
//
// 示例 2：
//
//
// 输入：ranks = [5,1,8], cars = 6
// 输出：16
// 解释：
// - 第一位机械工修 1 辆车，需要 5 * 1 * 1 = 5 分钟。
// - 第二位机械工修 4 辆车，需要 1 * 4 * 4 = 16 分钟。
// - 第三位机械工修 1 辆车，需要 8 * 1 * 1 = 8 分钟。
// 16 分钟时修理完所有车需要的最少时间。
//
//
//
//
// 提示：
//
//
// 1 <= ranks.length <= 10⁵
// 1 <= ranks[i] <= 100
// 1 <= cars <= 10⁶
//
//
// Related Topics 数组 二分查找 👍 102 👎 0

#define MAX 100LL * 1000000 * 1000000
bool valid(int *ranks, int size, int cars, long long int time) {
    for (int i = 0; i < size && cars; ++i) {
        long can = sqrtl(time * 1.0 / ranks[i]);
        if (can >= cars) return true;
        cars -= can;
    }
    return false;
}
long long repairCars(int *ranks, int size, int cars) {
    long long ans = 0;
    for (long long mid, r = MAX; ans <= r;) {
        if (valid(ranks, size, cars, mid = (ans + r) / 2)) {
            r = mid - 1;
        } else {
            ans = mid + 1;
        }
    }
    return ans;
}