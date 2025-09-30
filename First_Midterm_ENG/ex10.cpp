/*
 Write a program in which from the standard input you read one positive integer z, and afterwards you read one after another pairs of integers (a, b). Thereby, the loop should end if you read the pair (0, 0). The program should calculate how many times the integer z is equal to the sum of the pairs a and b, as well as the percentage of the pairs (a,b) that give sum equal to z (NOTE: the pair (0,0) is not taken into account when doing calculations!).
 Input:
 100
50 50
-50 -50
-99 199
32 98
0 0

 Output:
 You entered 2 pairs of numbers that have a sum equal to 100
The percentage of pairs with sum 100 is 50%
 */



#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;



int main() {

    int n;
    cin >> n;
    int x, y;
    int countValid=0;
    int countAll = 0;
    double percentage = 0;
    while (true){
        cin >> x >> y;
        if (x==0 && y==0){
            break;
        }
        if (x+y == n){
            countValid++;
        }
        countAll++;
    }
    percentage = (1.0*countValid/countAll) * 100;
    cout << "You entered " << countValid << " pairs of numbers that have a sum equal to " << n << endl;
    cout << "The percentage of pairs with sum " << n << " is " << percentage << "%" << endl;


    return 0;
}