// 一所学校里有一些班级，每个班级里有一些学生，现在每个班都会进行一场期末考试。给你一个二维数组 classes ，其中
// classes[i] = [passi, totali] ，表示你提前知道了第 i 个班级总共有 totali 个学生，其中只有 passi 个学生可以通过考试。
//
// 给你一个整数 extraStudents ，表示额外有 extraStudents 个聪明的学生，他们 一定 能通过任何班级的期末考。你需要给这
// extraStudents 个学生每人都安排一个班级，使得 所有 班级的 平均 通过率 最大 。
//
// 一个班级的 通过率 等于这个班级通过考试的学生人数除以这个班级的总人数。平均通过率 是所有班级的通过率之和除以班级数目。
//
// 请你返回在安排这 extraStudents 个学生去对应班级后的 最大 平均通过率。与标准答案误差范围在 10⁻⁵
// 以内的结果都会视为正确结果。
//
//
//
// 示例 1：
//
//
// 输入：classes = [[1,2],[3,5],[2,2]], extraStudents = 2
// 输出：0.78333
// 解释：你可以将额外的两个学生都安排到第一个班级，平均通过率为 (3/4 + 3/5 + 2/2) / 3 = 0.78333 。
//
//
// 示例 2：
//
//
// 输入：classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
// 输出：0.53485
//
//
//
//
// 提示：
//
//
// 1 <= classes.length <= 10⁵
// classes[i].length == 2
// 1 <= passi <= totali <= 10⁵
// 1 <= extraStudents <= 10⁵
//
//
// Related Topics 贪心 数组 堆（优先队列） 👍 67 👎 0

typedef struct {
    double delta; // (pass + 1) / (total + 1) - pass / total
    int pass, total;
} node_t;
node_t node_init(int pass, int total) {
    return (node_t) { 1. * (pass + 1) / (total + 1) - 1. * pass / total, pass, total };
}
void swap(node_t *a, node_t *b) {
    node_t tmp = *a;
    *a = *b, *b = tmp;
}
void heap_adjust(node_t data[], int size, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < size && data[new_pos].delta < data[new_pos + 1].delta) new_pos += 1;
    if (new_pos < size && data[pos].delta < data[new_pos].delta) {
        swap(&data[pos], &data[new_pos]);
        heap_adjust(data, size, new_pos);
    }
}
double maxAverageRatio(int **classes, int size, int *colSize, int extraStudents) {
    double ans = 0;
    node_t nodes[size];
    for (int i = 0; i < size; ++i) {
        nodes[i] = node_init(classes[i][0], classes[i][1]);
    }
    for (int i = size / 2 - 1; i >= 0; heap_adjust(nodes, size, i--)) {}
    for (int i = 0; i < extraStudents; ++i) {
        nodes[0] = node_init(nodes->pass + 1, nodes->total + 1);
        heap_adjust(nodes, size, 0);
    }
    for (int i = 0; i < size; ++i) {
        ans += 1. * nodes[i].pass / nodes[i].total;
    }
    return ans / size;
}
