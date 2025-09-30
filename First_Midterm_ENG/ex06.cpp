/*
 One number is interesting if his flipped number is divisible by the number of digits it contains. The flipped number is composed from the same digits, but in opposite order (ex. 653 is flipped of the number 356). Read from SI one integer n ( n > 9). Find and print the largest integer small than n that is "interesting". If the read number is not valid print a message "The number is invalid".

 Input: 5
 Output: The number is invalid
 */



#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

int DigitNumber (int n){
    int count = 0;
    while (n>0){
        n/=10;
        count++;
    }
    return count;
}

int ReversedNumber (int n){
    int reversed = 0;
    while (n>0){
        int lastDigit = n%10;
        reversed = reversed * 10 + lastDigit;
        n/=10;
    }
    return reversed;
}

bool isInteresting (int n){
    if (ReversedNumber(n) % DigitNumber(n) == 0){
        return true;
    }
    return false;
}

int main() {

    int n;
    cin >> n;

    if (n<10){
        cout << "The number is invalid" << endl;
        return 0;
    }

    for (int i = n-1; i >0 ; i--) {
        if (isInteresting(i)){
            cout << i << endl;
            return 0;
        }
    }


    return 0;
}
