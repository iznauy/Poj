#include <iostream>
using namespace std;
#define MAX 100

int t[MAX][MAX];
int n;
int * maxSum;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> t[i][j];
    maxSum = t[n - 1];
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            maxSum[j] = max(maxSum[j], maxSum[j + 1]) + t[i][j];
    cout << maxSum[0] << endl;
}
