#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insert(root->left, x);
    else if (x > root->val) root->right = insert(root->right, x);
    return root;
}

int diameter = 0;

int dfs(Node* root) {
    if (!root) return 0;
    int lh = dfs(root->left);
    int rh = dfs(root->right);
    diameter = max(diameter, lh + rh);  
    return 1 + max(lh, rh);             
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    dfs(root);
    cout << diameter + 1 << "\n";

    return 0;
}
