#include <iostream>
#include <cstring>
using namespace std;
#define MAX 75

char board[MAX + 2][MAX + 2];
bool mark[MAX + 2][MAX + 2];
int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int w = -1, h = -1;
int minSegments;

void search(int startX, int startY, int endX, int endY, int f, int segments)
{
    if (segments > minSegments)
        return;
    if ((startX == endX) && (startY == endY)) {
        minSegments = segments;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int x = startX + direction[i][0], y = startY + direction[i][1];
        if ((x > -1 && x < w + 2 && y > -1 && y < h + 2) && ((board[y][x] == ' ' && mark[y][x] == false) || (endX == x && endY == y))) {
            mark[y][x] = true;
            if (i == f)
                search(x, y, endX, endY, i, segments);
            else
                search(x, y, endX, endY, i, segments + 1);
            mark[y][x] = false;
        }
    }
}


int main()
{
    int time = 1;
    while (true) {
        cin >> w >> h;
        if ((w == 0) && (h == 0))
            break;
        cin.get();
        memset(board, ' ', sizeof(board));
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++)
                board[i][j] = char(cin.get());
            cin.get();
        }
        cout << "Board #" << time << ":" << endl;
        int pairs = 1;
        while (true) {
            int startX, startY, endX, endY;
            cin >> startX >> startY >> endX >> endY;
            if ((startX == 0) && (startY == 0) && (endX == 0) && (endY == 0))
                break;
            memset(mark, false, sizeof(mark));
            minSegments = 1000000;
            search(startX, startY, endX, endY, -1, 0);
            if (minSegments != 1000000)
                cout << "Pair " << pairs << ": " << minSegments << " segments." << endl;
            else
                cout << "Pair " << pairs << ": impossible." << endl;
            pairs++;
        }
        cout << endl;
        time++;
    }

}



