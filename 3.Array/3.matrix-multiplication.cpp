#include <bits/stdc++.h>
using namespace std;

// Input Matrix
void input_matrix(int arr[][100], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }
}

// Display Matrix
void display_matrix(int arr[][100], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }
}

// Matrix Multiplication
void multiply_matrix(int A[][100], int B[][100], int C[][100], int row1, int col1, int col2){
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col2; j++){
            C[i][j] = 0;

            for(int k = 0; k < col1; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    int A[100][100], B[100][100], C[100][100];
    int row1, col1, row2, col2;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> row1 >> col1;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> row2 >> col2;

    if(col1 != row2){
        cout << "Matrix multiplication is not possible!" << endl;
        return 0;
    }

    cout << "\nEnter elements of Matrix A:" << endl;
    input_matrix(A, row1, col1);

    cout << "\nEnter elements of Matrix B:" << endl;
    input_matrix(B, row2, col2);

    multiply_matrix(A, B, C, row1, col1, col2);

    cout << "\nResultant Matrix:" << endl;
    display_matrix(C, row1, col2);

    return 0;
}