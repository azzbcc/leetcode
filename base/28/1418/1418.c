// 给你一个数组 orders，表示客户在餐厅中完成的订单，确切地说，orders[i]=[customerNamei,tableNumberi,foodItemi] ，其中
// customerNamei是客户的姓名，tableNumberi 是客户所在餐桌的桌号，而 foodItemi是客户点的餐品名称。
//
// 请你返回该餐厅的 点菜展示表。在这张表中，表中第一行为标题，其第一列为餐桌桌号
// “Table”，后面每一列都是按字母顺序排列的餐品名称。接下来每一行中的项则表示每张餐桌订购的相应餐品数量，第一列应当填对应的桌号，后面依次填写下单的餐品数量。
//
// 注意：客户姓名不是点菜展示表的一部分。此外，表中的数据行应该按餐桌桌号升序排列。
//
//
//
// 示例 1：
//
// 输入：orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried
// Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]] 输出：[["Table","Beef
// Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]]
// 解释：
// 点菜展示表如下所示：
// Table,Beef Burrito,Ceviche,Fried Chicken,Water
// 3    ,0           ,2      ,1            ,0
// 5    ,0           ,1      ,0            ,1
// 10   ,1           ,0      ,0            ,0
// 对于餐桌 3：David 点了 "Ceviche" 和 "Fried Chicken"，而 Rous 点了 "Ceviche"
// 而餐桌 5：Carla 点了 "Water" 和 "Ceviche"
// 餐桌 10：Corina 点了 "Beef Burrito"
//
//
// 示例 2：
//
// 输入：orders = [["James","12","Fried Chicken"],["Ratesh","12","FriedChicken"],["Amadeus","12","Fried
// Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]] 输出：[["Table","Canadian
// Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]]
//
// 解释：
// 对于餐桌 1：Adam 和 Brianna 都点了 "Canadian Waffles"
// 而餐桌 12：James, Ratesh 和 Amadeus 都点了 "Fried Chicken"
//
//
// 示例 3：
//
// 输入：orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
// 输出：[["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]
//
//
//
//
// 提示：
//
//
// 1 <= orders.length <= 5 * 10^4
// orders[i].length == 3
// 1 <= customerNamei.length, foodItemi.length <= 20
// customerNamei 和 foodItemi 由大小写英文字母及空格字符 ' ' 组成。
// tableNumberi 是 1 到 500 范围内的整数。
//
// Related Topics 数组 哈希表 字符串 有序集合 排序
// 👍 47 👎 0

typedef struct {
    char *str;
    int count;
    UT_hash_handle hh;
} * hash_t;
typedef struct {
    char *table;
    hash_t food;
    UT_hash_handle hh;
} * table_t;
int cmp_food(hash_t h1, hash_t h2) {
    return strcmp(h1->str, h2->str);
}
int cmp_table(table_t h1, table_t h2) {
    return atoi(h1->table) - atoi(h2->table);
}
int hash_str_count(hash_t t, char *str) {
    hash_t cur = NULL;
    HASH_FIND_STR(t, str, cur);
    return cur ? cur->count : 0;
}
void hash_str_record(hash_t *t, char *str) {
    hash_t cur = NULL;
    HASH_FIND_STR(*t, str, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->str = str, cur->count = 0;
        HASH_ADD_STR(*t, str, cur);
    }
    cur->count += 1;
}
int hash_count(table_t t, char *table, char *food) {
    table_t cur;
    HASH_FIND_STR(t, table, cur);
    return cur ? hash_str_count(cur->food, food) : 0;
}
void hash_record(table_t *t, char *table, char *food) {
    table_t cur;
    HASH_FIND_STR(*t, table, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->table = table, cur->food = NULL;
        HASH_ADD_STR(*t, table, cur);
    }
    hash_str_record(&cur->food, food);
}
char ***displayTable(char ***orders, int size, int *colSize, int *returnSize, int **returnColumnSizes) {
    hash_t food   = NULL, h_cur, h_next;
    table_t table = NULL, t_cur, t_next;
    for (int i = 0; i < size; ++i) {
        char *s_table = orders[i][1], *s_food = orders[i][2];
        hash_str_record(&food, s_food);
        hash_record(&table, s_table, s_food);
    }

    // 排序
    HASH_SORT(food, cmp_food);
    HASH_SORT(table, cmp_table);

    int iter, row = HASH_COUNT(table) + 1, col = HASH_COUNT(food) + 1;
    char ***ans = malloc((*returnSize = row) * sizeof(char **));

    *returnColumnSizes = malloc(row * sizeof(int));
    for (int i = 0; i < row; ++i) {
        ans[i] = malloc(((*returnColumnSizes)[i] = col) * sizeof(char *));
    }

    /// 拷贝表头
    iter = 0, ans[0][0] = strdup("Table");
    HASH_ITER(hh, table, t_cur, t_next) { ans[++iter][0] = strdup(t_cur->table); }
    iter = 0;
    HASH_ITER(hh, food, h_cur, h_next) {
        ans[0][++iter] = strdup(h_cur->str);
        HASH_DEL(food, h_cur);
        free(h_cur);
    }

    // 拷贝表
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            ans[i][j] = malloc(4 * sizeof(char));
            sprintf(ans[i][j], "%d", hash_count(table, ans[i][0], ans[0][j]));
        }
    }

    // 内存释放
    HASH_ITER(hh, table, t_cur, t_next) {
        HASH_ITER(hh, t_cur->food, h_cur, h_next) {
            HASH_DEL(t_cur->food, h_cur);
            free(h_cur);
        }
        HASH_DEL(table, t_cur);
        free(t_cur);
    }

    return ans;
}
