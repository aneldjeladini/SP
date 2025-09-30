/*
 Од тастатура се внесуваат димензиите m и n на матрица од цели броеви, Аmxn, ( 0 < m, n < 30 ) и нејзините елементи. Потоа се внесуваат два цели броја r и k  (индекси на редица/колона од матрицата, т.е. 0 <= r < m и 0 <= k < n).

Да се напише програма која ja трансформира матрицата А така што елементите над редицата r и лево од колоната k се заменуваат со минималната вредност од матрицата А.

Пример

Влез

4 6 // m и n

2 3 // r и k

1 2 3 4 5 1

2 9 4 5 1 3

4 5 6 7 3 2

1 2 3 3 2 8



Излез

1 1 1 4 5 1

1 1 1 5 1 3

4 5 6 7 3 2

1 2 3 3 2 8
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int findMinElement (int a[100][100],int m, int n){
    int min = a[0][0];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] < min){
                min = a[i][j];
            }
        }
    }
    return min;
}

int main (){
    int m,n;
    cin >> m >> n;
    int a[100][100];
    int r,k;
    cin >> r >> k;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int minElement = findMinElement(a,m,n);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < k; ++j) {
            a[i][j] = minElement;
        }
    }


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout <<  a[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}

