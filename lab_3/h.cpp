#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long *a = new long long[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    while (m--) {
        long long line;
        cin >> line;

        
        int l = 0, r = n - 1, ans = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (line <= a[mid]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans + 1 << endl; 
    }

    delete[] a;
    return 0;
}