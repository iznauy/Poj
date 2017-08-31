#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAXMONEY 10005
#define MAXCITY 105

struct Road
{
    int d, l, t;
};

vector<vector<Road>> roads(MAXCITY);
int K, N, R;
int minLen = 1 << 30;
int totalLen, totalToll;
int minL[MAXCITY][MAXMONEY];
int visited[MAXCITY];

void dfs(int s)
{
    if (s == N) {
        minLen = min(minLen, totalLen);
        return;
    }
    for (int i = 0; i < roads[s].size(); i++) {
        int d = roads[s][i].d;
        if (!visited[d]) {
            int nextTotalToll = totalToll + roads[s][i].t;
            int nextTotalLen = totalLen + roads[s][i].l;
            if (nextTotalLen >= minLen || nextTotalToll >= K || nextTotalLen >= minL[d][nextTotalToll])
                continue;
            totalLen = nextTotalLen;
            totalToll = nextTotalToll;
            visited[d] = 1;
            minL[d][totalToll] = totalLen;
            dfs(d);
            visited[d] = 0;
            totalLen -= roads[s][i].l;
            totalToll -= roads[s][i].t;
        }
    }
}

int main()
{
    cin >> K >> N >> R;
    for (int i = 0; i < R; i++) {
        int s;
        Road road;
        cin >> s >> road.d >> road.l >> road.t;
        if (road.d != s)
            roads[s].push_back(road);
    }
    memset(minL, (1 << 6), sizeof(minL));
    visited[1] = 1;
    dfs(1);
    if (minLen != (1 << 30))
        cout << minLen << endl;
    else
        cout << "-1" << endl;
    return 0;
}