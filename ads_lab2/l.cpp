#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(NULL) {}
};

void append(Node*& head, int v) {
    Node* node = new Node(v);
    if (!head) {
        head = node;
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

int findMaxSum(Node* head) {
    if (!head) return 0;

    int maxSum = head->val;
    int currentSum = head->val;
    head = head->next;

    while (head) {
        if (currentSum + head->val < head->val)
            currentSum = head->val;
        else
            currentSum += head->val;

        if (currentSum > maxSum)
            maxSum = currentSum;

        head = head->next;
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        append(head, x);
    }

    cout << findMaxSum(head) << "\n";
    return 0;
}
