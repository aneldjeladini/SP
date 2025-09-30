/*
 За даден број n, испечатете ја следнава секвенца без да користите наредби за повторување (со помош на рекурзија): n n-3 n-6 n-9 … n-9 n-6 n-3 n

Напомена: При печатење на секвенцата на броеви се користат празни места измеѓу броевите.

Input: 16
 Output: 16 13 10 7 4 1 -2 1 4 7 10 13 16
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void print (int n){
    if (n <= 0){
        cout << n << " ";
        return;
    }

    cout <<  n << " ";

    print(n-3);

    cout << n << " ";

}


int main() {

    int n;
    cin >> n;

    print(n);

    return 0;
}
