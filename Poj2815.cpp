#include <iostream>
using namespace std;
#define MAXN 50

int mark[MAXN][MAXN];
int rooms[MAXN][MAXN];
int R, C;
int roomNum, maxArea, area;

void dfs(int i, int j) //recursion
{
    if (mark[i][j])
        return;
    area++;
    mark[i][j] = 1;
    if ((rooms[i][j] & 1) == 0)
        dfs(i, j - 1);
    if ((rooms[i][j] & 2) == 0)
        dfs(i - 1, j);
    if ((rooms[i][j] & 4) == 0)
        dfs(i, j + 1);
    if ((rooms[i][j] & 8) == 0)
        dfs(i + 1, j);
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
                dfs(i, j);
                maxArea = max(area, maxArea);
            }
    cout << roomNum << endl << maxArea << endl;
}