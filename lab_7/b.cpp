#include <iostream>

using namespace std;

int main(){
    long long n,m;
    cin >> n;
    int a[100000];
    for(int i =0;i < n ;++i){
        cin >> a[i];
    }
    cin >> m ;
    int b[100000];
    for(int i = 0;i < m;++i){
        cin >> b[i];
    }
    int c[20000];
    int total = n+m;
    for(int i = 0 ; i < n;++i)
        c[i] = a[i];
    for(int i = 0; i < m;++i) 
        c[n+1] = b[i];

    for(int i = 0 ;i < total -1;++i){
        for(int  j = 0; j < total -i -1;++j){
            if(c[j] > c[j+1]){
                int tmp = c[j];
                c[j] = c[j+1];
                c[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < total; ++i)
        cout << c[i] << " ";
    
    return 0;
}