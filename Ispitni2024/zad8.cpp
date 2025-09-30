/*
 Од стандарден влез се читаат непознат број на редови додека не се прочита 0. Да се најде најдолгиот ред во кој има барем 2 цифри. Потоа, на стандарден излез да се испечатат знаците од најдолгиот ред кои се наоѓаат помеѓу првата и последната цифра (заедно со тие 2 цифри) во истиот редослед. Доколку има повеќе такви редови се печати последниот. Се претпоставува дека ниту еден ред не е подолг од 100 знаци.

Пример.

Влез:
dat.txt:
    aaa123aa222aa2aaa23aaaaa22
    aaaaaaaaaaaa 23aaaa
    123 aaa aaa aaa aaa 12345 aaa aaa 2a
    0
Излез:
    123 aaa aaa aaa aaa 12345 aaa aaa 2
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

bool isValid (char a[100][100],int i){
    int digitcount = 0;
    for (int j = 0; a[i][j] !='\n' && a[i][j] != '\0' ; ++j) {
        if (isdigit(a[i][j])){
            digitcount++;
        }
    }
    return digitcount >=2;
}

int main (){

    char a[100][100];
    bool exit = false;
    int count = 0;
    int i = 0;

    for (int j = 0; j < 100 ; ++j) {
        cin >> noskipws >> a[i][j];
        if (a[i][j] == '\n' || a[i][j] == '\0'){
            break;
        }
        count ++;
    }
    int maxCount = count;
    int maxIindex = i;
    i++;
    int count2=0;

    while (1){
        for (int j = 0; j <100 ; ++j) {
            cin >> noskipws >> a[i][j];
            if (a[i][0] == '0' && a[i][1] == '\n' ){
                exit = true;
                break;
            }
            if (a[i][j] == '\n'){
                break;
            }
            count2 ++;
        }
        if (exit){
            break;
        }
        if (isValid(a,i) && count2 >= count){
            maxIindex = i;
            count = count2;
        }
        count2=0;
        i++;

    }

    int IndexLastDigit = 0;
    int IndexFirstDigit = 0;

    for (int j = 0; j < count ; ++j) {
        if (isdigit(a[maxIindex][j])){
            IndexFirstDigit = j;
            break;
        }
    }

    for (int j = count-1; j >= 0 ; j--) {
        if (isdigit(a[maxIindex][j])){
            IndexLastDigit = j;
            break;
        }
    }

    for (int j = IndexFirstDigit; j <= IndexLastDigit ; ++j) {
        cout << a[maxIindex][j];
    }

    return 0;
}

