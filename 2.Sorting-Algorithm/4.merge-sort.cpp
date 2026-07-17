#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    int lsize = mid - left + 1;
    int rsize = right - mid;

    int L[lsize], R[rsize];
    
    for(i = 0; i < lsize; i++){
        L[i] = arr[left + i];
    }

    for(j = 0; j < rsize; j++){
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while(i < lsize && j < rsize){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < lsize){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < rsize){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right){
    if(left >= right) return;

    int mid = left + (right - left) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

int main(){
    int arr[] = {15, 5, 24, 8, 1, 3, 16, 10, 20};

    int n = sizeof(arr)/sizeof(arr[0]);

    merge_sort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}