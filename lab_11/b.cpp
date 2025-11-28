#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    long long sum = 0;
    long long mn = 0;

    if (n >= 1) {
        long long x;
        cin >> x;
        sum = x;
        mn = x;
        for (long long i = 1; i < n; ++i) {
            cin >> x;
            sum += x;
            if (x < mn) mn = x;
        }
    }

    long long ans = 0;
    if (n <= 1) ans = 0;
    else ans = sum + (n - 2) * mn;

    cout << ans << '\n';
    return 0;
}
