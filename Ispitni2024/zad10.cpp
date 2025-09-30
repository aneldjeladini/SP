/*
 Од стандарден влез прво се читаат два знака z1 и z2 , а потоа се читаат редови со низи од знаци се’ додека не се прочита знакот # (секој од редовите не е подолг од 80 знаци).

Да се напише програма со која на стандарден излез ќе се испечатат поднизите од секој ред составени од знаците што се наоѓаат меѓу z1 и z2 (без нив). Секоја подниза се печати во нов ред.

Се смета дека секој ред од датотеката точно еднаш ги содржи знаците z1 и z2, знакот z1 секогаш се наоѓа пред знакот z2, а меѓу z1 и z2 секогаш има барем еден знак.

 Input:
 0 9
nfjskdz0nvjkfdmnlks9bvfkjmcdz,
bfhjdskvfdkl0fvkdzddjmje k dmkldz kdfds!%mlacsd9
0fbnrjkdn9
fjkd0jdfkfmjndksfjd;sj sad;jm 9nfcjka
#

 Output:
nvjkfdmnlks
fvkdzddjmje k dmkldz kdfds!%mlacsd
fbnrjkdn
jdfkfmjndksfjd;sj sad;jm
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int main (){

    char z1 , z2;

    cin >> z1 >> z2;

    char a[80][80];
    bool exit = false;
    int countRows = 0;

    for (int i = 0; i <80 ; ++i) {
        for (int j = 0; j <80 ; ++j) {
            cin >>noskipws>> a[i][j];
            if (a[i][j] == '\n'){
                break;
            }
            if (a[i][j] == '#'){
                exit = true;
                break;
            }
        }
        if (exit){
            break;
        }
        countRows++;
    }
    for (int i = 0; i < countRows; ++i) {
        bool foundz1 = false;
        for (int j = 0; j < 80 ; ++j) {
            if (a[i][j] == z1){
                foundz1 = true;
                continue;
            }
            if (a[i][j] == z2){
                break;
            }
            if (foundz1){
                cout << a[i][j];
            }
        }
        if (foundz1 == true){
            cout << endl;
        }
    }



    return 0;
}

