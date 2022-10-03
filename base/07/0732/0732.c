// 当 k 个日程安排有一些时间上的交叉时（例如 k 个日程安排都在同一时间内），就会产生 k 次预订。
//
// 给你一些日程安排 [start, end) ，请你在每个日程安排添加后，返回一个整数 k ，表示所有先前日程安排会产生的最大 k
// 次预订。
//
// 实现一个 MyCalendarThree 类来存放你的日程安排，你可以一直添加新的日程安排。
//
//
// MyCalendarThree() 初始化对象。
// int book(int start, int end) 返回一个整数 k ，表示日历中存在的 k 次预订的最大值。
//
//
//
//
// 示例：
//
//
// 输入：
// ["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
// [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
// 输出：
// [null, 1, 1, 2, 3, 3, 3]
//
// 解释：
// MyCalendarThree myCalendarThree = new MyCalendarThree();
// myCalendarThree.book(10, 20); // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
// myCalendarThree.book(50, 60); // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
// myCalendarThree.book(10, 40); // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k 次预订是 2
// 次预订。 myCalendarThree.book(5, 15); // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。 myCalendarThree.book(5,
// 10); // 返回 3 myCalendarThree.book(25, 55); // 返回 3
//
//
//
//
// 提示：
//
//
// 0 <= start < end <= 10⁹
// 每个测试用例，调用 book 函数最多不超过 400次
//
// Related Topics 设计 线段树 有序集合 👍 127 👎 0

#define MAXN 1e9
typedef struct HashItem {
    int key, maxBook, lazy;
    UT_hash_handle hh;
} * hash_t;
hash_t hash_find(hash_t t, int key) {
    hash_t find;
    HASH_FIND_INT(t, &key, find);
    return find;
}
int hash_max_book(hash_t t, int key) {
    hash_t find = hash_find(t, key);
    return find ? find->maxBook : 0;
}
void hash_record(hash_t *t, int key, int book, int lazy) {
    hash_t cur = hash_find(*t, key);
    if (!cur) {
        cur = calloc(1, sizeof(*cur)), cur->key = key;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->maxBook += book, cur->lazy += lazy;
}
void hash_destroy(hash_t *t) {
    hash_t cur, next;
    HASH_ITER(hh, *t, cur, next) {
        HASH_DEL(*t, cur);
        free(cur);
    }
}

typedef struct {
    hash_t tree;
} MyCalendarThree;
MyCalendarThree *myCalendarThreeCreate() {
    return calloc(1, sizeof(MyCalendarThree));
}
static void update(MyCalendarThree *three, int start, int end, int l, int r, int idx) {
    if (r < start || end < l) return;
    if (start <= l && r <= end) {
        hash_record(&three->tree, idx, 1, 1);
    } else {
        int mid = (l + r) >> 1;
        update(three, start, end, l, mid, 2 * idx);
        update(three, start, end, mid + 1, r, 2 * idx + 1);
        hash_t find = hash_find(three->tree, idx);
        if (find) {
            int lmax      = hash_max_book(three->tree, idx * 2);
            int rmax      = hash_max_book(three->tree, idx * 2 + 1);
            find->maxBook = find->lazy + fmax(lmax, rmax);
        } else {
            hash_record(&three->tree, idx, 1, 0);
        }
    }
}

int myCalendarThreeBook(MyCalendarThree *three, int start, int end) {
    update(three, start, end - 1, 0, MAXN, 1);
    return hash_max_book(three->tree, 1);
}

void myCalendarThreeFree(MyCalendarThree *three) {
    hash_destroy(&three->tree);
    free(three);
}
