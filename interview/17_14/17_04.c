// 设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
//
// 示例：
//
// 输入： arr = [1,3,5,7,2,4,6,8], k = 4
// 输出： [1,2,3,4]
//
//
// 提示：
//
//
// 0 <= len(arr) <= 100000
// 0 <= k <= min(100000, len(arr))
//
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 109 👎 0

#if 0
int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int *smallestK(int *arr, int size, int k, int *returnSize) {
    int *ans = malloc((*returnSize = k) * sizeof(int));

    qsort(arr, size, sizeof(int), cmp);
    memcpy(ans, arr, k * sizeof(int));

    return ans;
}
#elif 0
void heap_adjust(int data[], int size, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < size && data[new_pos] < data[new_pos + 1]) new_pos += 1;
    if (new_pos < size && data[pos] < data[new_pos]) {
        for (int tmp = data[pos]; tmp != data[new_pos]; data[pos] = data[new_pos], data[new_pos] = tmp) {}
        heap_adjust(data, size, new_pos);
    }
}
int *smallestK(int *arr, int size, int k, int *returnSize) {
    int *ans = malloc((*returnSize = k) * sizeof(int));
    if (!k) return ans;
    memcpy(ans, arr, k * sizeof(int));
    for (int i = k / 2 - 1; i >= 0; heap_adjust(ans, k, i--)) {}
    for (int i = k; i < size; ++i) {
        if (arr[i] >= ans[0]) continue;
        ans[0] = arr[i], heap_adjust(ans, k, 0);
    }
    return ans;
}
#elif 0
void heap_adjust(int data[], int size, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < size && data[new_pos] > data[new_pos + 1]) new_pos += 1;
    if (new_pos < size && data[pos] > data[new_pos]) {
        for (int tmp = data[pos]; tmp != data[new_pos]; data[pos] = data[new_pos], data[new_pos] = tmp) {}
        heap_adjust(data, size, new_pos);
    }
}
int *smallestK(int *arr, int size, int k, int *returnSize) {
    int *ans = malloc((*returnSize = k) * sizeof(int));
    if (!k) return ans;
    for (int i = size / 2 - 1; i >= 0; heap_adjust(arr, size, i--)) {}
    for (int i = 0; i < k; ++i) {
        ans[i] = arr[0], arr[0] = arr[--size];
        heap_adjust(arr, size, 0);
    }
    return ans;
}
#else
void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
void qchoose(int arr[], int beg, int end, int k) {
    if (beg >= end) return;

    int pos = rand() % (end - beg + 1) + beg;
    swap(&arr[beg], &arr[pos]);

    int l = beg;
    for (int r = end, x = arr[l]; l < r;) {
        for (; l < r && arr[r] >= x; r--) {}
        for (; l < r && arr[l] <= x; l++) {}
        swap(&arr[l], &arr[r]);
    }
    swap(&arr[l], &arr[beg]);

    if (l < k) qchoose(arr, l + 1, end, k);
    if (l > k) qchoose(arr, beg, l - 1, k);
}
int *smallestK(int *arr, int size, int k, int *returnSize) {
    int *ans = malloc((*returnSize = k) * sizeof(int));
    qchoose(arr, 0, size - 1, k);
    memcpy(ans, arr, k * sizeof(int));
    return ans;
}
#endif