#include <iostream>
using namespace std;

int N, M;

struct Node
{
    int num;
    Node * next;
    Node(int num, Node * next)
            : num(num), next(next) {};
};

int main()
{
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        if (M == 1) {
            cout << N << endl;
            continue;
        }
        Node node(1, NULL);
        Node * current = &node, * head = &node;
        for (int i = 2; i <= N; i++) {
            current->next = new Node(i, NULL);
            current = current->next;
        }
        current->next = head;
        while (current->next != current) {
            for (int i = 1; i < M; i++)
                current = current->next;
            current->next = current->next->next;
        }
        cout << current->num << endl;
    }
    return 0;
}