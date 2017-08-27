#include <iostream>
using namespace std;

long long numbers[31] = {1};

long long countNumber(int n)
{
    if (n % 2 != 0)
        return 0;
    else if (n == 0) {
        return numbers[0];
    } else {
        if (numbers[n] != 0) {
            return numbers[n];
        }
        long long sum = 0;
        sum = 3 * countNumber(n - 2);
        for (int i = n - 4; i >= 0; i = i - 2)
            sum += 2 * countNumber(i);
        return sum;
    }

}

int main()
{
    int n = 0;
    while(true) {
        cin >> n;
        if (n == -1)
            break;
        cout << countNumber(n) << endl;
    }
    return 0;
}
