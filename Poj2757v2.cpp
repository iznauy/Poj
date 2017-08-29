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
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[j] > a[i])
                maxLen[j] = max(maxLen[j], maxLen[i] + 1);
    cout <<  * max_element(maxLen, maxLen + n) << endl;
    return 0;
}