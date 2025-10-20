#include <iostream>
using namespace std;

const int MAXN = 10000000;  
long long heap[MAXN];
int heapSize = 0;
int M;
long long total = 0;

void heapifyUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] > heap[i]) {
            long long tmp = heap[p];
            heap[p] = heap[i];
            heap[i] = tmp;
            i = p;
        } else break;
    }
}

void heapifyDown(int i) {
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < heapSize && heap[l] < heap[smallest]) smallest = l;
        if (r < heapSize && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            long long tmp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = tmp;
            i = smallest;
        } else break;
    }
}

void heappush(long long x) {
    heap[heapSize] = x;
    heapifyUp(heapSize);
    heapSize++;
}

long long heappop() {
    long long root = heap[0];
    heapSize--;
    heap[0] = heap[heapSize];
    heapifyDown(0);
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q >> M;

    string cmd;
    for (int i = 0; i < Q; i++) {
        cin >> cmd;

        if (cmd == "insert") {
            long long x;
            cin >> x;

            if (heapSize < M) {
                heappush(x);
                total += x;
            } else if (x > heap[0]) {
                total -= heap[0];
                heappop();
                heappush(x);
                total += x;
            }
        } 
        else if (cmd == "print") {
            cout << total << "\n";
        }
    }
    return 0;
}
