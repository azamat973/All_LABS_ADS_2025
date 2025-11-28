#include <iostream>
#include <string>
using namespace std;

const long long MOD = 1000000007;
const int BASE = 31;

long long gethash(string s){
    long long h = 0;
    for(int i = 0;i < s.size();i++){
        h = (h*BASE + (s[i] - 'a' + 1)) % MOD; 
    }
    return h;
}

int main(){
    string text, pattern;
    cin >> text >> pattern;

    int n  = text.size();
    int m = pattern.size();
    long long hashPattern = gethash(pattern);
    long long hashText = 0;
    long long power = 1;

    for(int i= 0;i < m;i++){
        hashText = (hashText * BASE +(text[i] - 'a' + 1)) % MOD;
        if(i < m-1){
            power  = (power * BASE )% MOD;
        }
    }

    bool found  = false;
    for(int  i = 0; i <= n-m;i++){
        if(hashText == hashPattern){
            bool equal =true;
            for(int j = 0; j< m ;j++){
                if(text[i+j] != pattern[i]){
                    equal = false;
                    break;
                }
            }
            if(equal){
                cout << i + 1 << " ";
                found  = true;
            }
        }
        if(i < n-m){
            hashText = (hashText - (text[i] - 'a' + 1) * power) % MOD;
            if(hashText < 0)
                hashText += MOD;
            hashText = (hashText * BASE + (text[i + m] -'a' + 1)) % MOD;
        }
    }
    if(!found)
        cout << "Not found";
        
    cout  << endl;
    return 0;
}