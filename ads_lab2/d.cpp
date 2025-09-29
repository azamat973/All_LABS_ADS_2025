#include <iostream>

using namespace std ;
int main(){
    int n; cin >> n;
    int a[1000];

    for(int i = 0 ; i < n ; i++) cin >> a[i] ; 

    int freq[1000], used[1000];
    for(int i = 0 ; i < n ; i++){
        freq[i] = 0;
        used[i] = 0;
    }
    int m = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(used[i]) continue;
        int c = 1 ;
        for(int j = i+1; j < n ;j++){
            if (a[i] == a[j]) {
                c++;
                used[j] = 1;

            }
        }
        freq[i] = c;
        if (c > m) m = c;
    }
    int modes[1000], m = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i] && freq[i] == m) modes[m++] = a[i];
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (modes[i] < modes[j]) {
                int t = modes[i];
                modes[i] = modes[j];
                modes[j] = t;
            }
        }
    }
    for (int i = 0; i < m; i++) cout << modes[i] << " ";


    return 0;
}