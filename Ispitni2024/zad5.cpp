/*
 Од стандарден влез се чита ливче во спортска обложувалница.

Во првиот ред е запишана сумата на уплата (цел број).

Потоа во секој нареден ред кој се чита од стандарден влез (се додека не се прочита знакот #) е запишан по еден тип во следниот формат:

ab12 1 1.25
Првиот број е шифрата на типот (низа од знаци која не е подолга од 9 знаци), вториот број е типот (може да биде 1, 0 или 2) додека третиот број е коефициентот (реален број).

Ваша задача е да го испечатите типот со најголем коефициент како и можната добивка на ливчето. Доколку има повеќе типови со ист максимален коефициент, да се испечати првиот.

Можната добивка се пресметува како производ на сите коефициенти со сумата на уплата.

 Input:
100
ab12 1 1.2
c234 2 2.0
#

 Output:
 c234 2 2
240
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;


int main (){

    int bet;
    cin >> bet;
    int tip[100];
    double coef[100];
    string code[100];
    int j = 0;
    double bestCoef = 0;
    int indexBestCoef = 0;
    double productCoef = 1.0;
    bool exit = false;

    while (1) {

        for (int i = 0; i < 3; ++i) {
            if (i == 0) {
                cin >> code[j];
                if (code[j] == "#"){
                    exit = true;
                    break;
                }
            } else if (i == 1) {
                cin >> tip[j];
            } else if (i == 2) {
                cin >> coef[j];
                if (coef[j] > bestCoef){
                    bestCoef = coef[j];
                    indexBestCoef = j;
                }
            }
        }
        if (exit){
            break;
        }
        j++;
    }

    for (int i = 0; i < j ; ++i) {
        productCoef *= coef[i];
    }
    double possibleWinnings = (productCoef * bet);

    cout << code[indexBestCoef] << " " << tip[indexBestCoef] << " " << coef[indexBestCoef] << endl;
    cout << possibleWinnings << endl;




    return 0;
}

