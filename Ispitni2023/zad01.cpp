/*
 Од стандарден влез се внесува почетна тексутуална низа (стринг) со максимална должина од 20 знаци - почетен стринг.

Потоа се внесува цел број N (N<=100), а во продолжение секоја во нов ред, се внесуваат N текстуални низи (реченици) со максимална должина од 100 знаци.

За секоја од внесените реченици треба да се изброи колку вкупно пати почетниот стринг се појавува во неа (треба  да се прави разлика помеѓу мали и големи букви). На крај да се генерира извештај во кој ќе се наведе колку вкупно реченици имаат 0, 1, 2, … односно n појавувања на почетниот стринг. Во овој случај n е бројот на појавувања на почетниот стринг во некоја од речениците. Излезот треба да биде во форматот како што е даден во примерот.


Забелешка: Броењето на тоа колку пати почетниот стринг се наоѓа во реченицата да се направи во посебна функција.

Кај излезот првиот број означува појавувања на стрингот 2024 (од 0 до n), а вториот број означува кај колку реченици од влезот е соодветниот број на појавувања на почетниот стринг 2024.

 Input:
 2024
4
Srekjna Nova Godina!
Srekjkna Nova 2024 godina! Mnogu zdravje, uspeh i srekja vo 2024ta.
2024 e novata godina koja ni pretstoi, Da bide ispolneta so radost i srekja. Srekjna 2024 godina!
Uste edna nova godina ni dojde.

 Output:
0: 2
1: 0
2: 2
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int occuranceCount (char podsting[], char matrix[100][100] , int i){
    int count = 0;
    for (int j = 0; j <= (strlen(matrix[i]) - strlen(podsting)); ++j) {
        bool isSubstring = true;
        if (matrix[i][j] != podsting[0]) {
            continue;
        } else {
            for (int k = 0; k < strlen(podsting); ++k) {
                if (podsting[k] != matrix[i][j + k]) {
                    isSubstring = false;
                    break;
                }
            }
            if (isSubstring) {
                count++;
            }
        }
    }
    return count;
}

int main() {


    char podstring [20];
    cin.getline(podstring,20);
    int n;
    cin >> n;
    cin.ignore();
    char matrix[100][100];
    for (int i = 0; i < n; ++i) {
        cin.getline(matrix[i],100);
    }
    int izvestaj[100] = {0};
    int maxOccurance = 0;

    for (int i = 0; i < n; ++i) {
        int temp = occuranceCount(podstring,matrix,i);
        if ( temp > maxOccurance){
            maxOccurance = temp;
        }
    }
    for (int i = 0; i < n ; ++i) {
        izvestaj[occuranceCount(podstring,matrix,i)]++;
    }
    for (int i = 0; i <= maxOccurance; ++i) {
        cout << i << ": " << izvestaj[i] << endl;
    }


    return 0;
}
