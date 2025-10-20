#include <iostream>

using namespace std;

struct date{
    int day;
    int month;
    int year;
};

bool aza(date a ,date b){
    if (a.year < b.year) return true;
    if (a.year > b.year) return false;
    if (a.month < b.month) return true;
    if (a.month > b.month) return false;

    return a.day < b.day;
}

int main(){
    int n ;
    cin >> n;
    date arr[100000];
    
    for(int i = 0;i < n ; i++){
        char d1,d2;
        cin >> arr[i].day >> d1 >> arr[i].month >> d2 >> arr[i].year;
    }

    for(int i  = 0; i <n; i++){
        int minindex = i;
        for(int j = i+1; j < n ;j++){
            if(aza(arr[j],arr[minindex])){
                minindex = j;
            }
        }
        date temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }

    for(int i = 0 ; i < n; i++){
        if(arr[i].day < 10) cout << "0";
        cout << arr[i].day << "-";
        if(arr[i].month < 10) cout << "0";
        cout << arr[i].month << "-";
        cout << arr[i].year << "\n";
    }

    return 0;
}