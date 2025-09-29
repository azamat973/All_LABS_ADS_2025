#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int freq[26] = {0};
        string q = "";
        for (int i = 0; i < N; i++) {
            char ch;
            cin >> ch;
            freq[ch - 'a']++;
            q.push_back(ch);
            int j = 0;
            while (j < (int)q.size() && freq[q[j] - 'a'] > 1) j++;
            if (j == (int)q.size()) cout << -1 << " ";
            else cout << q[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}