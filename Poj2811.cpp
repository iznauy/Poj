#include <iostream>
using namespace std;
int lights[6][8] = {0};
int pressed[6][8] = {0};

bool success()
{
    for (int i = 2; i < 6; i++)
        for (int j = 1; j < 7; j++)
            pressed[i][j] = (pressed[i - 1][j] + pressed[i - 2][j] + pressed[i - 1][j - 1] + pressed[i - 1][j + 1] + lights[i - 1][j]) % 2;

    for (int j = 1; j < 7; j++)
        if ((pressed[4][j] + pressed[5][j - 1] + pressed[5][j + 1] + pressed[5][j]) % 2 != lights[5][j])
            return false;

    return true;
}


void guess()
{
    for (int i = 0; i < 64; i++) {
        pressed[1][1] = i;
        int c = 1;
        while (pressed[1][c] >= 2) {
            pressed[1][c + 1] = pressed[1][c] / 2;
            pressed[1][c] = pressed[1][c] % 2;
            c++;
        }

        if (success()) {
            for (int i = 1; i < 6; i++) {
                for (int j = 1; j < 7; j++)
                    cout << pressed[i][j] << " ";
                cout << endl;
            }
            break;
        }
    }
}

int main()
{
    for (int i = 1; i < 6; i++)
        for (int j = 1; j < 7; j++)
            cin >> lights[i][j];

    guess();

}


