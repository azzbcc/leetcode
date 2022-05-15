// 给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
//
//
// 示例:
// 输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// 输出: 2
// 解释:
// 这五个点如下图所示。组成的橙色三角形是最大的，面积为2。
//
//
//
//
// 注意:
//
//
// 3 <= points.length <= 50.
// 不存在重复的点。
// -50 <= points[i][j] <= 50.
// 结果误差值在 10^-6 以内都认为是正确答案。
//
// Related Topics 几何 数组 数学 👍 135 👎 0

int weight(int *pa, int *pb, int *pc) {
    return abs(pa[0] * (pb[1] - pc[1]) + pb[0] * (pc[1] - pa[1]) + pc[0] * (pa[1] - pb[1]));
}
double largestTriangleArea(int **points, int size, int *colSize) {
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            for (int k = j + 1; k < size; ++k) {
                ans = fmax(ans, weight(points[i], points[j], points[k]));
            }
        }
    }
    return ans / 2.;
}
