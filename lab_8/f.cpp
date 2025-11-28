#include <iostream>
#include <string>
using namespace std;

bool isUnique(string subs[], int count, string s) {
    for (int i = 0; i < count; i++) {
        if (subs[i] == s)
            return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    string subs[20000000]; 
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string sub = "";
            for (int k = i; k <= j; k++) {
                sub += s[k];  
            }

            if (isUnique(subs, cnt, sub)) {
                subs[cnt++] = sub; 
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}
