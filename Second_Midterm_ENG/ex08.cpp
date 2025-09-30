/*
 Write a recursive function that will find the number of odd numbers of an array of integers. The function accepts as an arguments the array for which the number of odd numbers is required and the total number of elements in the array. The function is given with the following prototype:

int Odd (int a [], int n);

Also write the main () function to test the Odd function.

 Input:
25
-1
-2
-5
5
7
-7
5
100
-6
-2
6
-6
-2
-9
-110
-24
-55
2
4
6
8
10
17
24
-25

 Output: 10
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int Odd (int a[],int n){
    if (n == 0){
        return 0;
    }
    int count = (a[n-1] % 2 != 0) ? 1:0;
    return count + Odd(a,n-1);
}



int main (){

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << Odd(a,n) << endl;

    return 0;
}

