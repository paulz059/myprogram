#include <iostream>
#include <stack>
using namespace std;

const int MAX_ROW = 5, MAX_COL = 5;  // 迷宫的行数和列数

// 迷宫数组，0 表示可以通过，1 表示障碍物
int maze[MAX_ROW][MAX_COL] = {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 0, 1, 0 }
};

// 迷宫的坐标结构体
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// 判断该点是否可通过
bool isValid(int row, int col) {
    if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
        return false;  // 超出边界
    }
    if (maze[row][col] == 1) {
        return false;  // 遇到障碍物
    }
    return true;
}

// 老鼠走迷宫的函数
bool solveMaze() {
    stack<Point> s;
    s.push(Point(0, 0));  // 把起点加入栈中

    while (!s.empty()) {
        Point cur = s.top();
        s.pop();
        
        if (cur.x == MAX_ROW - 1 && cur.y == MAX_COL - 1) {
            // 找到了终点，返回成功
            

            return true;
        }

        if (isValid(cur.x + 1, cur.y)) {
            s.push(Point(cur.x + 1, cur.y));  // 往下走
            maze[cur.x][cur.y] = 1;  // 标记已走过
        }

        if (isValid(cur.x, cur.y + 1)) {
            s.push(Point(cur.x, cur.y + 1));  // 往右走
            maze[cur.x][cur.y] = 1;  // 标记已走过
        }

        if (isValid(cur.x - 1, cur.y)) {
            s.push(Point(cur.x - 1, cur.y));  // 往上走
            maze[cur.x][cur.y] = 1;  // 标记已走过
        }

        if (isValid(cur.x, cur.y - 1)) {
            s.push(Point(cur.x, cur.y - 1));  // 往左走
            maze[cur.x][cur.y] = 1;  // 标记已走过
        }
    }
     
    // 栈为空，无法找到通路
    return false;

    
}

int main() {
    if (solveMaze()) {
        cout << "迷宫有通路！" << endl;
    } else {
        cout << "迷宫无通路！" << endl;
    }

  
    return 0;
}