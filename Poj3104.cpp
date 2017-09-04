#include <iostream>
using namespace std;
#define MAX 100005

int N, K;
int clothes[MAX];
int l, r, mid;

bool valid(int x)
{
    int sumTime = 0;
    for (int i = 0; i < N; i++)
        if (clothes[i] > x) {
            sumTime += (clothes[i] - x - 1) / (K - 1) + 1;
            if (sumTime > x)
                return false;
        }
    return true;
}

int main()
{
    cin >> N;
    l = 1 << 30, r = 0;
    for (int i = 0; i < N; i++) {
        cin >> clothes[i];
        r = max(r, clothes[i]);
        l = min(l, clothes[i]);
    }
    cin >> K;
    if (K == 1)
        cout << r << endl;
    else {
        while (l <= r) {
            mid = (l + r) / 2;
            if (valid(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}