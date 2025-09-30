/*
  Од стандарден влез се внесуваат два цели броја N и Х.

Да се најде најблискот број помал од N коj е тотално различен од бројот Х.

Еден број е тотално различен од друг ако и само ако во него не се појавува ниту една од цифрите на другиот број.

Задачата да се реши без употреба на низи и матрици.

 Input: 88 7
 Output: 86
 */


#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;




bool isDifferent (int n, int x){

    while (n>0){
        int lastdigit_N = n%10;
        int tempX = x;

        while (tempX>0){
            if (lastdigit_N == tempX%10){
                return false;
            }
            tempX/=10;
        }
        n/=10;
    }


    return true;
}


int main () {


    int n,x;
    cin >> n >> x;


    for (int i = n-1; i >=0 ; i--) {
        if (isDifferent(i,x)){
            cout << i << endl;
            return 0;
        }
    }





    return 0;
}
