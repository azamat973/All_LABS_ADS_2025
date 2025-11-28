#include <iostream>
using namespace std;
// Implement merge (descending order)
void merge(int arr[],int left,int mid ,int right){
    int n1 = mid - left +1;
    int n2 = right - mid;
    
    int L[10000],R[10000];
    
    for(int i =0 ; i < n1 ; i++){
        L[i] = arr[left +i];
    }
    for(int j =0; j < n2 ;j++){
        R[j] = arr[mid + 1 + j]; 
    }

    int i =0, j = 0 , k =left;
    
    while(i < n1 && j < n2){
        if(L[i] >=R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;k++;
    }
    while(j< n2){
        arr[k] = R[j];
        j++;k++;
    }

}