#include <iostream>
using namespace std;
struct Node
{
    int num;
    Node * next;
    Node(int num, Node * next)
            : num(num), next(next) {};
};

int main()
{
    int N, M;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        Node * current = new Node(1, NULL), * head = current;
        for (int i = 2; i <= N; i++) {
            current->next = new Node(i, NULL);
            current = current->next;
        }
        current->next = head;
        while (current->next != current) {
            for (int i = 1; i < M; i++)
                current = current->next;
            Node * temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        cout << current->num << endl;
    }
    return 0;
}