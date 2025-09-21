#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;
    char c;
    int x;

    while (cin >> c) {
        if (c == '!') break;
        if (c == '+') { cin >> x; d.push_front(x); }
        else if (c == '-') { cin >> x; d.push_back(x); }
        else if (c == '*') {
            if (d.empty()) cout << "error\n";
            else if (d.size() == 1) { cout << d.front() * 2 << "\n"; d.pop_front(); }
            else { cout << d.front() + d.back() << "\n"; d.pop_front(); d.pop_back(); }
        }
    }
}
