#include <iostream>
#include <algorithm>
using namespace std;
#define SPACE "|     "
#define ROOT "ROOT"
#define MAX 31


int currentTestTime = 1;

void printBeginOfTest(bool hasOut, string currentFileName)
{
    if (!hasOut && currentFileName == ROOT) {
        if (currentTestTime != 1)
            cout << endl;
        cout << "DATA SET " << currentTestTime << ":" << endl;
    }
}

void print(int times, string fileName)
{
    for (int i = 0; i < times; i++)
        cout << SPACE;
    cout << fileName << endl;
}

bool getStructure(string currentFileName, int times)
{
    bool hasOutTest = false;
    bool hasOutStart = false;
    while (true){
        string currentFiles[MAX];
        for (int i = 0; ; ) {
            string current;
            cin >> current;
            if (current.empty())
                break;
            if (current[0] == 'd') {
                printBeginOfTest(hasOutTest, currentFileName);
                hasOutTest = true;
                if (!hasOutStart) {
                    print(times, currentFileName);
                    hasOutStart = true;
                }
                getStructure(current, times + 1);
            }
            if (current[0] == 'f')
                currentFiles[i++].assign(current);
            if (current[0] == ']') {
                printBeginOfTest(hasOutTest, currentFileName);
                if (!hasOutStart)
                    print(times, currentFileName);
                sort(currentFiles, currentFiles + i);
                for (int j = 0; j < i; j++)
                    print(times, currentFiles[j]);
                return true;
            }
            if (current[0] == '*') {
                printBeginOfTest(hasOutTest, currentFileName);
                if (!hasOutStart)
                    print(times, currentFileName);
                sort(currentFiles, currentFiles + i);
                for (int j = 0; j < i; j++)
                    print(times, currentFiles[j]);
                currentTestTime++;
                return true;
            }
            if (current[0] == '#')
                return false;
        }
    }
}

int main()
{
    bool isContinue = true;
    while (isContinue) {
        isContinue = getStructure(ROOT, 0);
    }
}

