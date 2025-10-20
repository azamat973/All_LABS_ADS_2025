#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    int cnt; 
    Node *left, *right;
    Node(int k) : key(k), cnt(1), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    else root->cnt++; 
    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (root->cnt > 1) { 
            root->cnt--; 
            return root;
        }
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->cnt = temp->cnt;
        temp->cnt = 1;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int cnt(Node* root, int key) {
    if (!root) return 0;
    if (key < root->key) return cnt(root->left, key);
    if (key > root->key) return cnt(root->right, key);
    return root->cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    Node* root = nullptr;
    string op;
    int x;

    while (q--) {
        cin >> op >> x;
        if (op == "insert") root = insert(root, x);
        else if (op == "delete") root = deleteNode(root, x);
        else if (op == "cnt") cout << cnt(root, x) << "\n"; 
    }
}
