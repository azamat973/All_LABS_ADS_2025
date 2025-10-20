#include <iostream>
#include <string>
using namespace std;

struct Student {
    string last;
    string first;
    double gpa;
};

double gradeToGpa(string g) {
    if (g == "A+") return 4.0;
    if (g == "A") return 3.75;
    if (g == "B+") return 3.5;
    if (g == "B") return 3.0;
    if (g == "C+") return 2.5;
    if (g == "C") return 2.0;
    if (g == "D+") return 1.5;
    if (g == "D") return 1.0;
    if (g == "F") return 0.0;
    return 0.0;
}

// Қолмен quick sort
void quickSort(Student arr[], int left, int right) {
    int i = left, j = right;
    Student pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (
            (arr[i].gpa < pivot.gpa) ||
            (arr[i].gpa == pivot.gpa && arr[i].last < pivot.last) ||
            (arr[i].gpa == pivot.gpa && arr[i].last == pivot.last && arr[i].first < pivot.first)
        ) i++;
        while (
            (arr[j].gpa > pivot.gpa) ||
            (arr[j].gpa == pivot.gpa && arr[j].last > pivot.last) ||
            (arr[j].gpa == pivot.gpa && arr[j].last == pivot.last && arr[j].first > pivot.first)
        ) j--;
        if (i <= j) {
            Student tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++; j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

void printGpa(double g) {
    int whole = (int)g;
    int frac = (int)((g - whole) * 1000 + 0.5);
    if (frac == 1000) { whole++; frac = 0; }
    cout << whole << ".";
    if (frac < 10) cout << "00";
    else if (frac < 100) cout << "0";
    cout << frac;
}

int main() {
    int n;
    cin >> n;
    Student s[100005];

    for (int i = 0; i < n; i++) {
        string last, first;
        int m;
        cin >> last >> first >> m;
        double sum = 0, credits = 0;

        for (int j = 0; j < m; j++) {
            string grade;
            int c;
            cin >> grade >> c;
            sum += gradeToGpa(grade) * c;
            credits += c;
        }

        s[i].last = last;
        s[i].first = first;
        s[i].gpa = sum / credits;
    }

    quickSort(s, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << s[i].last << " " << s[i].first << " ";
        printGpa(s[i].gpa);
        cout << "\n";
    }

    return 0;
}