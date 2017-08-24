#include <iostream>
using namespace std;

int block[16][17] = {0};
int paint[16][17] = {0};
int t, n = 0;
int minTimes = -1;

bool validPaint();
void clear();

int main()
{
    cin >> t;
    for (int a = 0; a < t; a++) {
        clear();
        cin >> n;
        char temp;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                cin >> temp;
                if (temp == 'w')
                    block[i][j] = 1;
            }

        for (int i = 0; i < (1 << n); i++) {
            paint[1][1] = i;
            int c = 1;
            while (paint[1][c] >= 2) {
                paint[1][c + 1] = paint[1][c] / 2;
                paint[1][c] = paint[1][c] % 2;
                c++;
            }

            if (validPaint()) {
                int sum = 0;
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= n; j++)
                        sum += paint[i][j];
                if ((minTimes >= 0 && sum < minTimes) || (minTimes < 0))
                    minTimes = sum;
            }

        }

        if (minTimes >= 0)
            cout << minTimes << endl;
        else
            cout << "inf" << endl;
    }

}

bool validPaint()
{
    if (n == 1 && block[1][1] != 0)
        return false;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= n; j++)
            paint[i][j] = (paint[i - 1][j] + paint[i - 1][j - 1] + paint[i - 1][j + 1] + paint[i - 2][j] + block[i - 1][j]) % 2;

    for (int j = 1; j <= n; j++)
        if ((paint[n][j - 1] + paint[n][j + 1] + paint[n][j] + paint[n - 1][j]) % 2 != block[n][j])
            return false;

    return true;
}


void clear()
{
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 17; j++)
            block[i][j] = paint[i][j] = 0;
    n = 0;
    minTimes = -1;
}
