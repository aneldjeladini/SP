/*
 За даден број n, испечатете ја следнава секвенца без да користите наредби за повторување (со помош на рекурзија): n n-5 n-10 n-15 … n-15 n-10 n-5 n

Напомена: При печатење на секвенцата на броеви се користат празни места измеѓу броевите.

Input: 16
Output: 16 11 6 1 -4 1 6 11 16

 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void pecati (int n){
    if (n<=0){
        cout << n << " ";
        return;
    }
    cout << n << " ";
    pecati(n-5);
    cout << n << " ";
}

int main() {

    int n;
    cin >> n;
    pecati(n);





    return 0;
}
