/*
 Од стандарден влез се чита цел број N (N<100) и потоа N низи од знаци. Низите знаци содржат букви, цифри и специјални знаци, а секоја од нив не е поголема од 50 знаци.

Да се напише програма што ќе ги отпечати на екран сите низи од знаци во кои се содржи поднизата А1c  најмалку 2 пати (пр. A1c01АA1c92, 12A1cwwA1cxy, аA1cwA1cA1ccA1cxab) според редоследот како што се прочитани од влезот. При печатење на зборовите, сите алфабетски знаци треба да се испечатат со мали букви.

Пример

Влез:

6

Ekjqh!!lkjsdh

 A1c01АA1c92

12A1cwwA1cxy

12A1cwwA1bxy

аA1cwA1cA1ccA1cxab

nemaA1c_povekjepati


Излез

а1c01аа1c92

12а1cwwа1cxy

аа1cwа1cа1ccа1cxab
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int isValid (char a[100][51],char podstr[4],int i){
    int countvalid = 0;
    bool isvalid = true;
    for (int j = 0; j < strlen(a[i])-1; ++j) {
        if (tolower(a[i][j]) == tolower(podstr[0])){
            for (int k = 0; k < strlen(podstr) ; ++k) {
                if (tolower(podstr[k]) != tolower(a[i][j+k])){
                    isvalid = false;
                    break;
                }
            }
            if (isvalid){
                countvalid++;
            }
            isvalid = true;
        }
    }
    return countvalid;
}

void transform (char a[100][51],int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; a[i][j] != '\0'; ++j) {
            a[i][j] = tolower(a[i][j]);
        }
    }
}

int main (){

    int n;
    cin>>n;
    char a[100][51];
    char podstr[] = "A1c";
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cin.getline(a[i],51);
    }
    transform(a,n);
    for (int i = 0; i < n; ++i) {
        if (isValid(a,podstr,i) >= 2){
            cout << a[i] << endl;
        }
    }


    return 0;
}

