#include <iostream>
#define MAX 505
using namespace std;

int books[MAX];
int k, m;

bool check(long long ans)
{
    long long now = 0;
    int count = 1;
    for (int i = m - 1; i >=0; i--) {
        if (now + books[i] > ans) {
            count++;
            now = books[i];
        } else
            now += books[i];
    }
    return count <= k;
}

void print(int book, long long ans, int count, long long now)
{
    if (book < 0)
        return;
    else {
        bool sep = false;
        if (book == count - 1 || now + books[book] > ans) {
            sep = true;
            now = books[book];
            print(book - 1, ans, count - 1, now);
        } else {
            print(book - 1, ans, count, now + books[book]);
        }
        if (book != 0)
            cout << " " << books[book];
        else
            cout << books[book];
        if (sep)
            cout << " /";
    }
}

int main()
{
    int N;
    cin >> N;
    for (int p = 0; p < N; p++) {
        cin >> m >> k;
        long long l = 0, r = 0, mid;
        for (int i = 0; i < m; i++) {
            cin >> books[i];
            if (l < books[i])
                l = books[i];
            r += books[i];
        }
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        print(m - 1, l, k - 1, 0);
        cout << endl;
    }
    return 0;
}
