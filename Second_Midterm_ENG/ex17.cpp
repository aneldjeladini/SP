/*
 Read an integer k from SI, followed by lines of characters. Print on SO the read lines transformed in such a way that all the vowels in the line will be repeated k times.

 Input: 3
Do you ever wish you knew exactly what your dog is thinking? A team of designers from the Nordic Society for Invention and Discovery is playing Doctor Dolittle -- they've developed a doggie headset that can read animal brainwaves and translate them into human speech. That's just one of the many amazing scientific breakthroughs we've witnessed this week.
 Output: Dooo yooouuu eeeveeer wiiish yooouuu kneeew eeexaaactly whaaat yooouuur dooog iiis thiiinkiiing? AAA teeeaaam ooof deeesiiigneeers frooom theee Nooordiiic Sooociiieeety fooor IIInveeentiiiooon aaand Diiiscoooveeery iiis plaaayiiing Doooctooor Doooliiittleee -- theeey'veee deeeveeelooopeeed aaa doooggiiieee heeeaaadseeet thaaat caaan reeeaaad aaaniiimaaal braaaiiinwaaaveees aaand traaanslaaateee theeem iiintooo huuumaaan speeeeeech. Thaaat's juuust oooneee ooof theee maaany aaamaaaziiing sciiieeentiiifiiic breeeaaakthrooouuughs weee'veee wiiitneeesseeed thiiis weeeeeek.

 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool isVowel (char a[500][1000] , int i, int j){
    char c = tolower(a[i][j]);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}


int main() {

    int k;
    cin >> k;
    cin.ignore();
    char a[10][1000];
    int rowCount = 0;
    int len = 0;

    for (int i = 0; i < 10; ++i) {
        cin.getline(a[i],1000);
        if (a[i][0] == '\0'){
            break;
        }
        rowCount ++;
    }

    for (int i = 0; i < rowCount ; ++i) {
        len = strlen(a[i]);
        char temp[1000];
        int index = 0;

        for (int j = 0; j<len ; ++j) {
            temp[index++] = a[i][j];
            if (isVowel(a,i,j)){
                for (int x = 1; x < k; ++x) {
                    temp[index++] = a[i][j];
                }
            }
        }
        temp[index] = '\0';
        strcpy(a[i],temp);
    }

    for (int i = 0; i < rowCount; ++i) {
        cout << a[i] << endl;
    }




    return 0;
}