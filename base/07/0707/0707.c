// 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val
// 是当前节点的值，next是指向下一个节点的指针引用。如果要使用双向链表，则还需要一个属性 prev
// 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
//
// 在链表类中实现这些功能：
//
//
// get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
// addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
// addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
// addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val 的节点。如果 index 等于链表的长度，则该节点将附加
// 到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
// deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
//
//
//
//
// 示例：
//
// MyLinkedList linkedList = new MyLinkedList();
// linkedList.addAtHead(1);
// linkedList.addAtTail(3);
// linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
// linkedList.get(1);            //返回2
// linkedList.deleteAtIndex(1);  //现在链表是1-> 3
// linkedList.get(1);            //返回3
//
//
//
//
// 提示：
//
//
// 所有val值都在 [1, 1000] 之内。
// 操作次数将在 [1, 1000] 之内。
// 请不要使用内置的 LinkedList 库。
//
//
// Related Topics 设计 链表 👍 597 👎 0

typedef struct _tag_list_node list_node_t;
struct _tag_list_node {
    int val;
    list_node_t *next;
    list_node_t **prev;
};
typedef struct {
    list_node_t *first;
    list_node_t **last;
} MyLinkedList;
MyLinkedList *myLinkedListCreate() {
    MyLinkedList *list = malloc(sizeof(MyLinkedList));
    list->first = NULL, list->last = &list->first;
    return list;
}
list_node_t *list_get(MyLinkedList *list, int index) {
    list_node_t *ans = list->first;
    for (; index-- && ans; ans = ans->next) {}
    return ans;
}
int myLinkedListGet(MyLinkedList *list, int index) {
    list_node_t *node = list_get(list, index);
    return node ? node->val : -1;
}
void myLinkedListAddAtHead(MyLinkedList *list, int val) {
    list_node_t *node = malloc(sizeof(list_node_t));
    if ((node->val = val, node->next = list->first)) {
        list->first->prev = &node->next;
    } else {
        list->last = &node->next;
    }
    list->first = node, node->prev = &list->first;
}
void myLinkedListAddAtTail(MyLinkedList *list, int val) {
    list_node_t *node = malloc(sizeof(list_node_t));
    node->val = val, node->next = NULL, node->prev = list->last;
    *list->last = node, list->last = &node->next;
}
void myLinkedListAddAtIndex(MyLinkedList *list, int index, int val) {
    if (!index) return myLinkedListAddAtHead(list, val);
    list_node_t *prev = list_get(list, index - 1);
    if (!prev) return;
    list_node_t *node = malloc(sizeof(list_node_t));
    if ((node->val = val, node->next = prev->next)) {
        node->next->prev = &node->next;
    } else {
        list->last = &node->next;
    }
    prev->next = node, node->prev = &prev->next;
}
void myLinkedListDeleteAtIndex(MyLinkedList *list, int index) {
    list_node_t *node = list_get(list, index);
    if (!node) return;
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        list->last = node->prev;
    }
    *node->prev = node->next;
    free(node);
}
void myLinkedListFree(MyLinkedList *list) {
    for (list_node_t *cur = list->first, *next; cur; cur = next) {
        next = cur->next;
        free(cur);
    }
    free(list);
}