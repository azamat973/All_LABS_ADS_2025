#include <iostream>

using namespace std;

void sortfunction(char s[],int n){
    for(int i = 0 ;i < n - 1;i++){
        for(int j = i + 1;j < n;j++){
            if(s[i] > s[j]){
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
            }
        }
    }
}

int main(){
    char s[100000];
    int n = 0;
    char c;
    while(cin.get(c)){
        if(c == '\n' || c == ' ')break;
        s[n] = c;
        n++;
    }
    sortfunction(s,n);

    for(int i = 0 ;i < n ; i++){
        cout << s[i];
    }
     cout << endl;
     
    return 0;
}