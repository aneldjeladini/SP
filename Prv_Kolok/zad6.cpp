/*
 Да се напише програма во која од стандарден влез прво се внесува еден позитивен цел број z, а потоа последователно се внесуваат парови цели броеви (a, b). Внесувањето на парови цели броеви треба да заврши кога корисникот ќе го внесе парот (0, 0). Треба да се пресмета колку пати z е еднаков на збирот на секој внесен пар броеви a и b, како и колкав процент од вкупниот број внесени парови (a, b) даваат збир z (ЗАБЕЛЕШКА: парот (0, 0) не се зема во предвид при извршувањето на пресметките!).

 Input:
 100
50 50
-50 -50
-99 199
32 98
0 0

 Output:
 Vnesovte 2 parovi od broevi chij zbir e 100
Procentot na parovi so zbir 100 e 50%
 */

#include <iostream>
using namespace std;



int main() {

    int n;
    cin >> n;
    int x1,x2;
    int countValidni = 0;
    int countParovi = 0;
    while (1){
        cin >> x1 >> x2;
        if (x1 == 0 && x2 == 0){
            break;
        }
        countParovi ++;

        if ((x1 + x2) == n){
            countValidni++;
        }
    }

    cout << "Vnesovte " << countValidni << " parovi od broevi chij zbir e " << n << endl;
    double procent = ( double(countValidni)/ (countParovi)) * 100;
    cout << "Procentot na parovi so zbir " << n << " e " << procent<<"%" << endl;


    return 0;
}
