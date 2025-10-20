#include <iostream>

using namespace std;

int main() {
    int n;
    long long S;
    cin >> n >> S;

    long long *a = new long long[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    long long sum = 0;
    int l = 0;
    int minLen = n + 1;

    for (int r = 0; r < n; r++) {
        sum += a[r];

        while (sum >= S) {
            int len = r - l + 1;
            if (len < minLen) minLen = len;
            sum -= a[l];
            l++;
        }
    }

    cout << minLen << endl;

    delete[] a;
    return 0;
}