#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int board[9][9];
bool rows[9][10];
bool cols[9][10];
bool blocks[9][10];
struct EmptyBox
{
    int row, col;
    EmptyBox(int r, int c):
            row(r), col(c) {};
};
vector<EmptyBox> emptyBoxs;

inline int getBlock(int row, int col)
{
    return (row / 3) * 3 + col / 3;
}

inline bool canSet(int row, int col, int num)
{
    return !rows[row][num] && !cols[col][num] && !blocks[getBlock(row, col)][num];
}

void mark(int row, int col, int num)
{
    if (num != 0) {
        rows[row][num] = cols[col][num] = blocks[getBlock(row, col)][num] = true;
        board[row][col] = num;
    } else {
        int temp = board[row][col];
        rows[row][temp] = cols[col][temp] = blocks[getBlock(row, col)][temp] = false;
        board[row][col] = 0;
    }
}

bool dfs(int n)
{
    if (n <= 0)
        return true;
    for (int num = 1; num <= 9; num++) {
        EmptyBox emptyBox = emptyBoxs[n - 1];
        int row = emptyBox.row, col = emptyBox.col;
        if (canSet(row, col, num)) {
            mark(row, col, num);
            if (dfs(n - 1))
                return true;
            mark(row, col, 0);
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        memset(rows, false, sizeof(rows));
        memset(cols, false, sizeof(cols));
        memset(blocks, false, sizeof(blocks));
        emptyBoxs.clear();
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                char temp;
                cin >> temp;
                board[i][j] = temp - '0';
                if (board[i][j] != 0)
                    mark(i, j, board[i][j]);
                else
                    emptyBoxs.push_back(EmptyBox(i, j));
            }
        dfs(emptyBoxs.size());
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j];
            cout << endl;
        }
    }
    return 0;
}
