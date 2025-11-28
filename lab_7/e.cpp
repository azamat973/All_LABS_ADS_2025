#include <iostream>
using namespace std;

int sumRow(int a[][5000], int i, int m) {
    int s = 0;
    for (int j = 0; j < m; j++)
        s += a[i][j];
    return s;
}
bool greaterRow(int a[][5000], int i, int j, int m) {
    int sum1 = sumRow(a, i, m);
    int sum2 = sumRow(a, j, m);

    if (sum1 != sum2)
        return sum1 > sum2; 
    for (int k = 0; k < m; k++) {
        if (a[i][k] < a[j][k]) return true;
        if (a[i][k] > a[j][k]) return false;
    }
    return false; 
}

void sortRows(int a[][5000], int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!greaterRow(a, i, j, m)) {
                for (int k = 0; k < m; k++)
                    swap(a[i][k], a[j][k]);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int a[5000][5000];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    sortRows(a, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
