/*
 Од тастатура се внесуваат димензиите на една матрица (m,n <= 100), а потоа и елементите од матрицата. Да се трансформира матрицата така што средниот елемент во секоја редица ќе се замени со разликата (по апсолутна вредност) на сумата на елементите во првата половина од редицата и сумата на елементите во втората половина на редицата. Ако матрицата има парен број колони, се менува вредноста на средните два елемента. Средниот/те елемент/и влегува/ат во сумите (при непарен број на колони, средниот елемент влегува во двете суми!). Да се испечати на екран променетата матрица.

Пример.

Влез:

m = 4

n = 4

1 3 -5 4

2 10 2 10

7 2 3 5

3 2 10 3

Излез:

1 5 5 4

2 0 0 10

7 1 1 5

3 8 8 3
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

void ChangeMiddleElements (int a[100][100], int n,int i){
    int sumFirstHalf = 0;
    int sumSecondHalf = 0;
    int middleElementValue=0;
    if (n%2 == 0){
        for (int j = 0; j < n/2 ; ++j) {
            sumFirstHalf += a[i][j];
        }
        for (int j = n/2; j <n ; ++j) {
            sumSecondHalf += a[i][j];
        }
        middleElementValue = abs(sumFirstHalf - sumSecondHalf);
        a[i][(n/2)-1] = middleElementValue;
        a[i][n/2] = middleElementValue;
    }
    else if (n%2 == 1){
        for (int j = 0; j <= (n/2) ; ++j) {
            sumFirstHalf += a[i][j];
        }
        for (int j = (n/2); j <n; ++j) {
            sumSecondHalf += a[i][j];
        }
        middleElementValue = abs(sumFirstHalf - sumSecondHalf);
        a[i][n/2] = middleElementValue;
    }
}

int main (){

    int a[100][100] , n , m;

    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        ChangeMiddleElements(a,n,i);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}

