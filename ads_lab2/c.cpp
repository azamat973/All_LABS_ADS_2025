#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

struct LinkedList {
    Node* head;
    LinkedList() { head = 0; }

    void add(int v) {
        Node* n = new Node;
        n->value = v;
        n->next = 0;
        if (!head) head = n;
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = n;
        }
    }

    void deleteEverySecond() {
        Node* cur = head;
        while (cur && cur->next) {
            Node* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            cur = cur->next;
        }
    }

    void print() {
        Node* cur = head;
        while (cur) {
            cout << cur->value;
            if (cur->next) cout << " ";
            cur = cur->next;
        }
    }
};

int main() {
    int n; 
    cin >> n;
    LinkedList l;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        l.add(x);
    }
    l.deleteEverySecond();
    l.print();
}
