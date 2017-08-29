#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1010

int a[MAX];
int n;
int maxLen[MAX];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxLen[i] = 1;
    }
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                maxLen[i] = max(maxLen[i], maxLen[j] + 1);
    cout <<  * max_element(maxLen, maxLen + n) << endl;
    return 0;
}
