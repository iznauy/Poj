#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define UP 0
#define DOWN 1
#define MAXN 25

long long C[MAXN][MAXN][2];

void init(int n)
{
    memset(C, 0, sizeof(C));
    C[1][1][UP] = C[1][1][DOWN] = 1;
    for (int i = 2; i <= n; i++)
        for (int k = 1; k <= i; k++) {
            for (int M = k; M < i; M++)
                C[i][k][UP] += C[i - 1][M][DOWN];
            for (int N = 1; N < k; N++)
                C[i][k][DOWN] += C[i - 1][N][UP];
        }
}

void print(int n, long long cc)
{
    long long skipped = 0;
    int seq[MAXN];
    int used[MAXN];
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n; i++) {
        int k;
        int no;
        for (k = 1,  no = 0; k <= n; k++) {
            skipped = 0;
            if (!used[k]) {
                no++;
                if (i == 1)
                    skipped = C[n][no][UP] + C[n][no][DOWN];
                else {
                    if (k > seq[i - 1] && (i <= 2 || seq[i - 2] > seq[i - 1]))
                        skipped = C[n - i + 1][no][DOWN];
                    else if(k < seq[i - 1] && (i <= 2 || seq[i - 1] > seq[i - 2]))
                        skipped = C[n - i + 1][no][UP];
                }
                if (skipped >= cc)
                    break;
                else
                    cc -= skipped;
            }
        }
        used[k] = true;
        seq[i] = k;
    }
    for (int i = 1; i <= n; i++)
        if (i < n)
            cout << seq[i] << " ";
        else
            cout << seq[i] << endl;
}

int main()
{
    int T, n;
    long long c;
    init(20);
    cin >> T;
    while (T--) {
        cin >> n >> c;
        print(n, c);
    }
    return 0;
}