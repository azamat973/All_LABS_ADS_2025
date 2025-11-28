#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string lines[10000]; 
    int lineCount = 0;

    for (int i = 0; i <= n; i++) {
        getline(cin, lines[lineCount++]);
    }

    for (int i = 0; i < lineCount; i++) {
        string line = lines[i];
        string words[10000];
        int count = 0;
        string word = "";

        for (int j = 0; j <= (int)line.size(); j++) {
            if (j == (int)line.size() || line[j] == ' ') {
                if (word != "") {
                    words[count++] = word;
                    word = "";
                }
            } else {
                word += line[j];
            }
        }

        for (int a = 0; a < count - 1; a++) {
            for (int b = 0; b < count - a - 1; b++) {
                if (words[b].size() > words[b + 1].size()) {
                    string temp = words[b];
                    words[b] = words[b + 1];
                    words[b + 1] = temp;
                }
            }
        }

        for (int k = 0; k < count; k++) {
            cout << words[k] << " ";
        }
        cout << endl;
    }

    return 0;
}
