#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

vector<int> constructLps(const string &s) {
    int n = s.size();
    vector<int> lps(n);
    int len = 0, i = 1;
    while (i < n) {
        if (s[i] == s[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

int main() {
    int n; cin >> n;
    while (n--) {
        string s;
        ll k;
        cin >> s >> k;

        vector<int> lps = constructLps(s);
        ll overlap = lps.back();
        ll n = s.size();

        ll resik = n + (k - 1) * (n - overlap);
        cout << resik << "\n";
    }

    return 0;
}