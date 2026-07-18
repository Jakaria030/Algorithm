#include<bits/stdc++.h>
using namespace std;

// Insert Row
int insert_row(int arr[][100], int row, int col, int values[], int position){

    if(position < 1 || position > row + 1){
        cout << "Invalid position!";
        return row;
    }

    for(int i = row; i >= position; i--){
        for(int j = 0; j < col; j++){
            arr[i][j] = arr[i-1][j];
        }
    }

    for(int j = 0; j < col; j++){
        arr[position - 1][j] = values[j];
    }

    return row + 1;
}

// Insert Col
int insert_col(int arr[][100], int row, int col, int values[], int position){

    if(position < 1 || position > col + 1){
        cout << "Invalid position!";
        return col;
    }

    for(int i = 0; i < row; i++){
        for(int j = col; j >= position; j--){
            arr[i][j] = arr[i][j-1];
        }
    }

    for(int i = 0; i < row; i++){
        arr[i][position-1] = values[i];
    }

    return col + 1;    
}

// Update Value
void update_value(int arr[][100], int row, int col, int value, int i, int j){
    
    if(i < 1 || i > row || j < 1 || j > col){
        cout << "Invalid position!" << endl;
        return;
    }

    arr[i-1][j-1] = value;
}

// Delete Row
int delete_row(int arr[][100], int row, int col, int position){
    
    if(position < 1 || position > row){
        cout << "Invalid position!" << endl;
        return row;
    }

    for(int i = position - 1; i < row - 1; i++){
        for(int j = 0; j < col; j++){
            arr[i][j] = arr[i + 1][j];
        }
    }

    return row - 1;
}

// Delete Col
int delete_col(int arr[][100], int row, int col, int position){
    
    if (position < 1 || position > col){
        cout << "Invalid position!" << endl;
        return col;
    }

    for(int i = 0; i < row; i++){
        for(int j = position - 1; j < col - 1; j++){
            arr[i][j] = arr[i][j + 1];
        }
    }

    return col - 1;
}

// Traversal
void traverse(int arr[][100], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }
}

int main(){
    int arr[100][100], row, col, position;

    cout << "Enter the number of row: ";
    cin >> row;

    cout << "Enter the number of col: ";
    cin >> col;

    cout << "Enter matrix elements (" << row << "x" << col << "):" << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }

    
    // ========== Traversal ==========
    cout << "\nCurrent Matrix:" << endl;
    traverse(arr, row, col);

    
    // ========== Insert Row ==========
    int rowValues[col];
    cout << "\n----- Insert Row -----" << endl;
    cout << "Enter the position (1 to " << row + 1 << "): ";
    cin >> position;

    cout << "Enter " << col << " elements for insert: ";
    for(int i = 0; i < col; i++){
        cin >> rowValues[i];
    }

    row = insert_row(arr, row, col, rowValues, position);

    cout << "\nMatrix after inserting row:" << endl;
    traverse(arr, row, col);


    // ========== Insert Col ==========
    int colValues[row];
    cout << "\n----- Insert Col -----" << endl;
    cout << "Enter the position (1 to " << col + 1 << "): ";
    cin >> position;

    cout << "Enter " << row << " elements for insert: ";
    for(int i = 0; i < row; i++){
        cin >> colValues[i];
    }

    col = insert_col(arr, row, col, colValues, position);

    cout << "\nMatrix after inserting col:" << endl;
    traverse(arr, row, col);


    // ========== Update Value ==========
    int value, x, y;
    cout << "\n----- Update Value -----" << endl;
    cout << "Enter the position within (" << row << " x "  << col << "): ";
    cin >> x >> y;

    cout << "Enter new value: ";
    cin >> value;

    update_value(arr, row, col, value, x, y);

    cout << "\nMatrix after updating:" << endl;
    traverse(arr, row, col);


    // ========== Delete Row ==========
    cout << "\n----- Delete Row -----" << endl;
    cout << "Enter the row position to delete (1 to " << row << "): ";
    cin >> position;

    row = delete_row(arr, row, col, position);

    cout << "\nMatrix after deleting row:" << endl;
    traverse(arr, row, col);


    // ========== Delete Column ==========
    cout << "\n----- Delete Column -----" << endl;
    cout << "Enter the column position to delete (1 to " << col << "): ";
    cin >> position;

    col = delete_col(arr, row, col, position);

    cout << "\nMatrix after deleting column:" << endl;
    traverse(arr, row, col);
    
    return 0;
}