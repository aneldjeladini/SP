/*
 The dimensions of one matrix (m,n <= 100), and then the elements of the matrix are entered from the keyboard. Make a transformation of the matrix so that the middle element in each column is replaced by the difference (by absolute value) of the sum of the elements in the first half of the column and the sum of the elements in the second half of the column. If the matrix has even number of rows, the value of the middle two elements should be changed. The middle element(s) are included when calculating the sum (in the case of an odd number of rows, the middle element is included when calculating both of the sums (upper and lower sum)!). Print the transformed matrix on the standard output.

 Input:
 6 5
0 -5 0 -100 -10
0 0 0 -30 0
0 0 0 -20 22
0 0 45 0 0
0 4 -23 0 14
0 -2 11 0 0

 Output:
 0 -5 0 -100 -10
0 0 0 -30 0
0 7 33 150 2
0 7 33 150 2
0 4 -23 0 14
0 -2 11 0 0
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int transformColumn (int a[100][100] , int m, int j){
    int sumUpperHalf = 0;
    int sumLowerHalf = 0;
    int ValueMiddle = 0;

    if (m%2 == 0){
        for (int i = 0; i < m/2; ++i) {
            sumUpperHalf += a[i][j];
        }
        for (int i = m/2; i <m ; ++i) {
            sumLowerHalf += a[i][j];
        }
    }
    else if (m%2==1){
        for (int i = 0; i <= m/2; ++i) {
            sumUpperHalf += a[i][j];
        }
        for (int i = m/2; i <m ; ++i) {
            sumLowerHalf += a[i][j];
        }
    }
    ValueMiddle = abs(sumUpperHalf-sumLowerHalf);
    return ValueMiddle;
}



int main (){

    int m , n;
    cin >> m >> n;

    int a[100][100];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j <n ; ++j) {
        if (m%2 == 1){
            a[m/2][j] = transformColumn(a,m,j);
        }
        else if (m%2 == 0){
            int middleValue = transformColumn(a,m,j);
            a[m/2-1][j] = middleValue;
            a[m/2][j] = middleValue;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

