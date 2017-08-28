#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000

char s1[MAX];
char s2[MAX];
int maxLength[MAX][MAX];

int main()
{
    while (cin >> s1 >> s2) {
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        for (int j = 0; j <= l2; j++)
            maxLength[0][j] = 0;
        for (int i = 0; i <= l1; i++)
            maxLength[i][0] = 0;
        for (int i = 1; i <= l1; i++)
            for (int j = 1; j <= l2; j++) {
                if (s1[i - 1] == s2[j - 1])
                    maxLength[i][j] = maxLength[i - 1][j - 1] + 1;
                else
                    maxLength[i][j] = max(maxLength[i - 1][j], maxLength[i][j - 1]);
            }
        cout << maxLength[l1][l2] << endl;
    }
}

