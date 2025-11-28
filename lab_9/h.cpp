#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    long long ans = 0;

    for (int len = 1; len * 2 < n; len++) {
        bool ok = true;
        for (int i = 0; i < len; i++) {
            if (s[i] != s[i + len]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }

    cout << ans;
    return 0;
}
