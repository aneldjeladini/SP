/*
 Read from standard input the dimensions of a matrix (m < 100 and n < 100) which contains only zeros and ones. Then read the elements of the matrix.

Read the coordinates of one element of the matrix. If the element of the read position is 0, then it should become 1 and:

all zeros above that element to the first element with value 1 or to the start of the column,
all zeros bellow that element to the first element with value 1 or to the end of the column,
all zeros left from that element to the first element with value 1 or to the begin of the row and
all zeros right from that element to the first element with value 1 or to the end of the row.
If the element of the given position is 1 than the matrix stays unchanged.

Print the changed matrix.

 Input:
7 6
1 1 1 1 1 1
0 0 0 0 1 0
1 0 0 0 1 1
1 1 0 1 0 0
0 1 1 0 0 0
0 1 0 0 0 0
1 1 0 0 0 0
5 5

 Output:
1 1 1 1 1 1
0 0 0 0 1 0
1 0 0 0 1 1
1 1 0 1 0 1
0 1 1 0 0 1
0 1 1 1 1 1
1 1 0 0 0 1
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;





int main (){

    int m,n;
    cin >> m >> n;

    int a[m][n];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int coordinateI, coordinateJ;
    cin >> coordinateI >> coordinateJ;

    if (a[coordinateI][coordinateJ] == 0){
        a[coordinateI][coordinateJ] = 1;

        for (int i = coordinateI-1; i >=0 ; i--) {
            if (a[i][coordinateJ] == 1){
                break;
            }
            else {
                a[i][coordinateJ] = 1;
            }
        }

        for (int i = coordinateI+1; i <m ; ++i) {
            if (a[i][coordinateJ] == 1){
                break;
            }
            else{
                a[i][coordinateJ] = 1;
            }
        }

        for (int j = coordinateJ-1; j >=0 ; j--) {
            if (a[coordinateI][j] == 1){
                break;
            }
            else {
                a[coordinateI][j] = 1;
            }
        }

        for (int j = coordinateJ+1; j < n ; ++j) {
            if (a[coordinateI][j] == 1){
                break;
            }
            else {
                a[coordinateI][j] = 1;
            }
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

