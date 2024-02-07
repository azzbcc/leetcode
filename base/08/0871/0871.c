// 汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。
//
// 沿途有加油站，用数组 stations 表示。
// 其中 stations[i] = [positioni, fueli] 表示第 i 个加油站位于出发位置东面 positioni 英里处，并且有 fueli 升汽油。
//
// 假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。
// 它每行驶 1 英里就会用掉 1 升汽油。当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。
//
// 为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1 。
//
// 注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。
// 如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。
//
//
//
// 示例 1：
//
//
// 输入：target = 1, startFuel = 1, stations = []
// 输出：0
// 解释：可以在不加油的情况下到达目的地。
//
//
// 示例 2：
//
//
// 输入：target = 100, startFuel = 1, stations = [[10,100]]
// 输出：-1
// 解释：无法抵达目的地，甚至无法到达第一个加油站。
//
//
// 示例 3：
//
//
// 输入：target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
// 输出：2
// 解释：
// 出发时有 10 升燃料。
// 开车来到距起点 10 英里处的加油站，消耗 10 升燃料。将汽油从 0 升加到 60 升。
// 然后，从 10 英里处的加油站开到 60 英里处的加油站（消耗 50 升燃料），
// 并将汽油从 10 升加到 50 升。然后开车抵达目的地。
// 沿途在两个加油站停靠，所以返回 2 。
//
//
//
//
// 提示：
//
//
// 1 <= target, startFuel <= 10⁹
// 0 <= stations.length <= 500
// 1 <= positioni < positioni+1 < target
// 1 <= fueli < 10⁹
//
//
// Related Topics 贪心 数组 动态规划 堆（优先队列） 👍 431 👎 0

typedef struct {
    int size;
    int data[];
} heap_t;
void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
void heap_adjust(heap_t *heap, int cur) {
    for (int next; cur < heap->size; cur = next) {
        next = cur * 2 + 1;
        if (next + 1 < heap->size && heap->data[next] <= heap->data[next + 1]) next += 1;
        if (next >= heap->size || heap->data[next] <= heap->data[cur]) break;
        swap(&heap->data[cur], &heap->data[next]);
    }
}
void heap_add(heap_t *heap, int val) {
    heap->data[heap->size] = val;
    for (int now = heap->size++, parent; now; now = parent) {
        parent = (now - 1) / 2;
        if (heap->data[parent] >= heap->data[now]) break;
        swap(&heap->data[now], &heap->data[parent]);
    }
}
int heap_pop(heap_t *heap) {
    int ans = heap->data[0];

    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
int minRefuelStops(int target, int current, int **stations, int size, int *colSize) {
    int ans = 0;
    uint8_t memory[sizeof(heap_t) + size * sizeof(int)];
    heap_t *heap = ( heap_t * )memory;

    heap->size = 0;
    for (int i = 0; current < target;) {
        for (; i < size && stations[i][0] <= current; heap_add(heap, stations[i++][1])) {}
        if (!heap->size) break;
        current += heap_pop(heap), ans += 1;
    }
    return current >= target ? ans : -1;
}
