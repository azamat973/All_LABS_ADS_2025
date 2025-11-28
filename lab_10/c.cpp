#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int path[10000000];
    int steps = 0;

    path[steps++] = b;

    while (b > a) {
        if (b % 2 == 0)
            b /= 2;
        else
            b++;
        path[steps++] = b;
    }

    while (b < a) {
        b++;
        path[steps++] = b;
    }

    cout << steps - 1 << endl;
    for (int i = steps - 2; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;

    return 0;
}
