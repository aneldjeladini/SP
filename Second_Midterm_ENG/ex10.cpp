/*
 Write a program where a matrix A read from SI (maximum value of dimensions of the matrix is 100) is transformed to a new matrix B. Each element of the new matrix B is sum of positive neighbors of the corresponding element of the matrix A. Print the new matrix B on the standard output.

 Input:
2 3
1 -5 -9
-2 3 8

 Output:
 0 4 8
4 8 3
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int sumPositiveNeighbors (int a[100][100],int i , int j, int m,int n){
    int sum = 0;
    if (i<m-1){
        sum += (a[i+1][j] > 0) ? a[i+1][j]:0;
    }
    if (i>0){
        sum += (a[i-1][j] > 0) ? a[i-1][j] : 0;
    }
    if (j<n-1){
        sum += (a[i][j+1] > 0) ? a[i][j+1] : 0;
    }
    if (j>0) {
        sum += (a[i][j-1] > 0) ? a[i][j-1] : 0;
    }
    return sum;
}


int main (){

    int a[100][100], b[100][100] , m , n;
    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = sumPositiveNeighbors(a,i,j,m,n);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

