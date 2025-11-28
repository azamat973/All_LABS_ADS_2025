#include <iostream>
using namespace std;

void sort(int arr[],int n){
    for(int i = 0; i < n -1;i++){
        for(int j = 0 ; j < n-1-i ;j++){
            if(arr[j]>=arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }    
}

int main() {
    int a,b;
    cin >> a >> b;

    int arr1[100000];
    int arr2[100000];
    for(int i = 0 ; i < a;i++) cin >> arr1[i];
    for(int j = 0 ;j < b;j++) cin >>  arr2[j];

    sort(arr1,a);
    sort(arr2,b);

    for(int i = 0 ;i < a;i++){
        for(int j = 0; j < b;j++){
            if(arr1[i] == arr2[j]){
                cout << arr1[i] << " ";
                arr2[j] = -1000000;
                break;
            }
        }
    }
    
    return 0;
}
