/*
 From SI read one number that represents the today's date in format DDMMYYYY (DD-day, MM-month, YYYY-year). Then read one integer N, after you read N dates of birth in the given format. For each of the N read dates your program should print "YES" if on today's date (read in the beginning) the person with that date have more or equal to 18 years, otherwise should print "NO".

 Input:
 15032015
12
12121992
16031997
12121980
12041997
01011999
23121976
28071955
16091985
19950817
04061983
16111981
25021951

 Output:
 YES
NO
YES
NO
NO
YES
YES
YES
YES
YES
YES
YES
 */



#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

int Years (int n){
    int years = n % 10000;
    return years;
}

int Months (int n){
    int months = (n/10000) % 100;
    return months;
}

int Days (int n){
    int days = (n/1000000)%100;
    return days;
}

bool Is18 (int x, int y){
    if ((Years(x) - Years(y)) < 18 ){
        return false;
    } else if ((Years(x) - Years(y)) > 18){
        return true;
    } else if ((Years(x) - Years(y)) == 18){
        if (Months(x) < Months(y)){
            return false;
        } else if (Months(x) > Months(y)){
            return true;
        } else if (Months(x) == Months(y)){
            if (Days(x) < Days(y)){
                return false;
            } else {
                return true;
            }
        }
    }
}

int main() {

    int todaysDate;
    cin >> todaysDate;
    int NumberOfDates;
    cin >> NumberOfDates;
    int Date = 0;

    for (int i = 0; i <NumberOfDates ; ++i) {
        cin >> Date;
        if (Is18(todaysDate , Date)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }



    return 0;
}