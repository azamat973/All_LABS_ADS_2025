#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int* a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int left = 0, right = 1000000000, result = 0;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int blocks = 1, maxGhoul = a[0];
        for(int i = 1; i < n; i++) {
            if(a[i] > maxGhoul) maxGhoul = a[i];
            if(i - blocks >= k && maxGhoul > mid) {
                blocks++;
                maxGhoul = a[i];
            }
        }
        if(blocks <= k) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << result << endl;
    
    delete[] a;
    return 0;
}