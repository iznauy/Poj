#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 10010
int n;
int a, b;
int setA[MAX], setB[MAX];

int main()
{
    cin >> n;
    while (n--) {
        int target = 0;
        cin >> target;
        cin >> a;
        for (int i = 0; i < a; i++)
            cin >> setA[i];
        cin >> b;
        for (int j = 0; j < b; j++)
            cin >> setB[j];
        sort(setA, setA + a);
        sort(setB, setB + b);
        int count = 0;
        int i = 0, j = b - 1;
        while (true) {
            if (setA[i] + setB[j] < target)
                i++;
            else if (setA[i] + setB[j] > target)
                j--;
             else {
                int t1 = 1;
                int t2 = 1;
                while (i + t1 < a && setA[i + t1] == setA[i])
                    t1++;
                while (j - t2 > -1 && setB[j - t2] == setB[j])
                    t2++;
                count += t1 * t2;
                i += t1;
                j -= t2;
            }
            if (i > a - 1 || j < 0)
                break;
        }
        cout << count << endl;
    }
}