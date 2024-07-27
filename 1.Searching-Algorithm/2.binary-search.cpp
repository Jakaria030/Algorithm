#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int x){
    int left = 0;
    int right = n-1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] < x){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //array must be sorted

    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 5; //searching number

    int indx = binary_search(arr, n, x);

    if(indx != -1){
        cout << "Number is found at index: " << indx << endl;
    }else{
        cout << "Number is not found." << endl;
    }

    return 0;
}