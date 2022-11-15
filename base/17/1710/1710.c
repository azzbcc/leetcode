// 请你将一些箱子装在 一辆卡车 上。给你一个二维数组 boxTypes ，其中 boxTypes[i] = [numberOfBoxesi,numberOfUnitsPerBoxi]
// ：
//
//
// numberOfBoxesi 是类型 i 的箱子的数量。
// numberOfUnitsPerBoxi 是类型 i 每个箱子可以装载的单元数量。
//
//
// 整数 truckSize 表示卡车上可以装载 箱子 的 最大数量 。只要箱子数量不超过 truckSize ，你就可以选择任意箱子装到卡车上。
//
// 返回卡车可以装载 单元 的 最大 总数。
//
//
//
// 示例 1：
//
//
// 输入：boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
// 输出：8
// 解释：箱子的情况如下：
// - 1 个第一类的箱子，里面含 3 个单元。
// - 2 个第二类的箱子，每个里面含 2 个单元。
// - 3 个第三类的箱子，每个里面含 1 个单元。
// 可以选择第一类和第二类的所有箱子，以及第三类的一个箱子。
// 单元总数 = (1 * 3) + (2 * 2) + (1 * 1) = 8
//
// 示例 2：
//
//
// 输入：boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
// 输出：91
//
//
//
//
// 提示：
//
//
// 1 <= boxTypes.length <= 1000
// 1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
// 1 <= truckSize <= 10⁶
//
//
// Related Topics 贪心 数组 排序 👍 80 👎 0

void swap(int **a, int **b) {
    for (int *tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
void heap_adjust(int **boxTypes, int size, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < size && boxTypes[new_pos][1] < boxTypes[new_pos + 1][1]) new_pos += 1;
    if (new_pos < size && boxTypes[pos][1] < boxTypes[new_pos][1]) {
        swap(&boxTypes[pos], &boxTypes[new_pos]);
        heap_adjust(boxTypes, size, new_pos);
    }
}
int maximumUnits(int **boxTypes, int size, int *colSize, int truckSize) {
    int ans = 0;
    for (int i = size / 2 - 1; i >= 0; --i) {
        heap_adjust(boxTypes, size, i);
    }
    for (int c; truckSize && size; truckSize -= c) {
        c = fmin(truckSize, boxTypes[0][0]), ans += c * boxTypes[0][1];
        swap(&boxTypes[0], &boxTypes[--size]);
        heap_adjust(boxTypes, size, 0);
    }
    return ans;
}
