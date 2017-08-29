#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000

struct Point
{
    int h;
    int x;
    int y;
    int l;
};

bool cmp(Point p1, Point p2)
{
    if (p1.h != p2.h)
        return p1.h < p2.h;
    else if (p1.x != p2.x)
        return p1.x < p2.x;
    else
        return p1.y < p2.y;
}

Point points[MAX];
int r, c, n;

int main()
{
    cin >> r >> c;
    n = r * c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cin >> points[i * c + j].h;
            points[i * c + j].x = i;
            points[i * c + j].y = j;
            points[i * c + j].l = 1;
        }
    sort(points, points + n, cmp);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if ((((points[i].x == points[j].x && points[i].y == points[j].y + 1) ||
                    (points[i].x == points[j].x && points[i].y == points[j].y - 1))
                    || ((points[i].y == points[j].y && points[i].x == points[j].x + 1) ||
                    (points[i].y == points[j].y && points[i].x == points[j].x - 1)))
                    && (points[i].h < points[j].h)) {
                points[j].l = max(points[j].l, points[i].l + 1);
            }
        }
    int longestLine = -1;
    for (int i = 0; i < n; i++)
        longestLine = max(longestLine, points[i].l);
    cout << longestLine << endl;
    return 0;
}

