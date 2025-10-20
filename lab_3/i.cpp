#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[1000]; 
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int x;
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (nums[i] == x) {
            cout << "Yes";
            return 0; 
        }
    }

    cout << "No";
    return 0;
}
