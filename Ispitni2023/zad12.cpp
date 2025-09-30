/*
 За дадена низа од знаци со големина од максимум 100 знаци (се внесува од тастатура) да се пронајде и врати првата голема буква со помош на рекурзивна функција. Пронајдената буква да се испечати на екран. Доколку нема, функцијата потребно е да го врати знакот ‘\0’.

 Input:
 daNh5}cFVfj.aQsC06eTHr;y0;!YZ~S;%cF{
 Output: N
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


void firstCaps (char a[],int i){
    if (i == strlen(a)){
        cout << "Nema" << endl;
        return;
    }
    if (isupper(a[i])){
        cout << a[i] << endl;
        return;
    }
    else {
        firstCaps(a,i+1);
    }
}




int main() {

    char a[100];
    cin.getline(a,100);

    firstCaps(a,0);



    return 0;
}


