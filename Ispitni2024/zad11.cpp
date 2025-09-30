/*
 Од стандарден влез се читаат низи од знаци се додека не се прочита знакот #. Да се напише програма во која од за секој прочитан ред ќе се отпечати бројот на цифри во тој ред, знакот :, па самите цифри подредени според ASCII кодот во растечки редослед. Низите од знаци не се подолги од 100 знаци.

 Input:
 74I9BjpbhbsfX6Ai0xtnmv4csz2gNv
wtkb3Y82B9oygnG1vhRsMOuman2n894v08w4pI3e4x
p7A3pO1U70aeGxwpOptb2rie
nw01MAok4HWisf913hjtiyscgwhdr7w92lm7eddhy6ne40fHbsZc3ac
Zmwk1yrnqt0LjT6ItS2kH
kfcp3Xpxx030B0ojf2G2o4JgkTsolbxqgxkifmbwrxRevKum8tvq4FZxi9LsUM2bq3jGjuo0eu4iv6
W79qURXz32tn8gdzAmasf019JdFbVtizbwu1t09dlkLfpxF1dw7g4wqHSLgEojK27bYP
wyqzCunXvicN1D31v41hbhvmC45m69u587aW0gAZ4mvhypshmn0kVs
#
 Output:
 7:0244679
14:01223344488899
6:012377
14:00112334467799
4:0126
16:0000222333444689
16:0011122347778999
15:001113444556789

 */



#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int DigitNumber (char a[],int countElements){
    int totalDigits = 0;
    for (int i = 0; i <countElements ; ++i) {
        if (isdigit(a[i])){
            totalDigits++;
        }
    }
    return totalDigits;
}

void sortArray (char a[],int countElements){
    for (int i = 0; i <countElements-1 ; ++i) {
        for (int j = 0; j <countElements-1-i ; ++j) {
            if (a[j] > a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}



int main (){

    char a[100];
    int countElements = 0;
    bool exit = false;
    while (1){
        for (int i = 0; i <100 ; ++i) {
            cin >>noskipws>> a[i];
            if (a[i] == '\n' || a[i] == '\0'){
                break;
            }
            if (a[i] == '#'){
                exit = true;
                break;
            }
            countElements++;
        }
        if (exit){
            break;
        }
        cout << DigitNumber(a,countElements) << ":";
        sortArray(a,countElements);
        for (int i = 0; i <countElements ; ++i) {
            if (isdigit(a[i])){
                cout << a[i];
            }
        }
        cout << endl;

        countElements = 0;

    }




    return 0;
}

