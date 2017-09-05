#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100005

int N, C;
int stalls[MAX];

bool valid(int X)
{
    int now = stalls[0], count = 1;
    for (int i = 1; i < N; i++) {
        if (stalls[i] - now >= X) {
            count++;
            now = stalls[i];
        }
    }
    return count >= C;
}

int main()
{
    int l, r, mid;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> stalls[i];
    sort(stalls, stalls + N);
    l = 1, r = stalls[N - 1];
    while (l <= r) {
        mid = (l + r) / 2;
        if (!valid(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << r << endl;
    return 0;
}
