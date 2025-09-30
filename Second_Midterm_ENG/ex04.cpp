/*
 Write a program that will read unknown number of three integers, and for each triple (a, b, c) will print the number (a or b) that contains the digit c more times on even positions (the positions are counted from right to left, and the first position is 1).

 Input:
 5436666 542456 6
1232432 3435 2
121211 22222 1
3333 4444 3
555514 1212 1
889999 99 9
50 20 2
81 21 8

 Output:
5436666
1232432
121211
3333
1212
889999
20
81
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;



int occuranceAtEvenPosition (int n,int x){
    int count = 0;
    n/=10;
    while (n>0){
        if (n%10 == x){
            count++;
        }
        n/=100;
    }
    return count;
}


int main (){

    int a,b,c;

    while (cin >> a >> b >> c){
        if (occuranceAtEvenPosition(a,c) > occuranceAtEvenPosition(b,c)){
            cout << a << endl;
        }
        else if (occuranceAtEvenPosition(b,c) > occuranceAtEvenPosition(a,c)){
            cout << b << endl;
        }
        else {
            cout << a << endl;
        }
    }



    return 0;
}

