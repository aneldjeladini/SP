/*
 Eден природен e „интересен“ ако неговиот обратен број е делив со неговиот број на цифри. Обратен број е бројот составен од истите цифри, но во обратен редослед (на пример, 653 е обратен број на бројот 356). Од тастатура се внесува природен број n ( n > 9). Да се најде и отпечати најголемиот природен број помал од n кој што е „интересен“. Ако внесениот број не е валиден, да се отпечати соодветна порака (Brojot ne e validen).

 Input: 5
 Output: Brojot ne e validen
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

int digitNumber (int broj){
    int count = 0;
    while (broj>0){
        broj/=10;
        count++;
    }
    return count;
}

int obraten_broj(int broj){
    int reversedNumber = 0;

    while (broj>0) {
        int ostatok = broj % 10;
        reversedNumber = reversedNumber * 10 + ostatok;
        broj /= 10;
    }

    return reversedNumber;

}

bool isInteresting (int broj) {
    if (obraten_broj(broj) % digitNumber(broj) == 0){
        return true;
    }
    return false;
}

int main() {



    int broj;
    cin >> broj;

    if (broj <= 9){
        cout << "Brojot ne e validen " << endl;
        return 0;
    }

    for (int i = broj-1; i >0 ; i--) {
        if (isInteresting(i)){
            cout << i << endl;
            return 0;
        }
    }




    return 0;
}






