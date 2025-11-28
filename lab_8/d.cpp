#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break; 

        string patterns[150];
        for (int i = 0; i < N; i++) {
            cin >> patterns[i];
        }

        string text;
        cin >> text;
        int n = text.size();
        int freq[150] = {0}; 
        for (int k = 0; k < N; k++) {
            string p = patterns[k];
            int m = p.size();

            for (int i = 0; i + m <= n; i++) {
                bool ok = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != p[j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) freq[k]++;
            }
        }
        int maxFreq = 0;
        for (int i = 0; i < N; i++) {
            if (freq[i] > maxFreq) maxFreq = freq[i];
        }
        cout << maxFreq << endl;
        for (int i = 0; i < N; i++) {
            if (freq[i] == maxFreq) {
                cout << patterns[i] << endl;
            }
        }
    }

    return 0;
}
