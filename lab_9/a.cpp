#include <iostream>
#include <string>
using namespace std;
typedef long long ll;


int lps[1000005]; 
void Lps(const string &pat, int *lps){
    int  m = pat.size();
    lps[0] = 0;
    int len = 0;
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
bool kmp(const string &pat, const string &txt){
    int n = txt.size();
    int m =pat.size();
    Lps(pat,lps);
    int i =0,j =0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++; j++;
            if (j == m) {
                return true; 
            }
        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return false;
}

int main(){
    string a,b;
    cin >> a >> b;
    string repeated = a;
    int rep = 1;
    while(repeated.size() < b.size()){
        repeated +=a;
        rep++;
    }
    if (kmp(b, repeated)) {
        cout << rep;
        return 0;
    }

    repeated += a;
    rep++;

    if (kmp(b, repeated)) {
        cout << rep;
    } else {
        cout << -1;
    }
    
    return 0;
}