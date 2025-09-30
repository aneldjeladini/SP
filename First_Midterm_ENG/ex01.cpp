/*
 From SI read characters until you read the char !. In these characters are hidden integers (smaller than 100). Write a program that will read all characters and print the sum of all integers hidden in the text.

Use cin >> noskipws >> znak to read all the chars including spaces.

 Input: ako34D neka12em bashka41mewr!
Output: 87

 */

#include <iostream>
#include <cctype>
using namespace std;



int main(){

    char znak;
    int sum = 0;
    int current = 0;

    while (cin >> noskipws >> znak){
        if (znak == '!'){
            break;
        }
        if (isdigit(znak)){
            current = (current * 10) + znak-'0';
        } else{
            sum+=current;
            current = 0;
        }
    }
    sum+=current;
    cout << sum << endl;



    return 0;
}
