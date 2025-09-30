/*
 Read from SI lines. Find and print the row, where the ratio of digits/letters is largest. If there are more than one such rows print the last. No row is longer than 100 characters, and if in a row there are no letters, that row is ignored.

Example

Input

aaa123aa 222aa5a289
aaaa cde 23aaaa
45 ,, 56! 7
222aa5a289 aaa123aa
123 aaa 89994 ghj 90 xyz
xyz ,. hgfd
Output

222aa5a289 aaa123aa
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int digitCount (char a[100][300] , int i){
    int count = 0;

    for (int j = 0; j < 300; ++j) {
        if (a[i][j] == '\0'){
            break;
        }
        if (isdigit(a[i][j])){
            count++;
        }
    }
    return count;
}

int letterCount (char a[100][300] , int i ) {
    int count = 0;
    for (int j = 0; j < 300; ++j) {
        if (a[i][j] == '\0'){
            break;
        }
        if (isalpha(a[i][j])){
            count ++;
        }
    }
    return count;
}

double ratio (char a[100][300], int i){

    double Ratio = 1.0 * abs(digitCount(a,i)) / abs(letterCount(a,i));

    return Ratio;
}

int main() {


    char a[100][300];
    int rowCount = 0;
    double maxRatio = 0;
    int maxIndex = 0;
    for (int i = 0; i < 100; ++i) {
        cin.getline(a[i],300);
        if (a[i][0] == '\0'){
            break;
        }
        rowCount++;
    }



    for (int i = 0; i < rowCount; ++i) {
        if (letterCount(a,i) == 0){
            continue;
        }
        if (ratio(a,i) > 0){
            maxRatio = ratio(a,i);
            maxIndex = i;
        }
        break;
    }

    for (int i = 0; i < rowCount; ++i) {
        if (letterCount(a,i) == 0){
            continue;
        }
        if (ratio(a,i) >= maxRatio){
            maxRatio = ratio(a,i);
            maxIndex = i;
        }
    }

    cout << a[maxIndex] << endl;





    return 0;
}