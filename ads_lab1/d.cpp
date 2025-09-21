#include <iostream>
#include <string>

using namespace std;

bool isBalanced(const string& s) {
    int n = s.size();
    if (n == 0) return true;
    

    if (s[0] == s[n - 1] && isBalanced(s.substr(1, n - 2)))
        return true;

    for (int i = 1; i < n; i++) {
        if (isBalanced(s.substr(0, i)) && isBalanced(s.substr(i)))
            return true;
    }

    return false;
}

int main() {
    string s;
    cin >> s;
    cout << (isBalanced(s) ? "YES" : "NO") << endl;
    return 0;
}
