#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 65
using namespace std;

int N, L;
vector<int> anLength;
bool anUsed[MAXN];
int nLastStickNo;

bool dfs(int R, int M)
{
    if (R == 0 && M == 0)
        return true;
    if (M == 0)
        M = L;
    int nStartNo = 0;
    if (M != L)
        nStartNo = nLastStickNo + 1;
    for (int i = nStartNo; i < N; i++) {
        if (!anUsed[i] && anLength[i] <= M) {
            if (i > 0) {
                if (anUsed[i - 1] == false && anLength[i] == anLength[i - 1])
                    continue;
            }
            anUsed[i] = true;
            nLastStickNo = i;
            if (dfs(R - 1, M - anLength[i]))
                return true;
            else {
                anUsed[i] = false;
                if (anLength[i] == M || M == L)
                    return false;
            }
        }
    }
    return false;
}

int main()
{
    while (true) {
        cin >> N;
        if (N == 0)
            break;
        int totalLen = 0;
        anLength.clear();
        for (int i = 0; i < N; i++) {
            int n;
            cin >> n;
            anLength.push_back(n);
            totalLen += n;
        }
        sort(anLength.begin(), anLength.end(), greater<int>());
        for (L = anLength[0]; L <= totalLen / 2; L++) {
            if (totalLen % L != 0)
                continue;
            memset(anUsed, false, sizeof(anUsed));
            if (dfs(N, L)) {
                cout << L << endl;
                break;
            }
        }
        if (L > totalLen / 2)
            cout << totalLen << endl;
    }
    return 0;
}