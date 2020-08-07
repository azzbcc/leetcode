// 二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。
//
// 每个 LED 代表一个 0 或 1，最低位在右侧。
//
//
//
// 例如，上面的二进制手表读取 “3:25”。
//
// 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。
//
//
//
// 示例：
//
// 输入: n = 1
// 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "
// 0:32"]
//
//
//
// 提示：
//
//
// 输出的顺序没有要求。
// 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
// 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
// 超过表示范围（小时 0-11，分钟 0-59）的数据将会被舍弃，也就是说不会出现 "13:00", "0:61" 等时间。
//
// Related Topics 位运算 回溯算法
// 👍 155 👎 0

int help_len    = 0;
char *help[256] = { NULL };
void search(int num, int hour, int minute) {
    if (hour > 11 || minute >= 60) return;
    if (num <= 0) {
        help[help_len] = calloc(6, sizeof(char));
        sprintf(help[help_len++], "%d:%02d", hour, minute);
        return;
    }

    for (int i = 0; !minute && i < 4; ++i) {
        if (hour >= 1 << i) continue;
        search(num - 1, hour + (1 << i), minute);
    }
    for (int i = 0; i < 6; ++i) {
        if (minute >= 1 << i) continue;
        search(num - 1, hour, minute + (1 << i));
    }
}

char **readBinaryWatch(int num, int *returnSize) {
    help_len = 0;
    search(num, 0, 0);

    *returnSize = help_len;
    char **ans  = calloc(help_len, sizeof(char *));
    memcpy(ans, help, help_len * sizeof(char *));

    return ans;
}
