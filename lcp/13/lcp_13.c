//我们得到了一副藏宝图，藏宝图显示，在一个迷宫中存在着未被世人发现的宝藏。
//
// 迷宫是一个二维矩阵，用一个字符串数组表示。它标识了唯一的入口（用 'S' 表示），和唯一的宝藏地点（用 'T'
// 表示）。但是，宝藏被一些隐蔽的机关保护了起
//来。在地图上有若干个机关点（用 'M' 表示），只有所有机关均被触发，才可以拿到宝藏。
//
// 要保持机关的触发，需要把一个重石放在上面。迷宫中有若干个石堆（用 'O'
// 表示），每个石堆都有无限个足够触发机关的重石。但是由于石头太重，我们一次只能搬一
//个石头到指定地点。
//
// 迷宫中同样有一些墙壁（用 '#' 表示），我们不能走入墙壁。剩余的都是可随意通行的点（用 '.'
// 表示）。石堆、机关、起点和终点（无论是否能拿到宝藏）也是
//可以通行的。
//
// 我们每步可以选择向上/向下/向左/向右移动一格，并且不能移出迷宫。搬起石头和放下石头不算步数。那么，从起点开始，我们最少需要多少步才能最后拿到宝藏呢？如果
//无法拿到宝藏，返回 -1 。
//
// 示例 1：
//
//
// 输入： ["S#O", "M..", "M.T"]
//
// 输出：16
//
// 解释：最优路线为： S->O, cost = 4, 去搬石头 O->第二行的M, cost = 3, M机关触发 第二行的M->O, cost = 3,
//我们需要继续回去 O 搬石头。 O->第三行的M, cost = 4, 此时所有机关均触发 第三行的M->T, cost = 2，去T点拿宝藏。
//总步数为16。
//
//
//
// 示例 2：
//
//
// 输入： ["S#O", "M.#", "M.T"]
//
// 输出：-1
//
// 解释：我们无法搬到石头触发机关
//
//
// 示例 3：
//
//
// 输入： ["S#O", "M.T", "M.."]
//
// 输出：17
//
// 解释：注意终点也是可以通行的。
//
//
// 限制：
//
//
// 1 <= maze.length <= 100
// 1 <= maze[i].length <= 100
// maze[i].length == maze[j].length
// S 和 T 有且只有一个
// 0 <= M的数量 <= 16
// 0 <= O的数量 <= 40，题目保证当迷宫中存在 M 时，一定存在至少一个 O 。
//
// 👍 57 👎 0

typedef struct {
    int x, y;
} point_t;

#define INF   99999999
#define LEN   100
#define MAX_M 16
#define MAX_O 40

int stone_count = 0, mechanism_count = 0;
int costs[MAX_M + 2][MAX_M + 2]   = { 0 };
int dist_stones[MAX_O][MAX_M + 1] = { 0 };
int dists[0x10000][MAX_M]         = { 0 };
const point_t wards[]             = { -1, 0, 1, 0, 0, -1, 0, 1 };
point_t start, end, stones[MAX_O], mechanisms[MAX_M];

// read the maze
void init(char **maze, int m, int n) {
    stone_count = 0, mechanism_count = 0;
    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
            if (maze[x][y] == 'S') {
                start.x = x, start.y = y;
            } else if (maze[x][y] == 'T') {
                end.x = x, end.y = y;
            } else if (maze[x][y] == 'O') {
                stones[stone_count].x = x;
                stones[stone_count].y = y;
                stone_count++;
            } else if (maze[x][y] == 'M') {
                mechanisms[mechanism_count].x = x;
                mechanisms[mechanism_count].y = y;
                mechanism_count++;
            }
        }
    }

    for (int i = 0; i <= mechanism_count + 1; ++i) {
        for (int j = 0; j <= mechanism_count + 1; ++j) {
            costs[i][j] = INF;
        }
    }
    for (int i = 0; i < stone_count; ++i) {
        for (int j = 0; j <= mechanism_count; ++j) {
            dist_stones[i][j] = INF;
        }
    }
    for (int i = 0; i < 0x1 << mechanism_count; ++i) {
        for (int j = 0; j < mechanism_count; ++j) {
            dists[i][j] = INF;
        }
    }
}

// calculate the distances from one stone to every mechanism
void bfs(char **maze, int m, int n, point_t beg, int *result) {
    point_t queue[LEN * LEN] = { 0 };
    int front = 0, rear = 1, map[LEN][LEN] = { 0 };

    queue[0] = beg, map[beg.x][beg.y] = 1;
    while (front < rear) {
        point_t now = queue[front++];
        if (maze[now.x][now.y] == 'S') {
            result[0] = map[now.x][now.y] - 1;
        } else if (maze[now.x][now.y] == 'M') {
            for (int pos = 0; pos < mechanism_count; ++pos) {
                if (mechanisms[pos].x == now.x && mechanisms[pos].y == now.y) {
                    result[pos + 1] = map[now.x][now.y] - 1;
                    break;
                }
            }
        }

        for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
            point_t next = now;
            next.x += wards[i].x;
            next.y += wards[i].y;

            if (next.x < 0 || next.x >= m) continue;
            if (next.y < 0 || next.y >= n) continue;
            if (map[next.x][next.y] > 0) continue;
            if (maze[next.x][next.y] == '#') continue;

            queue[rear++] = next, map[next.x][next.y] = map[now.x][now.y] + 1;
        }
    }
}

void dfs(int now, int cost, bool visited[MAX_M], int *ans) {
    if (cost >= *ans) return;

    bool over = true;
    for (int i = 0; i < mechanism_count; ++i) {
        if (!visited[i]) {
            over = false;
            break;
        }
    }
    if (over) {
        if (*ans > cost + costs[now][mechanism_count + 1] || *ans == -1) {
            *ans = cost + costs[now][mechanism_count + 1];
        }
        return;
    }

    for (int i = 0; i < mechanism_count; ++i) {
        if (visited[i]) continue;
        if (costs[now][i + 1] == INF) continue;

        visited[i] = true;
        dfs(i + 1, cost + costs[now][i + 1], visited, ans);
        visited[i] = false;
    }
}

int minimalSteps(char **maze, int m) {
    int n;
    if (m > 0) n = strlen(maze[0]);
    if (m <= 0 || n <= 0) return -1;

    // 数据初始化
    init(maze, m, n);

    // 检索终点到各个机关的最短距离
    bfs(maze, m, n, end, costs[mechanism_count + 1]);
    for (int i = 0; i <= mechanism_count; ++i) {
        costs[i][mechanism_count + 1] = costs[mechanism_count + 1][i];
    }

    // 检索石碓到各个机关的最短距离
    for (int i = 0; i < stone_count; ++i) {
        bfs(maze, m, n, stones[i], dist_stones[i]);
    }

    // 计算起点以及各个机关相互之间最短距离
    for (int i = 0; i < mechanism_count; ++i) {
        for (int j = i + 1; j <= mechanism_count; ++j) {
            int min = dist_stones[0][i] + dist_stones[0][j];
            for (int k = 1; k < stone_count; ++k) {
                if (min > dist_stones[k][i] + dist_stones[k][j]) { min = dist_stones[k][i] + dist_stones[k][j]; }
            }
            costs[i][j] = costs[j][i] = min;
        }
    }

	// 定义S为任意个机关点组成的集合
    // dists[S][k] = min(
    //     dists[S-k][1] + costs[1][k],
    //     dists[S-k][2] + costs[2][k],
    //     ...
	//     dists[S-k][i] + costs[i][k],
    // )
    for (int i = 0; i < mechanism_count; ++i) {
		dists[0x1 << i][i] = costs[0][i + 1];
    }
    for (size_t i = 0x3; i < 0x1 << mechanism_count; ++i) {
        for (int j = 0; j < mechanism_count; ++j) {
            int tj = 0x1 << j;
            // 集合i中不包含目的地j，不必运算
            if (0 == (i & tj)) continue;

            // 剔除集合中任意一点，动态规划最短路径
            for (int k = 0; k < mechanism_count; ++k) {
				// 目的地不可被剔除
				if (k == j) continue;
                int tk = 0x1 << k;
                if (0 == (i & tk)) continue;

                if (dists[i][j] > dists[i - tj][k] + costs[k + 1][j + 1]) {
					dists[i][j] = dists[i - tj][k] + costs[k + 1][j + 1];
                }
            }
        }
    }
    int ans = INF, last = (0x1 << mechanism_count) - 1;
    if (mechanism_count <= 0) {
        ans = costs[0][mechanism_count + 1];
    } else {
		for (int i = 0; i < mechanism_count; ++i) {
			if (ans > dists[last][i] + costs[i + 1][mechanism_count + 1]) {
				ans = dists[last][i] + costs[i + 1][mechanism_count + 1];
			}
		}
    }

    return ans >= INF ? -1 : ans;
}
