/*
 Од стандарден влез се читаат знаци се додека не се прочита извичник. Во вака внесениот текст се скриени цели броеви (помали од 100). Да се напише програма што ќе ги прочита сите знаци и на излез ќе го испечати збирот на сите броеви скриени во текстот.

Напомена: cin во C++ ги игнорира празните места (space). За да не ги игнорира потребно е да се додаде noskipws пред читањето на знакот (пр. cin >> noskipws >> znak;)

 Input: ako34D neka12em bashka41mewr20!
 Output: 107
 */


#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

int main() {

    char znak;
    int sum = 0;
    int currentNum = 0;
    bool isNumber = false;

    while (cin >> noskipws >> znak){
        if (znak == '!'){
            break;
        }

        if (isdigit(znak)){
            currentNum = currentNum * 10 + (znak - '0'); //0*10 + 3 = 3
            isNumber = true;
        }
        else if (isNumber){
            sum +=currentNum;
            currentNum = 0;
            isNumber = false;
        }

    }
    if (isNumber){
        sum += currentNum;
    }

    cout << sum << endl;

    return 0;
}