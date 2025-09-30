/*
 д стандарден влез се внесува цел број N (N<=100), а потоа се внесуваат N текстуални низи (реченици) со максимална должина од 100 знаци, секоја зададена во нов ред.


За секоја од внесените реченици треба да се изброи колку вкупно пати последователно се појавуваат самогласки. На крај да се генерира извештај во кој ќе се наведе колку вкупно реченици имаат 0, 1, 2, … односно n појaвувања на последователни самогласки. Во овој случај n е максималниот број на последователни појавувања на самогласки во некоја од речениците.

Излезот треба да биде во форматот како што е даден во примерот.


Забелешка: Броењето на последователни појавувања на самогласки во реченицата  да се направи во посебна функција.


Кај излезот првиот број ги значува последователните појавувања на самогласките (0 до n), а вториот број означува кај колку реченици од влезот е соодветниот број на последователни повторувања на самогласки.

На пример во реченицата:

Uste edna nоvaаа goооооdina ni dojdeееее.

бројот на последователно појавување самогласки е: 3 (обележани со задебелени букви).

 Input:
 4
Srekjna Nova Godina!
2024 e novata godina koja ni pretstoi, Da bide ispolneta so radost i srekja.
Uste edna novaaa gooooodina ni dojdeeeee.
2024taaaaaa

 Output:
 0: 1
1: 2
2: 0
3: 1
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


bool isVowel (char c){
    char ch = tolower(c);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u' ){
        return true;
    }
    return false;
}

int consecutiveVowels (char a[100][100], int i){
    int count = 0;
    for (int j = 1; j < strlen(a[i]); ++j) {
        if (isVowel(a[i][j]) && isVowel(a[i][j-1]) && !isVowel(a[i][j+1])){
            count ++;
        }
    }
    return count;
}


int main() {

    char a[100][100];
    int izvestaj[100] , n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cin.getline(a[i],100);
    }
    int max = 0;
    for (int i = 0; i < n; ++i) {
        int temp = consecutiveVowels(a,i);
        if (temp > max){
            max = temp;
        }
        izvestaj[temp]++;
    }

    for (int i = 0; i <= max; ++i) {
        cout << i << ": " << izvestaj[i] << endl;
    }




    return 0;
}


