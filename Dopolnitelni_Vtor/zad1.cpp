/*
 Од стандарден влез се чита цел број N (N<=100) и потоа N низи од знаци. Низите знаци содржат букви, цифри и специјални знаци (без знаци за празно место), а секоја од нив не е подолга од 80 знаци.

Да се напише програма со која што на стандарден излез ќе се отпечати најдолгата низа, којашто е палиндром (се чита исто од од лево на десно и од десно на лево) и што содржи барем еден специјален знак. Ако нема такви низи, се печати "Nema!". Ако има две или повеќе низи што го задоволуваат овој услов, се печати првата низа којашто го задоволува условот.

Влез:

9

a!bcdedcb!a

Kfd?vsvv98_89vvsv?dfK

Ccsvsdvdfv

342425vbbcb

352!2353696969625

gdg??dfg!!

5336346644747

8338736767867

12344321

Излез:

Kfd?vsvv98_89vvsv?dfK
 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

bool hasSpecialChar (char a[100][100],int i){
    for (int j = 0; a[i][j] !='\0'; ++j) {
        if (!isdigit(a[i][j]) && !isalpha(a[i][j]) && !isspace(a[i][j])){
            return true;
        }
    }
    return false;
}

bool isPalindrome (char a[100][100],int i){
    int left = 0;
    int right = strlen(a[i]);
    --right;
    int n = strlen(a[i]);
    --n;

    for (int j = 0; j < n/2 ; ++j) {
        if (a[i][left] != a[i][right]){
            return false;
        }
        -- right;
        ++left;
    }
    return true;
}

int maxRow (char a[100][100],int n){
    int LongestRow = -1;
    int current = 0;
    int indexMaxrow=-1;
    for (int i = 0; i < n; ++i) {
        if (!hasSpecialChar(a,i) || !isPalindrome(a,i)){
            continue;
        }
        current = strlen(a[i]);
        if (current>LongestRow){
            LongestRow = current;
            indexMaxrow = i;
        }
    }
    return indexMaxrow;
}

int main (){

    char a[100][100];
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cin.getline(a[i],100);
    }




    int index = maxRow(a,n);

    if (index == -1){
        cout << "Nema!" << endl;
    }
    else {
        cout << a[index];
    }




    return 0;
}

