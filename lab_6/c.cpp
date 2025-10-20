#include <iostream>
#include <string>
using namespace std;


void print(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int* arr, int beg, int end){
    srand(time(0));
    int pivot = beg + (rand()%(end-beg+1));
    swap(arr[pivot],arr[end]);
    int i = beg - 1;
    for (int j = beg; j < end; j++)
    {
        if(arr[j]<arr[end]){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

void quickSort(int* arr,int beg, int end){  
    if(beg<end){
        int part = partition(arr,beg,end);
        quickSort(arr,beg,part-1);
        quickSort(arr,part+1,end); 
    }
}


void merge(int* arr, int beg, int mid, int end){
    int* left = new int[mid-beg+1+1];
    int* right = new int[end-mid+1];

    for (int i = beg; i <= mid; i++)
    {
        left[i-beg] = arr[i];
    }

    for (int i = mid+1; i <= end; i++)
    {
        right[i-(mid+1)] = arr[i];
    }

    left[mid-beg+1] = 2147483647;
    right[end-mid] = 2147483647;


    int i = 0, j=0, k = beg;

    while(k<=end){
        if(left[i]<right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    

    delete[] left;
    delete[] right;
}

void mergeSort(int* arr, int beg, int end){
    if(beg<end){
        int mid = (beg+end)/2;
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    mergeSort(arr,0,n - 1);
    long long min_dif = 2147483647;
    for(int i=1;i<n;i++){
        int diff = arr[i] - arr[i - 1];
        if(diff < min_dif){
            min_dif = diff;
        }
    }
    for(int i=1;i < n; i++){
        if(arr[i] - arr[i-1] == min_dif){
            cout << arr[i - 1] << " " << arr[i] << " ";
        }
    }
    return 0;
    
}