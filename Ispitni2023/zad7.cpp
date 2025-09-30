/*
 Од стандарден влез се внесува цел број N (N<=100), а потоа се внесуваат N текстуални низи (реченици) со максимална должина од 100 знаци, секоја зададена во нов ред.


За секоја од внесените реченици треба да се изброи колку вкупно пати последователно се појавуваат согласки. На крај да се генерира извештај во кој ќе се наведе колку вкупно реченици имаат 0, 1, 2, … односно n појaвувања на последователни согласки. Во овој случај n е максималниот број на последователни појавувања на согласки во некоја од речениците.

Излезот треба да биде во форматот како што е даден во примерот.


Забелешка: Броењето на последователни појавувања на согласки во реченицата  да се направи во посебна функција.



Кај излезот првиот број ги значува последователните појавувања на согласките (0 до n), а вториот број означува кај колку реченици од влезот е соодветниот број на последователни повторувања на согласки.

На пример во реченицата:

Uste edna nova godina ni dojde.

бројот на последователно појавување согласки е: 3 (обележани со задебелени букви).

 Input:
 4
Srekjna Nova Godina!
2024 e novata godina koja ni pretstoi, Da bide ispolneta so radost i srekja.
Uste edna nova godina ni dojde.
2024taaaaa

 output:
 0: 1
1: 0
2: 1
3: 1
4: 0
5: 0
6: 0
7: 1
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool isConsonant (char c){
    char ch = tolower(c);
    if  (isalpha(ch) && (ch!= 'a' && ch!= 'e' && ch!= 'i' && ch!= 'o' && ch!= 'u')){
        return true;
    }
    return false;
}

int consecutiveConsonants (char a[150][150] , int i){
    int countConsecutive = 0;
    for (int j = 0; j < strlen(a[i])-1; ++j) {
        if (isConsonant(a[i][j]) && isConsonant(a[i][j+1])){
            countConsecutive ++;
            ++j;
        }
    }
    return countConsecutive;
}



int main() {


    char a[150][150];
    int izvestaj[150];
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cin.getline(a[i],150);
    }
    int maxOccurance = 0;
    for (int i = 0; i < n; ++i) {
        int temp = consecutiveConsonants(a,i);
        if (temp > maxOccurance){
            maxOccurance = temp;
        }
        izvestaj[temp]++;
    }

    for (int i = 0; i <= maxOccurance; ++i) {
        cout << i << ": " << izvestaj[i] << endl;
    }




    return 0;
}