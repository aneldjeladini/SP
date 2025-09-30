/*
 Од стандарден влез се чита еден природен број n. Меѓу природните броеви помали од n, да се најде оној чиј што збир на делителите е најголем. Во пресметувањето на збирот на делителите на даден број, да не се зема предвид самиот број.

 Input: 10
 Output: 8
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

int sumaDeliteli (int broj) {
    int sum = 0;
    for (int i = 1; i <= broj / 2; ++i) {
        if (broj % i == 0){
            sum += i;
        }
    }
    return sum;
}


int main() {


    int n ;
    cin >> n;

    int maxSum=0;
    int maxNum=0;

    for (int i = 1; i < n ; ++i) {
        int currentSum = sumaDeliteli(i);

        if (currentSum > maxSum){
            maxSum = currentSum;
            maxNum = i;
        }
    }


    cout << maxNum << endl;



    return 0;
}
