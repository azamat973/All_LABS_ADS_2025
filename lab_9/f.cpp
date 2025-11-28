#include <iostream>
#include <string>
using namespace std;

int pi[1000005];   
int occurrences[1000005];

int main() {
    string text, pattern;
    cin >> text >> pattern;

    int n = text.size();
    int m = pattern.size();

    pi[0] = 0;
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];
        if (pattern[i] == pattern[j]) j++;
        pi[i] = j;
    }
    int j = 0;  
    int count = 0;

    for (int i = 0; i < n; i++) {  
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == m) {
            occurrences[count++] = i - m + 2;
            j = pi[j - 1];  
        }
    }
    cout << count << "\n";
    for (int i = 0; i < count; i++) {
        cout << occurrences[i] << " ";
    }

    return 0;
}
