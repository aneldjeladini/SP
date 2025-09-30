/*
 Од тастатура се читаат 2 позитивни цели броеви. Доколку се внесе барем еден негативен број или 0 треба да се печати „Invalid input“.

Треба да се определи дали помалиот број “е парен еквивалент” од поголемиот број.

Еден број “е парен еквивалент” на друг број, ако и само ако неговите цифри се наоѓаат на парните позиции од другиот број, во истиот редослед. Соодветно да се испечатат пораки „PAREN“ и „NE“.

Позициите треба да се сметаат оддесно-налево (најмалку значајната цифра е на позиција 1)

 Input: 12345678 1357
 Output: PAREN
 */



#include <cctype>
#include <iostream>
#include <cmath>
using namespace std;

int digitNumber(int n){
    int count = 0;
    while (n>0){
        n/=10;
        count++;
    }
    return count;
}

bool isEquivalent (int n1,int n2){
    int temp = digitNumber(n1);
    if (digitNumber(n1) % 2 == 0 || n1%10 == 0){
        temp --;
        n1/=10;
    }

    for (int i = 0; i < temp/2 ; ++i) {
        int lastdigit_n1 = n1%10;
        int lastdigit_n2 = n2%10;
        if (lastdigit_n1 != lastdigit_n2){
            return false;
        }
        n1/=100;
        n2/=10;
    }
    return true;
}


int main() {


    int x, y;

    cin >> x >> y;

    if (x <= 0 || y <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    if (isEquivalent(x,y)){
        cout << "PAREN" << endl;
        return 0;
    }
    cout << "NE" << endl;


    return 0;
}



