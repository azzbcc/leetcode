// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
// 个数字。滑动窗口每次只向右移动一位。
//
// 返回滑动窗口中的最大值。
//
//
//
// 示例 1：
//
//
// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
//
// 示例 2：
//
//
// 输入：nums = [1], k = 1
// 输出：[1]
//
//
// 示例 3：
//
//
// 输入：nums = [1,-1], k = 1
// 输出：[1,-1]
//
//
// 示例 4：
//
//
// 输入：nums = [9,11], k = 2
// 输出：[11]
//
//
// 示例 5：
//
//
// 输入：nums = [4,-2], k = 2
// 输出：[4]
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length
//
// Related Topics 堆 Sliding Window
// 👍 725 👎 0

#ifdef USE_QUEUE
typedef struct {
    int size, front, rear;
    int data[];
} queue_t;
void queue_init(queue_t *q, int size) {
    q->size = size, q->front = q->rear = 0;
}
bool queue_empty(queue_t *q) {
    return q->front == q->rear;
}
int queue_right(queue_t *q) {
    return q->data[(q->rear + q->size - 1) % q->size];
}
void queue_rpop(queue_t *q) {
    q->rear = (q->rear + q->size - 1) % q->size;
}
void queue_rpush(queue_t *q, int val) {
    while (!queue_empty(q) && queue_right(q) < val) {
        queue_rpop(q);
    }
    q->data[q->rear] = val, q->rear = (q->rear + 1) % q->size;
}
int queue_left(queue_t *q) {
    return q->data[q->front];
}
void queue_lpop(queue_t *q) {
    q->front = (q->front + 1) % q->size;
}
int *maxSlidingWindow(int *nums, int size, int k, int *returnSize) {
    int memory[sizeof(queue_t) / sizeof(int) + k + 1];
    queue_t *q = ( queue_t * )memory;
    int *ans   = malloc((*returnSize = size - k + 1) * sizeof(int));

    queue_init(q, k + 1);
    for (int i = 0; i < k; queue_rpush(q, nums[i++])) {}
    for (int i = 0; i + k < size; ++i) {
        ans[i] = queue_left(q);
        if (nums[i] == ans[i]) queue_lpop(q);
        queue_rpush(q, nums[i + k]);
    }
    ans[size - k] = queue_left(q);

    return ans;
}
#else
int max(int a, int b) {
    return a > b ? a : b;
}
int *maxSlidingWindow(int *nums, int size, int k, int *returnSize) {
    int prefix[size], suffix[size];
    for (int i = 0; i < size; ++i) {
        if (i % k) {
            prefix[i] = max(prefix[i - 1], nums[i]);
        } else {
            prefix[i] = nums[i];
        }
    }
    for (int i = size - 1; i >= 0; --i) {
        if (i + 1 < size && (i + 1) % k) {
            suffix[i] = max(suffix[i + 1], nums[i]);
        } else {
            suffix[i] = nums[i];
        }
    }

    int *ans = malloc((*returnSize = size - k + 1) * sizeof(int));
    for (int i = 0; i + k <= size; ++i) {
        ans[i] = max(suffix[i], prefix[i + k - 1]);
    }

    return ans;
}
#endif