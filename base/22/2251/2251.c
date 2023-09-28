// 给你一个下标从 0 开始的二维整数数组 flowers ，其中 flowers[i] = [starti, endi] 表示第 i 朵花的
// 花期 从 starti 到 endi （都 包含）。同时给你一个下标从 0 开始大小为 n 的整数数组 people ，
// people[i] 是第 i 个人来看花的时间。
//
// 请你返回一个大小为 n 的整数数组 answer ，其中 answer[i]是第 i 个人到达时在花期内花的 数目 。
//
//
//
// 示例 1：
//
//
//
//
// 输入：flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
// 输出：[1,2,2,2]
// 解释：上图展示了每朵花的花期时间，和每个人的到达时间。
// 对每个人，我们返回他们到达时在花期内花的数目。
//
//
// 示例 2：
//
//
//
//
// 输入：flowers = [[1,10],[3,3]], people = [3,3,2]
// 输出：[2,2,1]
// 解释：上图展示了每朵花的花期时间，和每个人的到达时间。
// 对每个人，我们返回他们到达时在花期内花的数目。
//
//
//
//
// 提示：
//
//
// 1 <= flowers.length <= 5 * 10⁴
// flowers[i].length == 2
// 1 <= starti <= endi <= 10⁹
// 1 <= people.length <= 5 * 10⁴
// 1 <= people[i] <= 10⁹
//
//
// Related Topics 数组 哈希表 二分查找 有序集合 前缀和 排序 👍 121 👎 0

typedef struct {
    int a, b;
} node_t;
static int cmp(const void *a, const void *b) {
    node_t *pa = ( node_t * )a, *pb = ( node_t * )b;
    return pa->a - pb->a;
}
int *fullBloomFlowers(int **flowers, int size, int *colSize, int *people, int peopleSize, int *returnSize) {
    node_t data_f[size * 2], data_p[peopleSize];
    for (int i = 0; i < size; ++i) {
        data_f[2 * i + 0] = (node_t) { flowers[i][0], 1 };
        data_f[2 * i + 1] = (node_t) { flowers[i][1] + 1, -1 };
    }
    for (int i = 0; i < peopleSize; ++i) {
        data_p[i] = (node_t) { people[i], i };
    }
    qsort(data_f, size * 2, sizeof(node_t), cmp);
    qsort(data_p, peopleSize, sizeof(node_t), cmp);

    int *ans = malloc((*returnSize = peopleSize) * sizeof(int));
    for (int pf = 0, pp = 0, cur = 0; pp < peopleSize; ans[data_p[pp++].b] = cur) {
        for (; pf < size * 2 && data_f[pf].a <= data_p[pp].a; cur += data_f[pf++].b) {};
    }
    return ans;
}
