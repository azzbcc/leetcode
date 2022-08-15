// 设计实现双端队列。
//
// 实现 MyCircularDeque 类:
//
//
// MyCircularDeque(int k) ：构造函数,双端队列最大为 k 。
// boolean insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
// boolean insertLast() ：将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
// boolean deleteFront() ：从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
// boolean deleteLast() ：从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
// int getFront() )：从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
// int getRear() ：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
// boolean isEmpty() ：若双端队列为空，则返回 true ，否则返回 false 。
// boolean isFull() ：若双端队列满了，则返回 true ，否则返回 false 。
//
//
//
//
//  示例 1：
//
//
// 输入
// ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast",
// "insertFront", "getFront"]
// [[3], [1], [2], [3], [4], [], [], [], [4], []]
// 输出
// [null, true, true, true, false, 2, true, true, true, 4]
//
// 解释
// MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
// circularDeque.insertLast(1);			        // 返回 true
// circularDeque.insertLast(2);			        // 返回 true
// circularDeque.insertFront(3);			        // 返回 true
// circularDeque.insertFront(4);			        // 已经满了，返回 false
// circularDeque.getRear();  				// 返回 2
// circularDeque.isFull();				        // 返回 true
// circularDeque.deleteLast();			        // 返回 true
// circularDeque.insertFront(4);			        // 返回 true
// circularDeque.getFront();				// 返回 4
//
//
//
//
// 提示：
//
//
// 1 <= k <= 1000
// 0 <= value <= 1000
// insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty,
// isFull 调用次数不大于 2000 次
//
//
// Related Topics 设计 队列 数组 链表 👍 171 👎 0

typedef struct {
    int front, rear;
    int size;
    int data[];
} MyCircularDeque;
MyCircularDeque *myCircularDequeCreate(int k) {
    MyCircularDeque *deque = malloc(sizeof(MyCircularDeque) + (k + 1) * sizeof(int));
    deque->front = deque->rear = 0, deque->size = k + 1;
    return deque;
}
bool myCircularDequeIsEmpty(MyCircularDeque *deque) {
    return deque->front == deque->rear;
}
bool myCircularDequeIsFull(MyCircularDeque *deque) {
    return (deque->rear + 1) % deque->size == deque->front;
}
bool myCircularDequeInsertFront(MyCircularDeque *deque, int value) {
    if (myCircularDequeIsFull(deque)) return false;
    deque->front = (deque->front + deque->size - 1) % deque->size, deque->data[deque->front] = value;
    return true;
}
bool myCircularDequeInsertLast(MyCircularDeque *deque, int value) {
    if (myCircularDequeIsFull(deque)) return false;
    deque->data[deque->rear] = value, deque->rear = (deque->rear + 1) % deque->size;
    return true;
}
bool myCircularDequeDeleteFront(MyCircularDeque *deque) {
    if (myCircularDequeIsEmpty(deque)) return false;
    deque->front = (deque->front + 1) % deque->size;
    return true;
}
bool myCircularDequeDeleteLast(MyCircularDeque *deque) {
    if (myCircularDequeIsEmpty(deque)) return false;
    deque->rear = (deque->rear + deque->size - 1) % deque->size;
    return true;
}
int myCircularDequeGetFront(MyCircularDeque *deque) {
    if (myCircularDequeIsEmpty(deque)) return -1;
    return deque->data[deque->front];
}
int myCircularDequeGetRear(MyCircularDeque *deque) {
    if (myCircularDequeIsEmpty(deque)) return -1;
    return deque->data[(deque->rear + deque->size - 1) % deque->size];
}
void myCircularDequeFree(MyCircularDeque *deque) {
    free(deque);
}
