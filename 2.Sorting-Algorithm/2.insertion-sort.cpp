#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i - 1;

        while(j >= 0 && temp < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    int arr[] = {5, 4, 10, 1, 6, 2};

    int n = sizeof(arr)/sizeof(arr[0]);

    insertion_sort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}