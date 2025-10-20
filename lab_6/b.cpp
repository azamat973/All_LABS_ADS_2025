#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[1000], b[1000], c[2000];
    int k = 0; 

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                c[k++] = a[i];
                b[j] = -1000000000; 
                break;
            }
        }
    }

    // (selection sort)
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (c[i] > c[j]) {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}
