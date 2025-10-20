#include <iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int* a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--; r1--; l2--; r2--; 
        
        int count = 0;
        for(int j = 0; j < n; j++) {
            bool cond1 = (l1 <= j && j <= r1);
            bool cond2 = (l2 <= j && j <= r2);
            if((cond1 && !cond2) || (!cond1 && cond2)) {
                count++;
            }
        }
        cout << count << endl;
    }
    
    delete[] a;
    return 0;
}