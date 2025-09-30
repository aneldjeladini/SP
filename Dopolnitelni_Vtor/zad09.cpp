/*
 Од стандарден влез се внесуваат непознат број на реченици претставени преку текстуални низи (стрингови) секоја не подолга од 100 знаци и секоја во нов ред. Програмата треба да го најде стрингот кој содржи најмногу сврзници и да го испечати заедно со бројот на најдените сврзници. За сврзници се сметаат сите зборови составени од една, две или три букви. Зборовите во текстуалната низа се одделени со едно или повеќе прзани места и/или интерпункциски знак.

Броењето на сврзници во дадена текстуална низа треба да се реализира во посебна функција. Решенијата без користење функција ќе бидат оценети со најмногу 40% од поените.

Ако има повеќе реченици со ист максимален број на сврзници, се печати прво најдената.

Објаснување на тест примерот:
Бројот на сврзници по реченици е 2, 3, 4, 2, 4 и 7 соодветно. Најмногу сврзници има по последната реченица па се печати бројот 7 и содржината на таа реченица.

Input:
 Svrznicite vo makedonskiot jazik se sluzbeni zborovi
odnosno niv gi upotrebuvame za povrzuvanje oddelni zborovi
vo ramkite na edna recenica ili poveḱe recenici vo edna slozena recenica.
Pri povrzuvanjeto, svrznicite gi izrazuvaat odnosite megju zborovite
ili megju recenicite, pa taka sprotiven odnos se iskazhuva so
ama ili no, a usloven odnos so ako itn.

 Output: 7: ama ili no, a usloven odnos so ako itn.

 */

#include <iostream>
#include <cstring>
using namespace std;

int conjunctionNumber (char a[100][100],int i,int coubntrows) {
    int countCounjunctions = 0;
    for (int j = 0; j < strlen(a[i]); ++j) {
        if (j > 0) {
            if (isalpha(a[i][j]) && (isspace(a[i][j - 1]) || ispunct(a[i][j-1]))) {
                if (isspace(a[i][j + 1]) || ispunct(a[i][j + 1])) {
                    countCounjunctions ++;
                } else if (isalpha(a[i][j + 1]) && (isspace(a[i][j + 2]) || ispunct(a[i][j + 2]))) {
                    countCounjunctions ++;
                } else if (isalpha(a[i][j+1]) && isalpha(a[i][j+2]) && (isspace(a[i][j+3]) || ispunct(a[i][j+3]) || a[i][j+3] == '\0' || a[i][j+3] == '\n')){
                    countCounjunctions ++;
                }
            }
        }
        else if (j == 0){
            if (isalpha(a[i][j])) {
                if (isspace(a[i][j + 1]) || ispunct(a[i][j + 1])) {
                    countCounjunctions ++;
                } else if (isalpha(a[i][j + 1]) && (isspace(a[i][j + 2]) || ispunct(a[i][j + 2]))) {
                    countCounjunctions ++;
                } else if (isalpha(a[i][j+1]) && isalpha(a[i][j+2]) && (isspace(a[i][j+3]) || ispunct(a[i][j+3]) || a[i][j+3] == '\0' || a[i][j+3] == '\n')){
                    countCounjunctions ++;
                }
            }
        }
    }
    return countCounjunctions;
}




int main() {

    char a[100][100];
    int countrows = 0;
    for (int i = 0; i < 100; ++i) {
        cin.getline(a[i],100);
        if (a[i][0] == '\0' || a[i][0] == '\n'){
            break;
        }
        countrows ++;
    }

    int maxRowIndex = 0;
    for (int i = 0; i < countrows; ++i) {
        if (conjunctionNumber(a,i,countrows) > conjunctionNumber(a,maxRowIndex,countrows)){
            maxRowIndex = i;
        }
    }

    cout << conjunctionNumber(a,maxRowIndex,countrows) << ": " << a[maxRowIndex] << endl;




    return 0;
}
