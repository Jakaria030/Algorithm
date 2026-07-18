#include<bits/stdc++.h>
using namespace std;

void counting_sort(int arr[], int n){
    int count[10] = {0};

    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    for(int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }

    int temp[n];

    for(int i = n-1; i >= 0; i--){
        temp[--count[arr[i]]] = arr[i];
    }

    for(int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
}

int main(){
    int arr[] = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};

    int n = sizeof(arr)/sizeof(arr[0]);

    counting_sort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}