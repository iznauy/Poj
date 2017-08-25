#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

int s[9][9];
int sum[9][9];
int res[15][9][9][9][9];

int calSum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}

int fun(int n, int x1, int y1, int x2, int y2)
{
    int MIN = 1000000;
    if (res[n][x1][y1][x2][y2] != -1)
        return res[n][x1][y1][x2][y2];
    if (n == 1) {
        int t = calSum(x1, y1, x2, y2);
        t *= t;
        res[n][x1][y1][x2][y2] = t;
        return t;
    }
    for (int i = x1; i < x2; i++) {
        int s1 = calSum(i + 1, y1, x2, y2);
        int s2 = calSum(x1, y1, i, y2);
        int t = min(fun(n - 1, x1, y1, i, y2) + s1 * s1, fun(n - 1, i + 1, y1, x2, y2) + s2 * s2);
        if (MIN > t)
            MIN = t;
    }
    for (int j = y1; j < y2; j++) {
        int s1 = calSum(x1, j + 1, x2, y2);
        int s2 = calSum(x1, y1, x2, j);
        int t = min(fun(n - 1, x1, j + 1, x2, y2) + s2 * s2, fun(n - 1, x1, y1, x2, j) + s1 * s1);
        if (MIN > t)
            MIN = t;
    }
    res[n][x1][y1][x2][y2] = MIN;
    return MIN;
}

int main()
{
    memset(sum, 0, sizeof(sum));
    memset(res, -1, sizeof(res));
    int n;
    cin >> n;
    for (int i = 1; i < 9; i++)
        for (int j = 1, rowSum = 0; j < 9; j++) {
            cin >> s[i][j];
            rowSum += s[i][j];
            sum[i][j] = sum[i - 1][j] + rowSum;
        }
    double result = n * fun(n, 1, 1, 8, 8) - sum[8][8] * sum[8][8];
    cout << setiosflags(ios::fixed) << setprecision(3) << sqrt(result / (n * n)) << endl;
    return 0;
}