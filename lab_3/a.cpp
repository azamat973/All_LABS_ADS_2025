#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int* values = new int[t];
    for(int i = 0; i < t; i++) cin >> values[i];
    int n, m;
    cin >> n >> m;
    int** arr = new int*[n];
    for(int i = 0; i < n; i++) arr[i] = new int[m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for(int k = 0; k < t; k++) {
        bool found = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == values[k]) {
                    cout << i << " " << j << endl;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(!found) cout << -1 << endl;
    }
    for(int i = 0; i < n; i++) delete[] arr[i];
    delete[] arr;
    delete[] values;
    return 0;
}