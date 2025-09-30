/*
 Цик-цак е број за кој што важи дека за секој пар соседни цифри, тие се наизменично поголеми односно помали една во однос на друга. На пример, ако бројот x е составен од цифрите a, b, c, d и е, тогаш за нив важи:

a>b, b<c, c>d, d<e или a<b, b>c, c<d, d>e

Пр. 343, 4624, 6231209
Од тастатура се читаат непознат број цели броеви поголеми од или еднакви на 10 (броевите помали од 10 се игнорираат). Читањето завршува во моментот кога ќе се прочита знак што не е цифра. Да се испечатат сите цик-цак броеви.

 Input:
 343
22
4624
123456
6231209
9
k

 Output:
 343
4624
6231209
 */

#include <iostream>

using namespace std;


bool isZigzag(int n){  // 4624
    int lastdigit = n%10; // 4
    n/=10; // 462
    bool increasing = (n%10 > lastdigit); // false

    while (n>0){
        int current = n%10;


        if ((increasing && current <= lastdigit) || (!increasing && current >= lastdigit)) {
            return false;
        }
        increasing =!increasing;
        lastdigit = current;
        n/=10;
    }
    return true;
}


int main () {

    int n;
    while (cin >> n){

        if (n >= 10 && isZigzag(n)){
            cout << n << endl;
        }

    }

    return 0;
}
