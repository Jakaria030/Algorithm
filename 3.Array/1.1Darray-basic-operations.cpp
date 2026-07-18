#include <bits/stdc++.h>
using namespace std;

// Insertion
int insertion(int arr[], int n, int value, int position){

    if(position < 1 || position > n + 1){
        cout << "Invalid position!" << endl;
        return n;
    }

    for(int i = n; i >= position; i--){
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = value;
    
    return n + 1;
}

// Update
void update(int arr[], int n, int value, int position){

    if(position < 1 || position > n){
        cout << "Invalid position!" << endl;
        return;
    }

    arr[position - 1] = value;
}

// Deletion
int deletion(int arr[], int n, int position){

    if(position < 1 || position > n){
        cout << "Invalid position!" << endl;
        return n;
    }

    for(int i = position-1; i < n-1; i++){
        arr[i] = arr[i+1];
    }

    return n - 1;
}

// Traversal
void traverse(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    int arr[100], n, value, position;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }


    // ========== Traversal ==========
    cout << "\nCurrent Array: ";
    traverse(arr, n);


    // ========== Insertion ==========
    cout << "\n----- Insertion -----" << endl;
    cout << "Enter the value to insert: ";
    cin >> value;

    cout << "Enter the position (1 to " << n + 1 << "): ";
    cin >> position;

    n = insertion(arr, n, value, position);

    cout << "\nArray after insertion: ";
    traverse(arr, n);


    // ========== Update ==========
    cout << "\n----- Update -----" << endl;
    cout << "Enter the postion to update (1 to " << n << "): ";
    cin >> position;

    cout << "Enter new value: ";
    cin >> value;

    update(arr, n, value, position);

    cout << "\nArray after update: ";
    traverse(arr, n);


    // ========== Deletion ==========
    cout << "\n----- Deletion -----" << endl;
    cout << "Enter the position to delete (1 to " << n << "): ";
    cin >> position;

    n = deletion(arr, n, position);

    cout << "\nArray after deletion: ";
    traverse(arr, n);

    return 0;
}