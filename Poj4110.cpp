#include <iostream>
#include <iomanip>
#include <algorithm>
#define MAX 105
using namespace std;

struct Box
{
    int values;
    int weight;
    double density;
};
int N, W;
Box boxes[MAX];

bool cmp(Box &a, Box &b)
{
    return a.density < b.density;
}

int main()
{
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        Box box;
        cin >> box.values >> box.weight;
        box.density = 1.0 * box.values / box.weight;
        boxes[i] = box;
    }
    sort(boxes, boxes + N, cmp);
    int totalWeight = 0;
    double totalValue = 0.0;
    for (int i = N - 1; i >=0; i--) {
        if (totalWeight + boxes[i].weight < W) {
            totalValue += boxes[i].values;
            totalWeight += boxes[i].weight;
        } else {
            totalValue += (W - totalWeight) * boxes[i].density;
            break;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(1) << totalValue << endl;
    return 0;
}