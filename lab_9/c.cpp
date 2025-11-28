#include <iostream>
#include <string>
using namespace std;

int lps[20005]; 

void buildLPS(const string &pat) {
    int m = pat.size();
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP(const string &text, const string &pat) {
    int n = text.size();
    int m = pat.size();

    buildLPS(pat);

    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;
        }
        if (j == m) {
            return i - j; 
        }
        else if (i < n && text[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return -1; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    cin >> A >> B;

    int n = A.size();

    string AA = A + A;

    int pos = KMP(AA, B);
    if (pos == -1) {
        cout << -1;
    } else {
        int shift = (n - (pos % n)) % n;
        cout << shift;
    }

    return 0;
}
