/*
 Цик-цак е број за кој важи дека за секој пар соседни цифри во бројот важи дека едната е помала од 5, а другата е поголема или еднаква на 5. На пример, ако бројот x е составен од цифрите a, b, c и d, тогаш за нив важи:

a<5, b>=5, c<5, d>=5 или a>=5, b<5, c>=5, d<5

Пр.  508294, 2638, 81
Од тастатура се читаат непознат број на цели броеви поголеми од или еднакви на 10 (броевите помали од 10 се игнорираат). Читањето завршува во моментот кога ќе се прочита знак што не е цифра. Да се испечатат сите цик-цак броеви.

 Input:
 5005
5050
60619
21365
12345
8045
8050
k

 Output:
5050
60619
8050
 */

#include <iostream>

using namespace std;

bool isZigzag (int n){
    int lastdigit = n%10;
    n/=10;

    bool decreasing = (lastdigit>=5 && n%10 < lastdigit);

    while (n>0){
        int current = n%10;

        if ((decreasing && current>=5) || (!decreasing && current<5 )){
            return false;
        }

        decreasing = !decreasing;
        lastdigit = current;
        n/=10;

    }

    return true;
}



int main () {

    int n;

    while (cin >> n){
        if (n >=10 && isZigzag(n)){
            cout << n << endl;
        }
    }


    return 0;
}