/*
 Read from SI one integer n. From the integers smaller than n, find the one with maximum sum of divisors. Do not count the number itself in the sum of divisors.

 Input: 50
 Output: 48
 */



#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

int sumDevisors (int n){
    int sum = 0;
    for (int i = 1; i <=n/2 ; i++) {
        if (n%i==0){
            sum +=i;
        }
    }
    return sum;
}


int main() {

    int n;
    cin >> n;
    int max =1;
    for (int i = n-1; i > 0 ; i--) {
        if (sumDevisors(i) > sumDevisors(max)){
            max = i;
        }
    }
    cout << max << endl;

    return 0;
}
