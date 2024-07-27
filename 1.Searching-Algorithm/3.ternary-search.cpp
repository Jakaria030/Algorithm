#include<bits/stdc++.h>
using namespace std;

int ternary_search(int arr[], int n, int x){
    int left = 0;
    int right = n-1;

    while(left <= right){
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if(arr[mid1] == x){
            return mid1;
        }
        if(arr[mid2] == x){
            return mid2;
        }
        if(x < arr[mid1]){
            right = mid1 - 1;
        }else if(x > arr[mid2]){
            left = mid1 + 1;
        }else{
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //array must be sorted

    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 5; //searching number

    int indx = ternary_search(arr, n, x);

    if(indx != -1){
        cout << "Number is found at index: " << indx << endl;
    }else{
        cout << "Number is not found." << endl;
    }

    return 0;
}