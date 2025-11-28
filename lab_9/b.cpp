#include <iostream>
#include <string>
using namespace std;

int lps[1000005];      
int res[1000005];       

void constructLps(string &pat, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    int m = pat.size();
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

int search(string &pat, string &txt, int *res) {
    int n = txt.size();
    int m = pat.size();
    constructLps(pat, lps);

    int i = 0, j = 0;
    int count = 0;

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
            if (j == m) {
                res[count++] = i - j; 
                j = lps[j - 1];
            }
        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return count;
}

int main() {
    string password, text;
    int k;
    cin >> password >> k;
    cin >> text;

    int count = search(password, text, res);

    if (count >= k)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
