#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1001

struct Block {
    int height;
    int x;
    int y;

};

bool cmp(Block b1, Block b2)
{
    if (b1.height != b2.height)
        return b1.height > b2.height;
    else if (b1.x != b2.x)
        return b1.x < b2.x;
    else
        return b1.y < b2.y;
}

Block blocks[MAX];
int times[MAX][2];

int main()
{
    int t = 0, n, maxDiffer;
    cin >> t;
    for (int a = 0; a < t; a++) {
        cin >> n >> blocks[0].x >> blocks[0].height >> maxDiffer;
        blocks[0].y = blocks[0].x;
        for (int i = 1; i <= n; i++)
            cin >> blocks[i].x >> blocks[i].y >> blocks[i].height;
        sort(blocks, blocks + n + 1, cmp);
        memset(times, -1, sizeof(times));
        for (int i = n; i >= 0; i--) {
            bool hasFoundLeft = false, hasFoundRight = false;
            int underLeft = -1, underRight = -1;
            for (int j = i + 1; j <= n; j++) {
                if (!hasFoundLeft && (blocks[j].x <= blocks[i].x) && (blocks[j].y >= blocks[i].x) &&
                    ((blocks[i].height - blocks[j].height) <= maxDiffer)) {
                    underLeft = j;
                    hasFoundLeft = true;
                }
                if (!hasFoundRight && (blocks[j].x <= blocks[i].y) && (blocks[j].y >= blocks[i].y) &&
                    ((blocks[i].height - blocks[j].height) <= maxDiffer)) {
                    underRight = j;
                    hasFoundRight = true;
                }
            }
            if (underLeft != -1) {
                if (times[underLeft][0] == -1 && times[underLeft][1] != -1)
                    times[i][0] = times[underLeft][1] + blocks[underLeft].y - blocks[i].x + blocks[i].height -
                                                                                           blocks[underLeft].height;
                else if (times[underLeft][1] == -1 && times[underLeft][0] != -1)
                    times[i][0] = times[underLeft][0] - blocks[underLeft].x + blocks[i].x + blocks[i].height -
                                                                                           blocks[underLeft].height;
                else if (times[underLeft][1] != -1 && times[underLeft][0] != -1)
                    times[i][0] = min(times[underLeft][0] - blocks[underLeft].x + blocks[i].x,
                                  times[underLeft][1] + blocks[underLeft].y - blocks[i].x) + blocks[i].height -
                              blocks[underLeft].height;
            } else if (blocks[i].height <= maxDiffer)
                times[i][0] = blocks[i].height;
            if (underRight != -1) {
                if (times[underRight][0] == -1 && times[underRight][1] != -1)
                    times[i][1] = times[underRight][1] + blocks[underRight].y - blocks[i].y + blocks[i].height -
                                                                                             blocks[underRight].height;
                else if (times[underRight][0] != -1 && times[underRight][1] == -1)
                    times[i][1] = times[underRight][0] - blocks[underRight].x + blocks[i].y + blocks[i].height -
                                                                                              blocks[underRight].height;
                else if (times[underRight][1] != -1 && times[underRight][0] != -1)
                    times[i][1] = min(times[underRight][0] - blocks[underRight].x + blocks[i].y,
                                      times[underRight][1] + blocks[underRight].y - blocks[i].y) + blocks[i].height -
                                  blocks[underRight].height;
            } else if (blocks[i].height <= maxDiffer)
                times[i][1] = blocks[i].height;
        }
        cout << times[0][0] << endl;
    }
}
