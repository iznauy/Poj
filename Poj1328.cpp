#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 1005
using namespace std;

struct Node
{
    double left, right;
};

bool operator < (const Node & a, const Node & b)
{
    return a.left < b.left;
}

int N, D;
Node nodes[MAX];

int solve()
{
    int count = 1;
    double right = nodes[0].right;
    for (int i = 1; i < N; i++)
        if (nodes[i].left <= right)
            right = min(nodes[i].right, right);
        else {
            count++;
            right = nodes[i].right;
        }
    return count;
}

int main()
{
    int times = 1;
    while (true) {
        cin >> N >> D;
        if (N == 0 && D == 0)
            break;
        bool possible = true;
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            if (y > D)
                possible = false;
            else {
                nodes[i].left = x - sqrt(D * D - y * y);
                nodes[i].right = x + sqrt(D * D - y * y);
            }
        }
        if (!possible)
            cout << "Case " << times <<": " << -1 << endl;
        else {
            sort(nodes, nodes + N);
            cout << "Case " << times <<": " << solve() << endl;
        }
        times++;
    }
    return 0;
}


