/*
 Еден елемент се заматува ако се најде аритметичка средина на елементот и сите негови соседи. Сосед на еден елемент се сите елементи кои припаѓаат на матрицата и се  околу истиот елемент (хоризонтално, вертикално и дијагонално).

Од стандарден влез се чита матрица од реални броеви (3 < n,m < 50). Прво се читаат бројот на редици и колони на матрицата и во секој преостанат ред се внесува еден ред од матрицата (види пример).По читањето на матрицата, се внесуваат и 2 пара координати на матрицата (ред и колона) кои го репрезентираат горниот-лев и долниот-десен елемент од регионот. Потребно е да генеирате нова матрица во која ќе ги заматите сите елементи кои припаѓаат на регионот.
Новодобиената матрица, во истиот формат, треба да се испечати (види пример).

Пример:

3 4
1.00 2.00 3.00 4.00
5.00 6.00 7.00 8.00
9.00 0.00 1.00 2.00
0 1
2 2
Резултат:

3 4
1.00 4.00 5.00 4.00
5.00 3.78 3.67 8.00
9.00 4.67 4.00 2.00
 */

#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;


double findArithmeticalValue (double a[100][100],int i,int j, int n, int m){
    double sumNeighbors = 0;
    double NeighborCount = 0;
    double arithmeticValue = 0;
    if (i == 0 && j == 0){
        sumNeighbors = (a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1]);
        NeighborCount = 4.0;
    }
    else if (i == n-1 && j == 0){
        sumNeighbors = (a[i][j] + a[i-1][j] + a[i][j+1] + a[i-1][j+1]);
        NeighborCount = 4.0;
    }
    else if (i>0 && i < n-1 && j == 0){
        sumNeighbors = (a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i][j+1] + a[i-1][j+1] + a[i-1][j]);
        NeighborCount = 6.0;
    }
    else if (i == 0 && j == m-1){
        sumNeighbors = (a[i][j] + a[i][j-1] + a[i+1][j-1] + a[i+1][j]);
        NeighborCount = 4.0;
    }
    else if (i == n-1 && j == m-1){
        sumNeighbors = (a[i][j] + a[i][j-1] + a[i-1][j-1] + a[i-1][j]);
        NeighborCount = 4.0;
    }
    else if (i > 0 && i < n-1 && j == m-1){
        sumNeighbors = (a[i][j] + a[i+1][j] + a[i+1][j-1] + a[i][j-1] + a[i-1][j-1] + a[i-1][j] );
        NeighborCount = 6.0;
    }
    else if (i == 0 && j>0 && j < m-1){
        sumNeighbors = (a[i][j] + a[i][j-1] + a[i+1][j-1] + a[i+1][j] + a[i+1][j+1] + a[i][j+1]);
        NeighborCount = 6.0;
    }
    else if (i == n-1 && j>0 && j<m-1){
        sumNeighbors = (a[i][j] + a[i][j-1] + a[i-1][j-1] + a[i-1][j] + a[i-1][j+1] + a[i][j+1]);
        NeighborCount = 6.0;
    }
    else if (j == 0 && i > 0 && j < n-1){
        sumNeighbors = (a[i][j] + a[i-1][j] + a[i-1][j+1] + a[i][j+1] + a[i+1][j+1] + a[i+1][j]);
        NeighborCount = 6.0;
    }
    else if (j == m-1 && i>0 && i<n-1){
        sumNeighbors = (a[i][j] + a[i+1][j] + a[i+1][j-1] + a[i][j-1] + a[i-1][j-1] + a[i-1][j]);
        NeighborCount = 6.0;
    }
    else if (i > 0 && i < n-1 && j>0 && j <m-1){
        sumNeighbors = (a[i][j] + a[i-1][j] + a[i-1][j+1] + a[i][j+1] + a[i+1][j+1] + a[i+1][j] + a[i+1][j-1] + a[i][j-1] + a[i-1][j-1]);
        NeighborCount = 9.0;
    }

    arithmeticValue = sumNeighbors/NeighborCount ;
    // double truncated = std::floor(arithmeticValue * 100000) / 100000;
    return arithmeticValue;
}


int main (){


    int n , m;
    cin >> n >> m;
    double a[100][100];
    double b[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }

    int upper_left_I , upper_left_J , lower_right_I, lower_right_J;

    cin >> upper_left_I >> upper_left_J;
    cin >> lower_right_I >> lower_right_J;


    for (int i = upper_left_I; i <=lower_right_I ; ++i) {
        for (int j = upper_left_J; j <=lower_right_J ; ++j) {
            b[i][j] = findArithmeticalValue(a,i,j,n,m);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }





    return 0;
}
