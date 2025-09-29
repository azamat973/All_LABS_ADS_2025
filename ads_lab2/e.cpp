#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAX = 1000;
    string words[MAX];
    int uniqueCount = 0;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        bool seen = false;
        for (int j = 0; j < uniqueCount; ++j) {
            if (words[j] == s) {
                seen = true;
                break;
            }
        }

        if (!seen) {
            words[uniqueCount++] = s;
        }
    }

    for (int i = 0; i < uniqueCount - 1; ++i) {
        for (int j = i + 1; j < uniqueCount; ++j) {
            if (words[j] < words[i]) {
                string tmp = words[i];
                words[i] = words[j];
                words[j] = tmp;
            }
        }
    }

    cout << "All in all: " << uniqueCount << "\n";
    cout << "Students:\n";
    for (int i = uniqueCount - 1; i >=0; --i) {
        cout << words[i] << "\n";
    }

    return 0;
}
