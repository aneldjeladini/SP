/*
 Oд стандарден влез се вчитува еден цел број X, димензии на матрица M и N (цели броеви), како и елементите на матрицата со димензии M x N (цели броеви). Да се напише програма што ќе ги промени редиците на матрицата на следниот начин:

Ако збирот на елементите од редот е поголем од X, елементите на тој ред добиваат вредност 1
Ако збирот на елементите од редот е помал од X, елементите на тој ред добиваат вредност -1
Ако збирот на елементите од редот е еднаков на X, елементите на тој ред добиваат вредност 0
Променетата матрица да се испечати на екран.

Input:
 17
4 6
1 5 7 2 1 1
10 0 0 5 1 1
5 8 3 9 1 0
9 8 2 5 3 4

 Output:
0 0 0 0 0 0
0 0 0 0 0 0
1 1 1 1 1 1
1 1 1 1 1 1
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int SumRowElements (int a[100][100], int n,int row){
    int sum = 0;
    for (int j = 0; j < n ; ++j) {
        sum += a[row][j];
    }
    return sum;
}


int main (){

    int x;
    cin >> x;
    int m,n;
    cin >> m >> n;
    int a[100][100];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        if (SumRowElements(a,n,i)>x){
            for (int j = 0; j <n; ++j) {
                a[i][j] = 1;
            }
        }
        else if (SumRowElements(a,n,i)<x){
            for (int j = 0; j <n; ++j) {
                a[i][j] = -1;
            }
        }
        else{
            for (int j = 0; j <n; ++j) {
                a[i][j] = 0;
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

