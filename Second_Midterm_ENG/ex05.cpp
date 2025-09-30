/*
 Write a program that reads matrix with dimensions MxN (max. 100x100). At the beginning the dimensions are read, and then the elements of the matrix with values 0 or 1. Your program should count and print on SO the number of rows and columns with at least 3 consecutive appearance of elements with value 1.

 Input:
 10 4
0 0 0 1
0 1 0 0
0 0 0 1
1 0 0 0
0 0 0 1
1 0 0 1
0 1 0 0
1 0 1 1
0 1 1 0
1 0 1 1


 Output: 1

 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;





int main (){

    int m ,n;
    cin >> m >> n;
    int a[m][n];
    int validRows = 0;
    int validCols = 0;


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n-2; ++j) {
            if (a[i][j] == 1 && a[i][j+1] == 1 && a[i][j+2] == 1){
                validRows++;
                break;
            }
        }
    }

    for (int j = 0; j <n ; ++j) {
        for (int i = 0; i < m-2; ++i) {
            if (a[i][j] == 1 && a[i+1][j] == 1 && a[i+2][j] == 1){
                validCols++;
                break;
            }
        }
    }
    cout << validRows+validCols << endl;


    return 0;
}

