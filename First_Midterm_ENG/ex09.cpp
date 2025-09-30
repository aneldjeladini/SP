/*
 Read from SI unknown number of triplets of integers (three integers). The reading ends when the program can not read successfully read three integers. For each triplet of integers print out the two of them that have the minimum difference between them. First print the smaller one, and then the bigger integer. If two pairs of integers in the triplet have equal difference, than print out all the integers, ordered from the smallest to the largest.

Example: if 5 1 7 is entered -> 5 - 1 = 4, 7 - 5 = 2, 7 - 1 = 6 -> 2 is the smallest difference -> 5 7 should be printed

Input:

5 1 7
10 2 18
Output:

5 7
2 10 18
 */



#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;



int main() {

    int x, y, z;
    int max1=0, max2=0, max3=0;
    int temp = 0;
    int r1=0,r2=0,r3=0;

    while (cin >> x >> y >> z) {

        if (x > y) {
            max1 = x;
            max2 = y;
        } else {
            max1 = y;
            max2 = x;
        }

        if (z > max1) {
            temp = max1;
            max1 = z;
            max3 = max2;
            max2 = temp;
        } else if (z < max1) {
            if (z > max2) {
                temp = max2;
                max2 = z;
                max3 = temp;
            } else {
                max3 = z;
            }
        }

        if (x == z){
            cout << x <<" " << x << endl;
            continue;
        }

        r1 = max2-max3;
        r2 = max1-max2;
        r3 = max1-max3;

        if (r1<r2 && r1 < r3){
            cout << max3 <<" "<<max2 << endl;
        }
        else if (r2 < r1 && r2 < r3){
            cout << max2 <<" "<<max1 << endl;
        }
        else if (r3 < r1 && r3 < r2){
            cout << max3 <<" "<<max1 << endl;
        }
        else {
            cout << max3 << " " << max2 << " " << max1 << endl;
        }

    }








    return 0;
}
