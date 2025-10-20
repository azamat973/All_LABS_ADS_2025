#include <iostream>
using namespace std;

bool canDeliver(long long *a, int n, long long capacity, long long flights) {
    long long needed = 0;
    for (int i = 0; i < n; i++) {
        needed += (a[i] + capacity - 1) / capacity; 
        if (needed > flights) return false;
    }
    return true;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    long long *a = new long long[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    long long l = 1, r = 0;
    for (int i = 0; i < n; i++) if (a[i] > r) r = a[i];

    long long answer = r;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (canDeliver(a, n, mid, k)) {
            answer = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << answer << endl;

    delete[] a;
    return 0;
}