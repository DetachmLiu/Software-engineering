/*
    题面大致意思：给定一个正方形迷宫（边长为size），
    最外边一圈为墙壁，迷宫由墙壁（用1表示）和空地（用0表示）
    组成，问你从起点(1, 1)处到终点(size - 2, size - 2)最短
    走多少步，无解输出"No solution"。

    测试用例：
    10
    1 1 1 1 1 1 1 1 1 1
    1 0 0 1 0 0 0 1 0 1
    1 0 0 1 0 0 0 1 0 1
    1 0 0 0 0 1 1 0 0 1
    1 0 1 1 1 0 0 0 0 1
    1 0 0 0 1 0 0 0 0 1
    1 0 1 0 0 0 1 0 0 1
    1 0 1 1 1 0 1 1 0 1
    1 1 0 0 0 0 0 0 0 1
    1 1 1 1 1 1 1 1 1 1

    输出：
    14
*/
#include <cstdio>
#include <queue>
#include <ctime>    // 提供clock()函数，用于函数运行时间的计算

/*
    思路：
    知晓起终点位置后，如何才能得到最短距离呢？
    BFS给了我们一个实现方式————以当前坐标点为中心，
    向上下左右四个方向走，合法的走法（非墙壁、非走过的地方）
    存起来，同时记录从起点到每点的步数。
    若无法走到终点，返回-1，反之返回最少步数。

    BFS：广度优先搜索。
    在二叉树的层序遍历上体现的很清晰，一层层地往下走。
*/
constexpr int MAX_N{ 10 };
int maze[MAX_N][MAX_N];
bool inq[MAX_N][MAX_N]{ false };    // 记录当前点是否走过
int dir_x[4]{ 0, 0, 1, -1 };
int dir_y[4]{ 1, -1, 0, 0 };

// 定义每个小格子的信息
struct point {
    int x;
    int y;
    int steps;
    point() : x{ 0 }, y{ 0 }, steps{ 0 } {}
    point(int _x, int _y) : x{ _x }, y{ _y }, steps{ 0 } {}
};

// 判断当前位置是否合法
bool isValid(int& x, int& y, int& size) {
    if (x >= size - 1 || x < 1 || y >= size - 1 || y < 1)  return false;
    if (maze[x][y] == 1)  return false;
    return !inq[x][y];
}

// 走迷宫算法（BFS）
int bfs(point& start, int& size) {
    std::queue<point> q;
    q.push(start);

    point now, temp;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (now.x == size - 2 && now.y == size - 2)  return now.steps;
        for (int i = 0; i < 4; i++)
        {
            // 走向当前点的四周
            int newX = now.x + dir_x[i];
            int newY = now.y + dir_y[i];
            if (isValid(newX, newY, size))
            {
                temp.x = newX;
                temp.y = newY;
                temp.steps = now.steps + 1;
                q.push(temp);
                inq[newX][newY] = true;
            }
        }
    }

    return -1;
}

int main() {

    int size{ 0 };
    scanf_s("%d", &size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf_s("%d", &maze[i][j]);
        }
    }

    point start{ 1, 1 };
    
    // 获得bfs函数运行10000次的大致耗时
    auto st = clock();
    int res{ 0 };
    for (int i = 0; i < 10000; i++)
        res = bfs(start, size);
    auto et = clock();
    
    double time = static_cast<double>(et) - static_cast<double>(st);
    printf("Run bfs with %lf ms!\n", time);

    if (res == -1)
        printf("No solution");
    else
        printf("%d\n", res);

    return 0;
}
