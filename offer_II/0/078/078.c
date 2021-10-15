// 给定一个链表数组，每个链表都已经按升序排列。
//
// 请将所有链表合并到一个升序链表中，返回合并后的链表。
//
//
//
// 示例 1：
//
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
// 输出：[1,1,2,3,4,4,5,6]
// 解释：链表数组如下：
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 将它们合并到一个有序链表中得到。
//  1->1->2->3->4->4->5->6
//
//
// 示例 2：
//
//
// 输入：lists = []
// 输出：[]
//
//
// 示例 3：
//
//
// 输入：lists = [[]]
// 输出：[]
//
//
//
//
// 提示：
//
//
// k == lists.length
// 0 <= k <= 10^4
// 0 <= lists[i].length <= 500
// -10^4 <= lists[i][j] <= 10^4
// lists[i] 按 升序 排列
// lists[i].length 的总和不超过 10^4
//
//
//
//
// 注意：本题与主站 23 题相同： https://leetcode-cn.com/problems/merge-k-sorted-lists/
// Related Topics 链表 分治 堆（优先队列） 归并排序 👍 12 👎 0

typedef struct {
    int size;
    struct ListNode *data[];
} heap_t;
void swap(struct ListNode **a, struct ListNode **b) {
    for (struct ListNode *tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
void heap_adjust(heap_t *heap, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < heap->size && heap->data[new_pos]->val > heap->data[new_pos + 1]->val) new_pos += 1;
    if (new_pos < heap->size && heap->data[pos]->val > heap->data[new_pos]->val) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
void heap_add(heap_t *heap, struct ListNode *val) {
    if (!val) return;
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->data[parent]->val <= heap->data[pos]->val) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
struct ListNode *heap_pop(heap_t *heap) {
    struct ListNode *ans = heap->data[0];
    heap->data[0]        = ans->next ? ans->next : heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
struct ListNode *mergeKLists(struct ListNode **lists, int size) {
    struct ListNode *head = NULL, **tail = &head;
    heap_t *heap = malloc(sizeof(heap_t) + size * sizeof(struct ListNode *));

    heap->size = 0;
    for (int i = 0; i < size; heap_add(heap, lists[i++])) {}
    for (; heap->size; *tail = heap_pop(heap), tail = &(*tail)->next) {}
    free(heap);

    return head;
}