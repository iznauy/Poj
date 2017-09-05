#include <iostream>
using namespace std;
#define MAX 10005

long long minCost;
int prices[MAX];
int requests[MAX];
int N, S;

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> prices[i] >> requests[i];
    minCost = prices[0] * requests[0];
    for (int i = 1; i < N; i++) {
        prices[i] = min(prices[i - 1] + S, prices[i]);
        minCost += prices[i] * requests[i];
    }
    cout << minCost << endl;
    return 0;
}
