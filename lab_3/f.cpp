#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int p;
    cin >> p;
    int* m = new int[p];
    for(int i = 0; i < p; i++) cin >> m[i];
    
    for(int i = 0; i < p; i++) {
        int count = 0, sum = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] <= m[i]) {
                count++;
                sum += a[j];
            }
        }
        cout << count << " " << sum << endl;
    }
    
    delete[] a;
    delete[] m;
    return 0;
}