/*
 Се внесуваат низи од значи од стандарден влез. Да се избројат и испечатат сите последнователни појавувања на соседни самогласки во речениците. Појавата на големи и мали букви да се игнорира. Пронајдените парови самогласки да се испечатат на екран, секој во нов ред со мали букви. Потоа во нов ред се печати бројот на појавувања на паровите самогласки. Читањето завршува кога ќе се прочита знакот #.

Пример:

IO is short for Input Output
medioio medIo song
#
Излез:

io
ou
io
oi
io
io
6

 Input:
 Why so serious?
#

 Output:
 io
ou
2
 */



#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

bool IsVowel (char a){
    if (a == 'a' ||
        a == 'e' ||
        a == 'i' ||
        a == 'o' ||
        a == 'u'){
        return true;
    }
    return false;
}

int main() {
    const int SIZE = 100000;
    char a[SIZE];
    int count = 0;

    for (int i = 0; i < SIZE; ++i) {
        cin >> noskipws >>  a[i];
        if (a[i] == '#'){
            break;
        }
        a[i] = tolower(a[i]);
    }

    for (int i = 0; i < SIZE ; ++i) {
        if (a[i] == '#'){
            break;
        }
        if (IsVowel(a[i]) && IsVowel(a[i+1])){
            cout << a[i] << a[i+1] << endl;
            count++;
        }
    }

    cout << count << endl;


    return 0;
}

