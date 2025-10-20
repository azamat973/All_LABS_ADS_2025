#include <iostream>
using namespace std;

const int MAXN = 500000; 
long long heap[MAXN];
int heapSize = 0;

void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            long long tmp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = tmp;
            i = parent;
        } else break;
    }
}

void heapifyDown(int i) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heapSize && heap[left] < heap[smallest]) smallest = left;
        if (right < heapSize && heap[right] < heap[smallest]) smallest = right;

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

    int n;
    long long m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }
    heapSize = n;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyDown(i);

    long long ops = 0;
    bool possible = true;

    while (heapSize > 0 && heap[0] < m) {
        if (heapSize < 2) {
            possible = false;
            break;
        }

        long long min1 = heappop();
        long long min2 = heappop();
        long long new_val = min1 + 2 * min2;

        heappush(new_val);
        ops++;
    }

    if (possible) cout << ops << "\n";
    else cout << -1 << "\n";

    return 0;
}
