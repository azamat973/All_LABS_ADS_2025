#include <iostream>
#include <string>

using namespace std;
int main(){
    string s;cin >> s;
    int q; cin >> q;
    
    int L[50000],R[50000];
    for(int i = 0 ; i < q;i++){
        cin >> L[i] >> R[i];
    }
    int n = s.size();
    int results[50000];
    for(int k = 0; k < q;k++){
        int l = L[k] - 1;
        int r = R[k] -1;
        string sub = s.substr(l, r - l + 1);
        int m = sub.size();
        int count = 0;
        
        for(int i = 0; i+m <=n;i++){
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (s[i + j] != sub[j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) count++;
        }
        results[k] = count;
    }
    for (int i = 0; i < q; i++) {
        cout << results[i] << "\n";
    }
    return 0;   
}
