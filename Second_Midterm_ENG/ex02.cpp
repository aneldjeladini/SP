/*
 Write a program that will print the contents read from SI coded. The coding is done letter by letter, so that each letter (only letters, not digits, dots, ...) is replaced with the letter 3 places after in the alphabet. In case of the letters at the end of the alphabet, the counting continues cyclic from the beginning of the alphabet. In the final coded text all letters are lowercase. Example letter a is coded to d, H is coded to k, p is coded to s, x is coded to a, etc.

 Input: Momentalno go testiram resenieto na mojata treta zadaca!
 Output: prphqwdoqr jr whvwludp uhvhqlhwr qd prmdwd wuhwd cdgdfd!
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;



int main (){

    char a[100][100];
    int countRows = 0;
    for (int i = 0; i < 100; ++i) {
        cin.getline(a[i],100);
        if (a[i][0] == '\n' || a[i][0] == '\0') {
            break;
        }
        countRows = i +1;
    }

    for (int i = 0; i < countRows ; ++i) {
        for (int j = 0; j < strlen(a[i]); ++j) {
            if (isalpha(a[i][j])){
                a[i][j] = tolower(a[i][j]);
                a[i][j] = 'a' + (a[i][j] -'a' + 3) % 26;
            }
        }
        cout << a[i] << endl;
    }







    return 0;
}

