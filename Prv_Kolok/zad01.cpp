/*
 Благ број е број што е составен само од парни цифри (0, 2, 4, 6, 8). Во зададен опсег (почетокот m и крајот на опегот n се цели броеви чија вредност се внесува од тастатура),
 да се најде и испечати најмалиот „благ број“. Ако не постои таков број, да се испечати NE.

 Input: 99 500

 Output: 200
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

bool isBlag (int broj){
    while (broj > 0){
        int digit = broj%10;
        if (digit % 2 != 0){
            return false;
        }
        broj /= 10;
    }
    return true;
}


int main() {

    int pocetok,kraj,broj;

    cin >> pocetok >> kraj;

    int najmalBlag = -1;

    for ( broj = pocetok; broj <= kraj ; ++broj) {
        if (isBlag(broj)) {
            if (najmalBlag == -1 || najmalBlag > broj){
                najmalBlag = broj;
            }
        }
    }

    if (najmalBlag == -1){
        cout << "NE" << endl;
    } else {
        cout << najmalBlag << endl;
    }







    return 0;
}

