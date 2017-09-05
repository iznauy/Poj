#include <iostream>
using namespace std;
#define MAX 10005

int N, S;
long long minCost;
struct Week
{
    int price;
    int request;
};
Week weeks[MAX];

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> weeks[i].price >> weeks[i].request;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--)
            weeks[i].price = min(weeks[i].price, weeks[j].price + (i - j) * S);
        minCost += weeks[i].price * weeks[i].request;
    }
    cout << minCost << endl;
    return 0;
}
