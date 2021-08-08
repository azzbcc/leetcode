//给你一个字符串 date ，它的格式为 Day Month Year ，其中：
//
//
// Day 是集合 {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"} 中的一个元素。
// Month 是集合 {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oc
// t", "Nov", "Dec"} 中的一个元素。
// Year 的范围在 [1900, 2100] 之间。
//
//
// 请你将字符串转变为 YYYY-MM-DD 的格式，其中：
//
//
// YYYY 表示 4 位的年份。
// MM 表示 2 位的月份。
// DD 表示 2 位的天数。
//
//
//
//
// 示例 1：
//
// 输入：date = "20th Oct 2052"
//输出："2052-10-20"
//
//
// 示例 2：
//
// 输入：date = "6th Jun 1933"
//输出："1933-06-06"
//
//
// 示例 3：
//
// 输入：date = "26th May 1960"
//输出："1960-05-26"
//
//
//
//
// 提示：
//
//
// 给定日期保证是合法的，所以不需要处理异常输入。
//
// Related Topics 字符串
// 👍 3 👎 0

char *months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
char *reformatDate(char *date) {
    int day = 0, month = 0;
    static char ans[11] = { '\0' };

    day = *date++ - '0';
    if (isdigit(*date)) day = day * 10 + *date++ - '0';
    date += 3;

    for (int i = 0; i < sizeof(months) / sizeof(months[0]); ++i) {
        if (!strncmp(date, months[i], 3)) {
            month = i + 1;
            break;
        }
    }

    sprintf(ans, "%s-%02d-%02d", date + 4, month, day);
    return ans;
}
