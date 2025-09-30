/*
 За дадена низа од знаци со големина од максимум 100 знаци (се внесува од тастатура) да се пронајде и врати првиот интерпукциски знак со помош на рекурзивна функција. Пронајдениот интерпукциски знак да се испечати на екран. Доколку нема, функцијата потребно е да го врати знакот ‘\0’.

Input: daNh5 }cFVfj.aQsC06eTHr;y0;!YZ~S;%cF{

Output: }
 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


void firstChar (char a[],int i=0){
    if (i == strlen(a)){
        cout << "Nema" << endl;
        return;
    }
    if (ispunct(a[i])){
        cout << a[i] << endl;
        return;
    }
    firstChar(a,i+1);
}




int main() {

    char a[100];
    cin.getline(a,100);

    firstChar(a,0);



    return 0;
}


