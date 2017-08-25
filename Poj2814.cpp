#include <iostream>
using namespace std;

int clocks[9];
int sequence[9];
int minTimes = 27;

int main()
{
    for (int i = 0; i < 9; i++)
        cin >> clocks[i];

    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    for (int e = 0; e < 4; e++) {
                        for (int f = 0; f < 4; f++) {
                            for (int g = 0; g < 4; g++) {
                                for (int h = 0; h < 4; h++) {
                                    for (int i = 0; i < 4; i++) {
                                        int s = a + b + c + d + e + f + g + h + i;
                                        if (s > minTimes)
                                            continue;
                                        if (((a + b + d + clocks[0]) % 4 == 0) && ((a + b + c + e + clocks[1]) % 4 == 0)
                                                && ((b + c + f + clocks[2]) % 4 == 0) && ((a + d + e + g + clocks[3]) % 4 == 0)
                                                && ((a + c + e + g + i + clocks[4]) % 4 == 0) && ((c + e + f + i + clocks[5]) % 4 == 0)
                                                && ((d + g + h + clocks[6]) % 4 == 0) && ((e + g + h + i + clocks[7]) % 4 == 0)
                                                && ((f + h + i + clocks[8]) % 4 == 0)) {
                                            minTimes = s;
                                            sequence[0] = a, sequence[1] = b, sequence[2] = c;
                                            sequence[3] = d, sequence[4] = e, sequence[5] = f;
                                            sequence[6] = g, sequence[7] = h, sequence[8] = i;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < sequence[i]; j++)
            cout << i + 1 << " ";

    cout << endl;

}

