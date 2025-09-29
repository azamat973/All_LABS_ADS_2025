#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;

    int bestIndex = 0;
    long long bestDist = arr[0] - x;
    if (bestDist < 0) bestDist = -bestDist;

    for (int i = 1; i < n; i++) {
        long long d = arr[i] - x;
        if (d < 0) d = -d;
        if (d < bestDist) {
            bestDist = d;
            bestIndex = i;
        }
    }

    cout << bestIndex << "\n";

    delete[] arr;
    return 0;
}
