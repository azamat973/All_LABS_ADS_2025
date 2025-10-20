#include <iostream>
using namespace std;

void azz(long long arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        long long temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        azz(arr, n, largest);
    }
}

void build_heap(long long arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        azz(arr, n, i);
}

int main() {
    int n, m;
    cin >> n >> m;
    long long arr[100000]; 
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build_heap(arr, n);
    long long total = 0;

    for (int i = 0; i < m; i++) {
        if (arr[0] == 0)
            break;

        total += arr[0];
        arr[0] -= 1;
        azz(arr, n, 0);
    }

    cout << total;
    return 0;
}
