/*
 Let A = {a1, a2, .. a_n} is an array of integers. The size of the array n and the elements of the array are read from SI. Write a program that will transform the array so each element of the original array is replaced with the number of appearance of the least significant digit (the right most) in the number itself. Print the result array on the standard output.

Compute the count of given digit in a number with separate recursive function.

Example:

Input:
5
1 11 1121 111222112 22222
Output:
1 2 3 4 5

 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int countLeastSignificant (int n,int lastdigit,int count=0){
    if (n <10 ){
        return count + ((lastdigit == n) ? 1:0);
    }
    count += (lastdigit == n% 10) ? 1:0;
    return countLeastSignificant(n/10,lastdigit,count);
}






int main (){

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << countLeastSignificant(a[i],a[i]%10) << " ";
    }



    return 0;
}

