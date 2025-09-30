/*
 Write a program that will read a string (not longer than 100 characters) containing letters and digits. The program should print on the standard output the letters that are between the first and the second digit, left-to-right, including the bordering digits themselves. If there is only one digit in the string, the program should print all the letters till the end of the string. If there is no digits in the string the program should print out the message "No digits".

Example:

Axvdf7dbb3bdbd88B -> 7dbb3
Isdv88mvndkv9d -> 88
vnjis9kjsnvnv -> 9kjsnvnv
dsfsrtt -> No digits
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int stringDigits (char a[100]){
    int digitCount = 0;
    for (int i = 0; i < 100; ++i) {
        if (a[i] == '\n' || a[i] == '\0'){
            break;
        }
        if (isdigit(a[i])){
            digitCount ++;
        }
    }
    return digitCount;
}

int main (){

    char a[100];
    int countElements = 0;
    int indexFirstDigit = 0;
    int indexSecondDigit = 0;
    bool fountDigit = false;


    for (int i = 0; i < 100; ++i) {
        cin>>noskipws>>a[i];
        if (a[i] == '\n' || a[i] == '\0'){
            break;
        }
        countElements++;
    }



    for (int i = 0; i < countElements; ++i) {
        if (isdigit(a[i])){
            indexFirstDigit = i;
            break;
        }
    }
    for (int i = indexFirstDigit+1; i <countElements ; ++i) {
        if (isdigit(a[i])){
            indexSecondDigit = i;
            break;
        }
    }

    if (stringDigits(a) == 0){
        cout << "No digits" << endl;
    }
    else if (stringDigits(a) == 1){
        for (int i = indexFirstDigit; i < countElements ; ++i) {
            cout << a[i];
        }
    }
    else {
        for (int i = indexFirstDigit; i <= indexSecondDigit ; ++i) {
            cout << a[i];
        }
    }


    return 0;
}

