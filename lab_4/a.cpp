#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

bool checkPath(Node* root, const string& path) {
    Node* curr = root;
    for (char c : path) {
        if (!curr) return false;
        if (c == 'L') curr = curr->left;
        else curr = curr->right;
    }
    return curr != NULL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    while (m--) {
        string path;
        cin >> path;
        cout << (checkPath(root, path) ? "YES" : "NO") << "\n";
    }

    return 0;
}
