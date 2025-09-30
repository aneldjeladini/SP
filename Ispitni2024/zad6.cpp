/*
 Да се напише програма која вчитува матрица со димензии MxN (макс. 100x100). На почетокот се внесуваат димензиите на матрицата, а потоа и елементите на матрицата кои се само вредностите 1 и 0. Програмата треба да изброи и отпечати на СИ во колку од редиците и колоните има барем 3 последователни елементи со вредност 1.

 Input:
 3 8
0 0 1 1 1 0 0 0
1 1 1 0 1 1 1 0
0 1 1 1 1 0 0 1

 Output: 5
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;



int main() {

    int a[100][100] , n , m , count = 0;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m-2; ++j) {
            if (a[i][j] == 1 &&
                a[i][j+1] == 1 &&
                a[i][j+2] == 1){
                count++;
                break;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n-2; i++) {
            if (a[i][j] == 1 &&
                a[i+1][j] == 1 &&
                a[i+2][j] == 1){
                count++;
                break;
            }
        }
    }
    cout << count << endl;


    return 0;
}

