#include <iostream>
#include <string>
using namespace std;

string longestCommonSubstring(string arr[], int k) {
    int minIndex = 0;
    for (int i = 1; i < k; i++) {
        if (arr[i].size() < arr[minIndex].size())
            minIndex = i;
    }

    string base = arr[minIndex];
    int n = base.size();
    for (int len = n; len > 0; len--) {
        for (int i = 0; i + len <= n; i++) {
            string sub = base.substr(i, len);
            bool found = true;

            for (int j = 0; j < k; j++) {
                if (j == minIndex) continue;

                bool inside = false;
                for (int p = 0; p + len <= (int)arr[j].size(); p++) {
                    int q;
                    for (q = 0; q < len; q++) {
                        if (arr[j][p + q] != sub[q])
                            break;
                    }
                    if (q == len) {
                        inside = true;
                        break;
                    }
                }

                if (!inside) {
                    found = false;
                    break;
                }
            }

            if (found) return sub; 
        }
    }
    return "";
}

int main() {
    int k;
    cin >> k;
    string arr[100];
    for (int i = 0; i < k; i++) cin >> arr[i];

    cout << longestCommonSubstring(arr, k) << "\n";
    return 0;
}
