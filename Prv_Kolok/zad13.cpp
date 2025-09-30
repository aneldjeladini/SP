/*
 Од тастатура се читаат непознат број позитивни цели броеви се додека не се внесе нешто различно од број. За секој број треба да се пресмета збирот на цифрата со максимална вредност од претходно внесениот број  и сумата на цифрите на тековниот број (за првиот внесен број се пресметува само сумата на неговите цифри). За секој внесен број резултатот треба да се испечати во следниот формат:

[број]: [сумата на цифрите на бројот + максималната цифра од претходниот број]

342: 9   //3+4+2

345: 16 //3+4+5+4

123: 11 //1+2+3+5

456: 18 //4+5+6+3

 Input: 97654 48654 12345 12343 1263 12443 12643 12777 #

 Output:
 97654: 31
48654: 36
12345: 23
12343: 18
1263: 16
12443: 20
12643: 20
12777: 30
 */

#include <iostream>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

int digitNumber(int n){
    int count = 0;
    while (n>0){
        n/=10;
        count++;
    }
    return count;
}


int sumDigits (int n){
    int sum=0;
    while (n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int maxDigit(int n){
    int max = 0;
    while (n>0) {
        int currentdigit = n%10;
        if (max <= currentdigit){
            max = currentdigit;
        }
        n/=10;
    }
    return max;
}



int main() {

    int n;

    int prevNum = 0;
    while (cin >> n){
        int result = sumDigits(n) + maxDigit(prevNum);
        prevNum=n;
        cout<<n<<": " << result << endl;
    }


    return 0;
}


