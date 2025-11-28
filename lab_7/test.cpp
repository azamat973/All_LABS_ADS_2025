#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    vector <int> numbers(n);
    for(int i = 0; i < n;++i){
        cin >> numbers[i];
    }
    int k;
    cin >> k;

    if(binary_search(numbers.begin(),numbers.end(),k)){
        cout << "" << endl;
    }else{
        cout << "not found" << endl;
    }

    return 0;
}