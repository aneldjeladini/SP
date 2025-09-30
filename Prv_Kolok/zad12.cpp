/*
 * Од тастатура се читаат непознат број на позитивни цели броеви (со максимум 5 цифри) се додека не се внесе нешто различно од број. За секој број треба да се најде позицијата (од десно на лево) на првото појавување на најголемата цифра во составот на бројот (цифрата на единици се наоѓа на позиција 0). Потоа, да се испечати статистика за позициите на најдените цифри со максимална вредност во следниот формат:

[позиција]: [вкупно броеви чија максимална цифра се наоѓа на таа позиција]

0: 2

1: 3

2: 1

3: 1

4: 1


за броевите 97654 48654 12345 12343 1263 12443 12643 12777

Input: 97654 48654 12345 12343 1263 12443 12643 12777 #

 Output:
 0: 2
1: 3
2: 1
3: 1
4: 1

 */

#include <iostream>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;


int maxDigit(int n){
    int max = n%10;
    n/=10;
    int pos = 0;
    int maxpos;
    for (int i = 0; i <=5 ; ++i) {
        int current = n%10;
        if (current>max){
            max = current;
            pos++;
            maxpos = pos;
        }
        else{
            pos++;
        }
        n/=10;
    }
    return maxpos;
}



int main() {

    int n;
    int count0 = 0 , count1=0,count2=0,count3=0,count4=0;

    while(cin >> n){
        if (maxDigit(n)==0){
            count0++;
        }
        else if (maxDigit(n)==1){
            count1++;
        }
        else if (maxDigit(n)==2){
            count2++;
        }
        else if (maxDigit(n)==3){
            count3++;
        }
        else if (maxDigit(n)==4){
            count4++;
        }
    }

    cout << "0: " << count0 << endl;
    cout << "1: " << count1 << endl;
    cout << "2: " << count2 << endl;
    cout << "3: " << count3 << endl;
    cout << "4: " << count4 << endl;




    return 0;
}
