#include <iostream>
#include <cstring>
using namespace std;

int triangle[100][100];
int localSum[100][100];
int n;

int getMax(int startX, int startY)
{
    if (localSum[startX][startY] != -1)
        return localSum[startX][startY];
    if (startY == n - 1)
        return triangle[startX][startY];
    int maxSum = triangle[startX][startY] + max(getMax(startX + 1, startY), getMax(startX + 1, startY + 1));
    localSum[startX][startY] = maxSum;
    return maxSum;
}

int main0()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> triangle[i][j];
    memset(localSum, -1, sizeof(localSum));
    int maxSum = getMax(0, 0);
    cout << maxSum << endl;
    return 0;
}
