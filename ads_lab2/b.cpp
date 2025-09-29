#include <iostream>

using namespace std;


int main(){
    int t,b;
    cin >> t >> b;
    char strings[1000000][10];
    for(int i=0;i<t;i++){
        cin >> strings[i];
    }
    for(int i=b; i<t;i++){
        cout << strings[i]<< " ";
    }
    for(int i=0; i<b;i++){
        cout << strings[i]<< " ";
    }
    return 0;
    
}