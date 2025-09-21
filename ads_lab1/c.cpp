#include <bits/stdc++.h>
using namespace std;

string processString(const string &s) {
    string result;
    for (char ch : s) {
        if (ch == '#') {
            if (!result.empty()) {
                result.pop_back();
            }
        } else {
            result.push_back(ch);
        }
    }
    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (processString(s1) == processString(s2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
