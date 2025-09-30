/*
 Еден елемент од матрица ја дели матрицата на 4 квадранти (прикажани на сликата). Притоа самиот елемент кој ја дели матрицата припаѓа во четвртиот квадрант (-5 во примерот на сликата).

Од стандарден влез се внесува матрица со димензии NxM (1 <= N, M < 100). Потоа се внесуваат два броеви кои претставуваат индекси на еден елемент од матрицата.

Да се најдат сумите на секој од квадрантите и да се испечатат на стандарен излез. Притоа се печати сумата за првиот квадрант, па за вториот, па третиот и на крај за четвртиот. Доколку не може да се креира квадрант, тогаш за сумата на тој квадрант треба да се испечати 0.

 Input:
 2 3
5 7 8
1 2 3
1 1

 Output:
 15 5 1 5
 */



#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;



int main() {

    int matrix[100][100] , n,m, mI ,mJ ,sumI=0 ,sumII=0 ,sumIII=0 ,sumIV=0;

    cin >> n;
    cin >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    cin >> mI >> mJ;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i < mI && j>=mJ){
                sumI += matrix[i][j];
            }
            else if (i < mI && j < mJ){
                sumII += matrix[i][j];
            }
            else if (i >= mI && j < mJ ){
                sumIII += matrix[i][j];
            }
            else if (i >= mI && j >= mJ){
                sumIV += matrix[i][j];
            }
        }
    }

    cout << sumI << " " << sumII << " " << sumIII << " " << sumIV << endl;




    return 0;
}

