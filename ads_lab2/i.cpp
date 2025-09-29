#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    Node(string s) : data(s), prev(NULL), next(NULL) {}
};

Node* head = NULL;
Node* tail = NULL;

void add_front(string s) {
    Node* node = new Node(s);
    if (!head) {
        head = tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    cout << "ok\n";
}

void add_back(string s) {
    Node* node = new Node(s);
    if (!tail) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    cout << "ok\n";
}

void erase_front() {
    if (!head) {
        cout << "error\n";
        return;
    }
    cout << head->data << "\n";
    Node* tmp = head;
    head = head->next;
    if (head) head->prev = NULL;
    else tail = NULL;
    delete tmp;
}

void erase_back() {
    if (!tail) {
        cout << "error\n";
        return;
    }
    cout << tail->data << "\n";
    Node* tmp = tail;
    tail = tail->prev;
    if (tail) tail->next = NULL;
    else head = NULL;
    delete tmp;
}

void front() {
    if (!head) cout << "error\n";
    else cout << head->data << "\n";
}

void back() {
    if (!tail) cout << "error\n";
    else cout << tail->data << "\n";
}

void clear() {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = NULL;
    cout << "ok\n";
}

int main() {
    string cmd;
    while (cin >> cmd) {
        if (cmd == "add_front") {
            string s; cin >> s;
            add_front(s);
        } else if (cmd == "add_back") {
            string s; cin >> s;
            add_back(s);
        } else if (cmd == "erase_front") {
            erase_front();
        } else if (cmd == "erase_back") {
            erase_back();
        } else if (cmd == "front") {
            front();
        } else if (cmd == "back") {
            back();
        } else if (cmd == "clear") {
            clear();
        } else if (cmd == "exit") {
            cout << "goodbye\n";
            break;
        }
    }
    return 0;
}
