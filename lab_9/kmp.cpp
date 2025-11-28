#include <iostream>
#include <vector>

using namespace std;

vector<int> cumpLPS(string pat){
    int m = pat.size();
    vector<int> lps(m,0);
    int len  = 0;
    int i =1;
    
    while(i < m ){
        if(pat[i] ==pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0){
                len  = lps[len -1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMP(string pat, string text){
    int n = text.size();
    int m = pat.size();
    vector<int> lps  = cumpLPS(pat);
    
    int i = 0;
    int j = 0;

    while(i < n){
        if(text[i] == pat[j]){
            i++,j++;
        }
        if(j == m){
            cout << "Pattern found at index " << (i - j) << endl;
            j = lps[j -1];
        }else if (i < n && text[i] != pat[i]){
            if(j !=0)
                j = lps[j-1];
            else    
                i++; 
        }
    }
}

int main(){
    string text,pattern;
    cout << "Text" ;
    cin >> text;
    cout << "Pattern";
    cin >> pattern;
    KMP(text,pattern);
    return 0;
}
