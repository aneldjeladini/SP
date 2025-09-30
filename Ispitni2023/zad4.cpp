/*
 Од стандарден влез се внесува почетна текстуална низа (стринг) со максимална должина од 20 знаци - почетен стринг.

Потоа се внесува цел број N (N<=100), а во продолжение секоја во нов ред, се внесуваат N текстуални низи (реченици) со максимална должина од 150 знаци.

За секоја од внесените реченици треба да се изброи колку пати почетниот стринг последователно се појавува во неа (треба  да се прави разлика помеѓу мали и големи букви). На крај да се генерира извештај во кој ќе се наведе колку вкупно реченици имаат 0, 1, 2, … односно n последователни појавувања на почетниот стринг. Во овој случај n е бројот на последователни појавувања на почетниот стринг во речениците. Излезот треба да биде во форматот како што е даден во примерот.


Забелешка: Броењето на тоа колку пати почетниот стринг последователно се наоѓа во реченицата да се направи во посебна функција.

Кај излезот првиот број означува последователни појавувања на стрингот 2024 (од 0 до n), а вториот број означува кај колку реченици од влезот е соодветниот број на последователни појавувања на почетниот стринг 2024.

На пример во реченицата:

20242024 e novata godina koja ni pretstoi, Da bide ispolneta so radost i srekja. Srekjna Nova 202420242024 godina!

бројот на последователно појавување на стрингот 2024 е: 3 (обележани со задебелени и подвлечени знаци).

Input:
 2024
4
Srekjna Nova Godina!
Srekjkna Nova 20242024 godina! Mnogu zdravje, uspeh i srekja vo 2024ta.
20242024 e novata godina koja ni pretstoi, Da bide ispolneta so radost i srekja. Srekjna Nova 202420242024 godina!
Uste edna nova godina ni dojde.

 Output:
 0: 2
1: 1
2: 0
3: 1

 */

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;


int posledovatelniPovtoruvanja (char pocetna[],char niza[150][150],int i){
    int count = 0;
    int temp = strlen(pocetna);
    int temp2 = strlen(niza[i]);

    for (int j = 0; j <= (temp2) - (2*temp); ++j) {
        bool isSubstring = true;
        bool isDoubleSubstring = true;
        if (niza[i][j] != pocetna[0]){
            continue;
        }

        for (int k = 0; k < temp; ++k) {
            if (pocetna[k] != niza[i][j+k]){
                isSubstring = false;
                break;
            }
        }

        if (isSubstring){
            for (int l = 0; l < temp ; ++l) {
                if (pocetna[l] != niza[i][j+temp+l]){
                    isDoubleSubstring = false;
                    break;
                }
            }
        }
        else{
            isDoubleSubstring = false;
        }

        if (isDoubleSubstring){
            count ++;
        }
    }
    return count;
}


int main(){


    char pocetna[20],niza[150][150];
    int izvestaj[150] = {0};
    cin.getline(pocetna,20);
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cin.getline(niza[i],150);
    }
    int maxOccurances = 0;

    for (int i = 0; i < n; ++i) {
        int temp = posledovatelniPovtoruvanja(pocetna,niza,i);
        if (temp > maxOccurances){
            maxOccurances = temp;
        }
    }

    for (int i = 0; i < n; ++i) {
        int temp = posledovatelniPovtoruvanja(pocetna,niza,i);
        izvestaj[temp]++;
    }

    for (int i = 0; i <= maxOccurances; ++i) {
        cout << i << ": " << izvestaj[i] << endl;
    }



    return 0;


}

