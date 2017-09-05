#include <iostream>
#define MAX 126
using namespace std;

long long partTypes[MAX][MAX];
int N;

void calculatePartTypes()
{
    partTypes[0][0] = 1;
    for (int i = 1; i <= 125; i++)
        for (int j = 1; j <= i; j++)
            for (int k = 0; k <= j; k++)
                partTypes[i][j] += partTypes[i - j][k];
}

int main()
{
    calculatePartTypes();
    while (true) {
        long long types = 0;
        cin >> N;
        if (N == 0)
            break;
        if (N % 2 == 0) {
            for (int i = 1; i <= N / 2; i++)
                types += partTypes[N / 2][i];
            for (int i = 2; i <= N; i += 2)
                for (int j = 0; j <= i && j <= 125; j++)
                    types += partTypes[(N - i) / 2][j];
        } else
            for (int i = 1; i <= N; i += 2)
                for (int j = 0; j <= i && j <= 125; j++)
                    types += partTypes[(N - i) / 2][j];
        cout << N << " " << types << endl;
    }
    return 0;
}




