// 请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。
//
// 实现 AllOne 类：
//
//
// AllOne() 初始化数据结构的对象。
// inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
// dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key 从数据结构中删除。测试用例
// 保证：在减少计数前，key 存在于数据结构中。
// getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
// getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
//
//
//
//
// 示例：
//
//
// 输入
// ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey","getMinKey"]
// [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
// 输出
// [null, null, null, "hello", "hello", null, "hello", "leet"]
//
// 解释
// AllOne allOne = new AllOne();
// allOne.inc("hello");
// allOne.inc("hello");
// allOne.getMaxKey(); // 返回 "hello"
// allOne.getMinKey(); // 返回 "hello"
// allOne.inc("leet");
// allOne.getMaxKey(); // 返回 "hello"
// allOne.getMinKey(); // 返回 "leet"
//
//
//
//
// 提示：
//
//
// 1 <= key.length <= 10
// key 由小写英文字母组成
// 测试用例保证：在每次调用 dec 时，数据结构中总存在 key
// 最多调用 inc、dec、getMaxKey 和 getMinKey 方法 5 * 10⁴ 次
//
// Related Topics 设计 哈希表 链表 双向链表 👍 178 👎 0

typedef struct list_node *list_t;
typedef struct {
    list_t val;
    char str[12];
    UT_hash_handle hh;
} * hash_t, *hash_str_t;
hash_t hash_find(hash_t hash, const char *key) {
    hash_t find;
    HASH_FIND_STR(hash, key, find);
    return find;
}
struct list_node {
    int count;
    hash_str_t hash;
    list_t prev, next;
};
list_t list_create(int count) {
    list_t l = malloc(sizeof(*l));
    l->hash = NULL, l->prev = l->next = NULL, l->count = count;
    return l;
}
typedef struct {
    list_t head, tail;
    hash_t hash;
} AllOne;
static void list_append_prev(AllOne *one, list_t node, list_t append) {
    append->prev = node->prev, node->prev = append, append->next = node;
    if (append->prev) {
        append->prev->next = append;
    } else {
        one->head = append;
    }
}
static void list_append_next(AllOne *one, list_t node, list_t append) {
    if (!node) {
        if (one->head) {
            list_append_prev(one, one->head, append);
        } else {
            one->head = one->tail = append;
        }
    } else {
        append->next = node->next, node->next = append, append->prev = node;
        if (append->next) {
            append->next->prev = append;
        } else {
            one->tail = append;
        }
    }
}
void list_remove(AllOne *one, list_t node) {
    list_t prev = node->prev, next = node->next;
    if (prev) {
        prev->next = next;
    } else {
        one->head = next;
    }
    if (next) {
        next->prev = prev;
    } else {
        one->tail = prev;
    }
    free(node);
}
AllOne *allOneCreate() {
    return calloc(1, sizeof(AllOne));
}
void allOneInc(AllOne *one, char *key) {
    hash_t find = hash_find(one->hash, key);
    if (!find) {
        find = malloc(sizeof(*find)), find->val = NULL;
        sprintf(find->str, "%s", key);
        HASH_ADD_STR(one->hash, str, find);
    }

    // 当前链表旧节点
    list_t old = find->val;
    // 当前链表新节点
    list_t new = NULL;
    if (old && old->next && old->count + 1 == old->next->count) {
        new = old->next;
    } else if (!old && one->head && one->head->count == 1) {
        new = one->head;
    }
    if (!new) {
        new = list_create(old ? old->count + 1 : 1);
        list_append_next(one, old, new);
    }
    find->val = new;

    // 从旧节点删除
    hash_str_t str = NULL;
    if (old) {
        HASH_FIND_STR(old->hash, key, str);
        if (str) HASH_DEL(old->hash, str);
        if (!old->hash) list_remove(one, old);
    }

    // 加入新节点
    if (!str) {
        str = malloc(sizeof(*str));
        sprintf(str->str, "%s", key);
    }
    HASH_ADD_STR(new->hash, str, str);
}
void allOneDec(AllOne *one, char *key) {
    hash_t find = hash_find(one->hash, key);

    // 当前链表旧节点
    list_t old = find->val;
    // 当前链表新节点
    list_t new = NULL;
    if (old->prev && old->count - 1 == old->prev->count) { new = old->prev; }
    if (!new && old->count > 1) {
        new = list_create(old->count - 1);
        list_append_prev(one, old, new);
    }
    find->val = new;

    // 从旧节点删除
    hash_str_t str = NULL;
    HASH_FIND_STR(old->hash, key, str);
    HASH_DEL(old->hash, str);
    if (!old->hash) list_remove(one, old);

    // 加入新节点
    if (new) {
        HASH_ADD_STR(new->hash, str, str);
    } else {
        HASH_DEL(one->hash, find);
        free(find);
        free(str);
    }
}
char *allOneGetMaxKey(AllOne *one) {
    if (one->tail) {
        return one->tail->hash->str;
    } else {
        return "";
    }
}
char *allOneGetMinKey(AllOne *one) {
    if (one->head) {
        return one->head->hash->str;
    } else {
        return "";
    }
}
void allOneFree(AllOne *one) {
    hash_t h_cur, h_next;
    for (list_t cur = one->head, next; cur; cur = next) {
        next = cur->next;
        HASH_ITER(hh, cur->hash, h_cur, h_next) {
            HASH_DEL(cur->hash, h_cur);
            free(h_cur);
        }
        free(cur);
    }
    HASH_ITER(hh, one->hash, h_cur, h_next) {
        HASH_DEL(one->hash, h_cur);
        free(h_cur);
    }
    free(one);
}
