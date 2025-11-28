#include <iostream>
#include <string>
using namespace std;

bool myfunction(const string &s, const string &w, int pos){
    for(int i = 0 ;i < w.size();i++){
        if(s[pos + i] != w[i])
            return false;
        return true;
    }
    return true;
}


int main(){
    string s1,s2,w;
    cin >> s1 >> s2 >> w;

    int n1 = s1.size(), n2 = s2.size(), m = w.size();
    int count = 0;
    for(int i =0; i + m <= n1 && i + m <= n2; i++){
        if (myfunction(s1, w, i) && myfunction(s2, w, i))
            count++;
    }
    cout << count << endl;
    return 0;
}