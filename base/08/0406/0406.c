// 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h,
// k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来 重建这个队列。
//
// 注意：
// 总人数少于1100人。
//
// 示例
//
//
// 输入:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
// 输出:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
//
// Related Topics 贪心算法
// 👍 587 👎 0

static int cmp(const void *a, const void *b) {
    int *pa = *( int ** )a, *pb = *( int ** )b;
    if (pa[0] == pb[0]) return pb[1] - pa[1];
    return pa[0] - pb[0];
}
static int prefix_sum(const int bit_array[], int pos) {
    int sum = 0;
    for (pos += 1; pos; pos -= pos & (-pos)) {
        sum += bit_array[pos];
    }
    return sum;
}
static void update(int bit_array[], int size, int pos) {
    for (pos += 1; pos <= size; pos += pos & (-pos)) {
        bit_array[pos] += 1;
    }
}
int **reconstructQueue(int **people, int size, int *colSize, int *returnSize, int **returnColumnSizes) {
    int prefix[size + 1];
    int **ans = malloc((*returnSize = size) * (sizeof(int *)));

    memset(prefix, 0, sizeof(prefix));
    qsort(people, size, sizeof(int *), cmp);
    *returnColumnSizes = malloc(size * sizeof(int));
    for (int i = 0, pos; i < size; i++) {
        pos = people[i][1];
        for (int end = size - 1, mid; pos <= end;) {
            mid = (pos + end) / 2;
            if (mid - prefix_sum(prefix, mid) < people[i][1]) {
                pos = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        ans[pos] = people[i];
        update(prefix, size, pos);
        (*returnColumnSizes)[i] = 2;
    }

    return ans;
}
