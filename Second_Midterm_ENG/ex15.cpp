/*
 From SI read lines of text, none of which is longer than 80 characters. Write e program that will transform the input and print it out on the standard output. The output should contain only letters (all other characters are discarded), and each word should be printed in a separate line.

Example:

Input file:

 Voi5 ovaa 6d6ato$$tek!a ke
ostanat09856 4453 sa5m2o
bu!!4kv(((((i
Output:

Vo
ovaa
datoteka
ke
ostanat
samo
bukvi
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;





int main() {

    char a[100][500];
    int rowcount = 0;
    bool foundAlpha = false;
    bool flag = false;
    for (int i = 0; i < 100; ++i) {
        cin.getline(a[i],500);
        rowcount ++;
    }

    for (int i = 0; i < rowcount; ++i) {
        for (int j = 0; j < strlen(a[i]) ; ++j) {
            if (a[i][j] == '6' && a[i][j+1] == '0' && a[i][j+2] == '.'){
                flag = true;
            }
            if (isalpha(a[i][j])){
                foundAlpha = true;
                cout << a[i][j];
            }
            if ( (foundAlpha) && isspace(a[i][j]) && !isspace(a[i][j-1]) && a[i][j] != '\0'){
                cout << endl;
                foundAlpha = false;
            }
        }
        foundAlpha = false;
        if ( a[i][0] != '\0' && a[i][0] != '\n' && (!flag)){
            cout << endl;
        }
        flag = false;
    }

    return 0;
}