#include<bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int n, int x){
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    
    return -1;
}

int main(){
    int arr[] = {7, 17, 8, 12, 15, 10, 5, 9, 13, 10};

    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 5; //searching number

    int indx = linear_search(arr, n, x);

    if(indx != -1){
        cout << "Number is found at index: " << indx << endl;
    }else{
        cout << "Number is not found." << endl;
    }

    return 0;
}