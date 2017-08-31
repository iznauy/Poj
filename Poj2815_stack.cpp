#include <iostream>
#include <stack>
using namespace std;
#define MAXN 50

int mark[MAXN][MAXN];
int rooms[MAXN][MAXN];
int R, C;
int roomNum, maxArea, area;

void Dfs(int i, int j)
{
    struct Room
    {
        int r, c;
        Room(int rr, int cc):
                r(rr), c(cc) {};
    };
    stack<Room> stk;
    stk.push(Room(i, j));
    while (!stk.empty()) {
        Room rm = stk.top();
        int i = rm.r, j = rm.c;
        if (mark[i][j])
            stk.pop();
        else {
            area++;
            mark[i][j] = 1;
            if ((rooms[i][j] & 1) == 0)
                stk.push(Room(i, j - 1));
            if ((rooms[i][j] & 2) == 0)
                stk.push(Room(i - 1, j));
            if ((rooms[i][j] & 4) == 0)
                stk.push(Room(i, j + 1));
            if ((rooms[i][j] & 8) == 0)
                stk.push(Room(i + 1, j));
        }
    }
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> rooms[i][j];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (!mark[i][j]) {
                roomNum++;
                area = 0;
                Dfs(i, j);
                maxArea = max(area, maxArea);
            }
    cout << roomNum << endl << maxArea << endl;
}

