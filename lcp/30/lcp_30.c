// 小扣当前位于魔塔游戏第一层，共有 N 个房间，编号为 0 ~ N-1。
// 每个房间的补血道具/怪物对于血量影响记于数组 nums，
// 其中正数表示道具补血数值，即血量增加对应数值；
// 负数表示怪物造成伤害值，即血量减少对应数值；
// 0 表示房间对血量无影响。
//
// 小扣初始血量为 1，且无上限。
// 假定小扣原计划按房间编号升序访问所有房间补血/打怪，为保证血量始终为正值，小扣需对房间访问顺序进行调整，
// 每次仅能将一个怪物房间（负数的房间）调整至访问顺序末尾。请返回小扣最少需要调整几次，才能顺利访问所有房间。
// 若调整顺序也无法访问完全部房间，请返回 -1。
//
// 示例 1：
//
// 输入：nums = [100,100,100,-250,-60,-140,-50,-50,100,150]
//
// 输出：1
//
// 解释：初始血量为 1。至少需要将 nums[3] 调整至访问顺序末尾以满足要求。
//
// 示例 2：
//
// 输入：nums = [-200,-300,400,0]
//
// 输出：-1
//
// 解释：调整访问顺序也无法完成全部房间的访问。
//
// 提示：
// 1 <= nums.length <= 10^5
// -10^5 <= nums[i] <= 10^5
//
// Related Topics 贪心 数组 堆（优先队列） 👍 91 👎 0

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
        if (next + 1 < heap->size && heap->data[next] >= heap->data[next + 1]) next += 1;
        if (next >= heap->size || heap->data[next] >= heap->data[cur]) break;
        swap(&heap->data[cur], &heap->data[next]);
    }
}
void heap_add(heap_t *heap, int val) {
    heap->data[heap->size] = val;
    for (int now = heap->size++, parent; now; now = parent) {
        parent = (now - 1) / 2;
        if (heap->data[parent] <= heap->data[now]) break;
        swap(&heap->data[now], &heap->data[parent]);
    }
}
int heap_pop(heap_t *heap) {
    int ans = heap->data[0];

    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
int magicTower(int *nums, int size) {
    long sum = 0;
    int memory[size + 1], ans = 0;
    for (int i = 0; i < size; sum += nums[i++]) {}
    if (sum < 0) return -1;

    heap_t *heap = ( heap_t * )memory;
    heap->size = 0, sum = 0;
    for (int i = 0; i < size; ++i) {
        if (nums[i] < 0) heap_add(heap, nums[i]);
        if (sum += nums[i], sum < 0) sum -= heap_pop(heap), ans++;
    }
    return ans;
}
