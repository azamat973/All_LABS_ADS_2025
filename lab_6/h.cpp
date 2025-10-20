#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    char arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    char letter;
    cin >> letter;
    char result = arr[0]; 

    for (int i = 0; i < n; i++) {
        if (arr[i] > letter) {
            result = arr[i];
            break;
        }
    }

    cout << result << endl;
    return 0;
}
