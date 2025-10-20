#include <iostream>
using namespace std;

int main(){
    int n,m;cin >> n >> m;
    int a[1000][1000];
    
    for(int i = 0;i < n ;i++){
        for(int j = 0;j < m;j++){
            cin >> a[i][j];
        }
    }
    
    for (int j = 0; j < m; j++) {        
        for (int i = 0; i < n - 1; i++) {  
            for (int k = i + 1; k < n; k++) {
                if (a[i][j] < a[k][j]) {    
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }

    for(int i = 0;i < n ;i++){
        for(int j = 0;j < m;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}