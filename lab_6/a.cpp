#include <iostream>

using namespace std;

bool aza(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
    int n ;cin >> n ;
    char s[100000];
    
    for(int i = 0 ; i < n ;i++){
        cin >> s[i];
    }
    //selection sort 
    for(int i = 0 ;i < n - 1;i++){
        for(int j = i + 1;j < n;j++){
            if(s[i] > s[j]){
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
            }
        }
    }
    for(int i = 0 ;i < n ; i++){
        if(aza(s[i])) cout << s[i];
    }
    for(int i = 0 ;i < n ; i++){
        if(!aza(s[i])) cout << s[i];
    }
    cout << endl;
    return 0;
}