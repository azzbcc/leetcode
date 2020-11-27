// 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
//
// 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最
// 终结果不会超过 231 - 1 。
//
// 例如:
//
//
// 输入:
// A = [ 1, 2]
// B = [-2,-1]
// C = [-1, 2]
// D = [ 0, 2]
//
// 输出:
// 2
//
// 解释:
// 两个元组如下:
// 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
//
// Related Topics 哈希表 二分查找
// 👍 255 👎 0

typedef struct {
    int sum, count;
    UT_hash_handle hh;
} node_t, *hash_t;

int fourSumCount(int *A, int ASize, int *B, int BSize, int *C, int CSize, int *D, int DSize) {
    if (!ASize) return 0;

    int sum, ans = 0;
    hash_t hash = NULL, tmp;
    node_t nodes[ASize * ASize];

    for (int i = 0; i < ASize; ++i) {
        for (int j = 0; j < ASize; ++j) {
            sum = A[i] + B[j];
            HASH_FIND_INT(hash, &sum, tmp);
            if (tmp) {
                tmp->count += 1;
            } else {
                nodes[i * ASize + j] = (node_t) { sum, 1 };
                HASH_ADD_INT(hash, sum, &nodes[i * ASize + j]);
            }
        }
    }
    for (int i = 0; i < ASize; ++i) {
        for (int j = 0; j < ASize; ++j) {
            sum = 0 - C[i] - D[j];
            HASH_FIND_INT(hash, &sum, tmp);
            if (tmp) ans += tmp->count;
        }
    }
    HASH_CLEAR(hh, hash);

    return ans;
}