#include <iostream>
using namespace std;

struct Pair {
    string oldName;
    string newName;
};

int main() {
    int n;
    cin >> n;
    Pair arr[1000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].oldName >> arr[i].newName;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i].oldName == "") continue;
        bool changed = true;
        while (changed) {
            changed = false;
            for (int j = 0; j < n; j++) {
                if (i == j || arr[j].oldName == "") continue;

                if (arr[i].newName == arr[j].oldName) {
                    arr[i].newName = arr[j].newName;
                    arr[j].oldName = "";
                    changed = true;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].oldName != "") count++;
    }

    cout << count << endl;

    // (selection sort)
    for (int i = 0; i < n - 1; i++) {
        if (arr[i].oldName == "") continue;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].oldName == "") continue;
            if (arr[i].oldName > arr[j].oldName) {
                Pair tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i].oldName != "")
            cout << arr[i].oldName << " " << arr[i].newName << endl;
    }

    return 0;
}
