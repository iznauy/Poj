#include <iostream>
#include <cmath>
using namespace std;

int n;
int blocks[15][4] = {{0, 8, 0, 8}};
int table[8][8];
int sum[15];
double minQ = 1000001;

double calculateQ()
{
    double average = 0;
    double tempSum = 0;
    for (int i = 0; i < n; i++)
        tempSum += sum[i];
    average = tempSum / n;
    tempSum = 0;
    for (int i = 0; i < n; i++)
        tempSum += (sum[i] - average) * (sum[i] - average);
    return pow((tempSum / n), 0.5);
}

int calculateSum(int * position)
{
    int sum = 0;
    for (int i = position[0]; i < position[1]; i++)
        for (int j = position[2]; j < position[3]; j++)
            sum += table[i][j];
    return sum;
}

void divide(int toBeDivided)
{
    if (toBeDivided == 1) {
        sum[n - 1] = calculateSum(blocks[n - 1]);
        double tempQ = calculateQ();
        if (tempQ < minQ)
            minQ = tempQ;
        return;
    }
    int startX = blocks[n - toBeDivided][0], endX = blocks[n - toBeDivided][1];
    int startY = blocks[n - toBeDivided][2], endY = blocks[n - toBeDivided][3];
    for (int i = startX + 1; i < endX; i++) {
        {
            blocks[n - toBeDivided + 1][0] = i;
            blocks[n - toBeDivided + 1][1] = endX;
            blocks[n - toBeDivided + 1][2] = startY;
            blocks[n - toBeDivided + 1][3] = endY;
            blocks[n - toBeDivided][1] = i;
            sum[n - toBeDivided] = calculateSum(blocks[n - toBeDivided]);
            divide(toBeDivided - 1);
            blocks[n - toBeDivided][1] = endX;
        }
        {
            blocks[n - toBeDivided + 1][0] = startX;
            blocks[n - toBeDivided + 1][1] = i;
            blocks[n - toBeDivided + 1][2] = startY;
            blocks[n - toBeDivided + 1][3] = endY;
            blocks[n - toBeDivided][0] = i;
            sum[n - toBeDivided] = calculateSum(blocks[n - toBeDivided]);
            divide(toBeDivided - 1);
            blocks[n - toBeDivided][0] = startX;
        }
    }
    for (int i = startY + 1; i < endY; i++) {
        {
            blocks[n - toBeDivided + 1][2] = i;
            blocks[n - toBeDivided + 1][3] = endY;
            blocks[n - toBeDivided + 1][0] = startX;
            blocks[n - toBeDivided + 1][1] = endX;
            blocks[n - toBeDivided][3] = i;
            sum[n - toBeDivided] = calculateSum(blocks[n - toBeDivided]);
            divide(toBeDivided - 1);
            blocks[n - toBeDivided][3] = endY;
        }
        {
            blocks[n - toBeDivided + 1][2] = startY;
            blocks[n - toBeDivided + 1][3] = i;
            blocks[n - toBeDivided + 1][0] = startX;
            blocks[n - toBeDivided + 1][1] = endX;
            blocks[n - toBeDivided][2] = i;
            sum[n - toBeDivided] = calculateSum(blocks[n - toBeDivided]);
            divide(toBeDivided - 1);
            blocks[n - toBeDivided][2] = startY;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> table[i][j];

    divide(n);
    printf("%.3f", minQ);
    return 0;
}
