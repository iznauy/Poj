#include <iostream>
#include <stack>
using namespace std;

struct Problem {
    int n;
    char start;
    char middle;
    char end;
};

stack<Problem> stk;

int main()
{
    int n;
    cin >> n;
    Problem problem = {n, 'A', 'B', 'C'};
    stk.push(problem);
    while (!stk.empty()) {
        Problem p0 = stk.top();
        stk.pop();
        if (p0.n == 1)
            cout << p0.start << "->" << p0.end << endl;
        else {
            Problem p3 = {p0.n - 1, 'B', 'A', 'C'};
            stk.push(p3);
            Problem p2 = {1, 'A', 'B', 'C'};
            stk.push(p2);
            Problem p1 = {p0.n - 1, 'A', 'C', 'B'};
            stk.push(p1);
        }
    }
    return 0;
}