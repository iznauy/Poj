#include <iostream>
#include <cstring>
using namespace std;
struct Block
{
    int color;
    int len;
};
Block segment[200];
int score[200][200][200];

int click_box(int start, int end, int extra_len)
{
    if (score[start][end][extra_len] > 0)
        return score[start][end][extra_len];
    int result = segment[end].len + extra_len;
    result *= result;
    if (start == end) {
        score[start][end][extra_len] = result;
        return score[start][end][extra_len];
    }
    result += click_box(start, end - 1, 0);
    for (int i = end - 1; i >= start; i--) {
        if (segment[i].color != segment[end].color)
            continue;
        int temp = click_box(start, i, segment[end].len + extra_len) + click_box(i + 1, end - 1, 0);
        result = max(result, temp);
    }
    score[start][end][extra_len] = result;
    return score[start][end][extra_len];
};

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, end = 0; // end means the number of blocks, and begins from zero.
        cin >> n;
        segment[end].len = 1;
        cin >> segment[end].color;
        for (int j = 1; j < n; j++) {
            int color;
            cin >> color;
            if (color == segment[end].color)
                segment[end].len++;
            else {
                end++;
                segment[end].color = color;
                segment[end].len = 1;
            }
        }
        memset(score, 0, sizeof(score));
        cout << "Case " << i + 1 << ": " << click_box(0, end, 0) << endl;
    }
    return 0;
}
