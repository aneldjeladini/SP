/*
 Од тастатура се внесуваат димензиите на една матрица (m, n <= 100), а потоа и елементите од матрицата. Да се генерира низа (со најмногу m) така што секој елемент од низата се добива со наоѓање на елементот во секоја редица од матрицата што е најоддалечен од аритметичката средина во рамки на таа редица. Ако постојат повеќе елементи што се најоддалечени од аритметичката средина, тогаш се зема предвид првиот. Редоследот на запишување на елементите во низата одговара на редоследот на редиците.

Пример:

Влез:

3 6

1 2 2 3 4 5

1 1 2 2 3 3

1 2 3 4 5 6

Излез:

5 1 1
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

double arithmeticMiddle (int a[100][100] ,int i ,int m){
    int sum = 0;
    for (int j = 0; j <m ; ++j) {
        sum += a[i][j];
    }
    double middle  = (1.0*sum / m);
    return middle;
}

int furthestFromMiddle (int a[100][100], int i, int m){
    int max = a[i][0];
    int min = a[i][0];
    for (int j = 1; j <m ; ++j) {
        if (max < a[i][j]){
            max = a[i][j];
        }
        if (min > a[i][j]){
            min = a[i][j];
        }
    }
    double middle = arithmeticMiddle(a,i,m);
    if (abs(max - middle) > abs(min - middle)){
        return max;
    }
    else if (abs(max) - (arithmeticMiddle(a,i,m)) < abs(min - arithmeticMiddle(a,i,m))){
        return min;
    }
    else {
        for (int j = 0; j <m ; ++j) {
            if (a[i][j] == max || a[i][j] == min){
                return a[i][j];
            }
        }
    }
    return 0;
}


int main (){


    int a[100][100] , temp[100] , n , m;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <n ; ++i) {
        cout << furthestFromMiddle(a,i,m) << " ";
    }



    return 0;
}

