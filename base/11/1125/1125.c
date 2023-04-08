// 作为项目经理，你规划了一份需求的技能清单 req_skills，并打算从备选人员名单 people 中选出些人组成一个「必要团队」
// （ 编号为 i 的备选人员 people[i] 含有一份该备选人员掌握的技能列表）。
//
// 所谓「必要团队」，就是在这个团队中，对于所需求的技能列表 req_skills
// 中列出的每项技能，团队中至少有一名成员已经掌握。可以用每个人的编号来表示团队中的成员：
//
//
// 例如，团队 team = [0, 1, 3] 表示掌握技能分别为 people[0]，people[1]，和 people[3] 的备选人员。
//
//
// 请你返回 任一 规模最小的必要团队，团队成员用人员编号表示。你可以按 任意顺序 返回答案，题目数据保证答案存在。
//
//
//
// 示例 1：
//
//
// 输入：req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
// 输出：[0,2]
//
//
// 示例 2：
//
//
// 输入：req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people =
// [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
// 输出：[1,2]
//
//
//
//
// 提示：
//
//
// 1 <= req_skills.length <= 16
// 1 <= req_skills[i].length <= 16
// req_skills[i] 由小写英文字母组成
// req_skills 中的所有字符串 互不相同
// 1 <= people.length <= 60
// 0 <= people[i].length <= 16
// 1 <= people[i][j].length <= 16
// people[i][j] 由小写英文字母组成
// people[i] 中的所有字符串 互不相同
// people[i] 中的每个技能是 req_skills 中的技能
// 题目数据保证「必要团队」一定存在
//
//
// Related Topics 位运算 数组 动态规划 状态压缩 👍 157 👎 0

typedef struct {
    int index;
    char *skill;
    UT_hash_handle hh;
} *hash_t, node_t;
int hash_index(hash_t t, char *skill) {
    hash_t find = NULL;
    HASH_FIND_STR(t, skill, find);
    return find ? find->index : -1;
}
int get_count(uint64_t val) {
    int a = val & 0xffffffff, b = val >> 32;
    return __builtin_popcount(a) + __builtin_popcount(b);
}
int *smallestSufficientTeam(char **skills, int skillsSize, char ***people, int peopleSize, int *peopleColSize,
                            int *returnSize) {
    int *ans, pu = 0x1L << peopleSize, su = 0x1 << skillsSize;
    node_t nodes[skillsSize];
    hash_t hash = NULL;
    uint64_t dp[su];
    for (int i = 0; i < skillsSize; ++i) {
        nodes[i] = (node_t) { i, skills[i] };
        HASH_ADD_STR(hash, skill, &nodes[i]);
    }
    dp[0] = 0;
    for (int i = 1; i < su; dp[i++] = pu - 1) {}
    for (int i = 0, mask; i < peopleSize; ++i) {
        mask = 0;
        for (int j = 0; j < peopleColSize[i]; mask |= 1 << hash_index(hash, people[i][j++])) {}
        if (!mask) continue;
        for (int j = su - 1; j >= 0; --j) {
            if (get_count((0x1L << i) | dp[j & ~mask]) < get_count(dp[j])) {
                dp[j] = dp[j & ~mask] | (0x1L << i);
            }
        }
    }
    HASH_CLEAR(hh, hash);
    ans = malloc((*returnSize = get_count(dp[su - 1])) * sizeof(int));
    for (int i = 0, j = 0; i < peopleSize; ++i) {
        if (dp[(0x1L << skillsSize) - 1] & (0x1L << i)) ans[j++] = i;
    }
    return ans;
}