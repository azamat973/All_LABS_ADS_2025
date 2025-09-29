#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int v) : val(v), prev(NULL), next(NULL) {}
};

Node* head = NULL;
Node* tail = NULL;

Node* inserts(int x, int p) {
    Node* node = new Node(x);
    if (!head) {
        head = tail = node;
        return head;
    }
    if (p == 0) { 
        node->next = head;
        head->prev = node;
        head = node;
        return head;
    }
    Node* cur = head;
    for (int i = 0; i < p - 1; i++) cur = cur->next;
    node->next = cur->next;
    node->prev = cur;
    if (cur->next) cur->next->prev = node;
    else tail = node;
    cur->next = node;
    return head;
}

Node* removeNode(int p) {
    if (!head) return NULL;
    Node* cur = head;
    for (int i = 0; i < p; i++) cur = cur->next;
    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    else tail = cur->prev;
    delete cur;
    return head;
}

void print() {
    if (!head) {
        cout << -1 << "\n";
        return;
    }
    Node* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << " ";
        cur = cur->next;
    }
    cout << "\n";
}

Node* replaceNode(int p1, int p2) {
    if (!head) return head;
    Node* cur = head;
    for (int i = 0; i < p1; i++) cur = cur->next;

    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    else tail = cur->prev;

    if (p2 == 0) {
        cur->next = head;
        cur->prev = NULL;
        if (head) head->prev = cur;
        else tail = cur;
        head = cur;
        return head;
    }
    Node* pos = head;
    for (int i = 0; i < p2 - 1; i++) pos = pos->next;
    cur->next = pos->next;
    cur->prev = pos;
    if (pos->next) pos->next->prev = cur;
    else tail = cur;
    pos->next = cur;
    return head;
}

Node* reverseList() {
    Node* cur = head;
    Node* tmp = NULL;
    while (cur) {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev;
    }
    if (tmp) {
        tmp = tmp->prev;
        tail = head;
        head = tmp;
    }
    return head;
}

Node* cyclic_left(int x) {
    if (!head || !head->next) return head;
    for (int i = 0; i < x; i++) {
        Node* first = head;
        head = head->next;
        head->prev = NULL;
        tail->next = first;
        first->prev = tail;
        first->next = NULL;
        tail = first;
    }
    return head;
}

Node* cyclic_right(int x) {
    if (!head || !head->next) return head;
    for (int i = 0; i < x; i++) {
        Node* last = tail;
        tail = tail->prev;
        tail->next = NULL;
        last->prev = NULL;
        last->next = head;
        head->prev = last;
        head = last;
    }
    return head;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cmd;
    while (cin >> cmd) {
        if (cmd == 0) break;
        if (cmd == 1) {
            int x, p; cin >> x >> p;
            head = inserts(x, p);
        } else if (cmd == 2) {
            int p; cin >> p;
            head = removeNode(p);
        } else if (cmd == 3) {
            print();
        } else if (cmd == 4) {
            int p1, p2; cin >> p1 >> p2;
            head = replaceNode(p1, p2);
        } else if (cmd == 5) {
            head = reverseList();
        } else if (cmd == 6) {
            int x; cin >> x;
            head = cyclic_left(x);
        } else if (cmd == 7) {
            int x; cin >> x;
            head = cyclic_right(x);
        }
    }
    return 0;
}
