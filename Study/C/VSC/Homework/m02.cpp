#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// 方向数组：上、下、左、右
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void generateMaze(int x, int y, vector<vector<int>>& maze) {
    int m = maze.size();
    int n = maze[0].size();
    
    // 生成随机方向顺序
    vector<int> dirs = {0, 1, 2, 3};
    random_shuffle(dirs.begin(), dirs.end());
    
    for (int dir : dirs) {
        int nx = x + dx[dir];   
        int ny = y + dy[dir];
        
        // 检查新坐标是否在迷宫范围内且未被访问
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == 1) {
            maze[nx][ny] = 0; // 打通路径
            generateMaze(nx, ny, maze); // 递归生成
        }
    }
}

int main() {
    srand(time(0)); // 初始化随机种子
    
    int m, n, x, y;
    cout << "请输入迷宫的长度m和宽度n: ";
    cin >> m >> n;
    cout << "请输入入口的坐标x和y: ";
    cin >> x >> y;
    
    // 创建迷宫并初始化为全墙（1）
    vector<vector<int>> maze(m, vector<int>(n, 1));
    
    // 设置入口为路径（0）
    if (x >= 0 && x < m && y >= 0 && y < n) {
        maze[x][y] = 0;
        generateMaze(x, y, maze);
    } else {
        cout << "入口坐标不合法！" << endl;
        return 1;
    }
    
    // 打印迷宫
    cout << "生成的迷宫如下（1为墙，0为路）:" << endl;
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    return 0;
}