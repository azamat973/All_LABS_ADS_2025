#include <iostream>
#include <string>
using namespace std;

int pi[1000005]; 

int main() {
    string t;
    cin >> t;
    int n = t.size();

    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && t[i] != t[j])
            j = pi[j - 1];
        if (t[i] == t[j]) j++;
        pi[i] = j;
    }

    int period = n - pi[n - 1];
    cout << period;

    return 0;
}
