/*
 Да се напише рекурзивна функција која ќе го најде бројот на позитивни броеви од целобројна низа. Функцијата како аргумент ја прима низата, за која се бара бројот на позитивни броеви и вкупниот број на елементи, кои ги има таа низа. Функцијата е зададена со следниот прототип:

int BrojPozitivni(int niza[], int n);

Да се напише и функција main() за тестирање на функцијата BrojPozitivni.

For example:

 Input:
 2
-2
5

 Output: 1
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int BrojPozitivni (int a[],int n){
    if (n == 0){
        return 0;
    }

    return ((a[n-1]>=0)? 1:0) + BrojPozitivni(a,n-1);
}


int main (){
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sum = BrojPozitivni(a,n);
    cout << sum;


    return 0;
}

