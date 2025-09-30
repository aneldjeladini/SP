/*
 Четиринасочник претставува матрица во која се испишани зборови хоризонотално и вертикално, одлево-надесно и оддесно-налево. Притоа секој елемент од матрицата претставува буква од англиската азбука.

пример скриени зборови: HAIR, OLE (прецртани), FISH, TOE (подвлечени)

T H A I R E
E S N K N E
M I M J O L
M F S P S T
I F G E L O
X U T Y O E
Од стандарден влез се чита квадратна матрица од ред n (3 <= n <= 50), составена од знаци. Прво се чита бројот n - бројот на редици (колони) на матрицата, а потоа и самите елементи на матрицата (види пример).
По читањето на матрицата, од стандарден влез се внесува збор составен од максимум 10 букви.

Ваша задача е да определите дали тој збор се наоѓа во четиринасочникот (хоризонтално или вертикално, одлево-надесно или оддесно-налево). Потребно е да се испечати локацијата (ред, колона) на првата и последната буква од зборот. Доколку зборот повеќепати се наоѓа во четеринасочникот, треба да се испечати првото појавување, гледано елемент по елемент како што се чита матрицата.

Доколку не се пронајде зборот, тогаш се печати Not Found.
 */

#include <iostream>
#include <cstring>
using namespace std;

// Function to check if the word exists starting from (x, y) in the given direction
bool isWordPresent(char a[100][100], int n, int x, int y, int dx, int dy, const char* word, int letters) {
    for (int k = 0; k < letters; ++k) {
        int nx = x + k * dx; // New x-coordinate
        int ny = y + k * dy; // New y-coordinate

        // Check bounds
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || a[nx][ny] != word[k]) {
            return false;
        }
    }
    return true;
}

int main() {
    char a[100][100];
    int n;
    cin >> n;

    // Input the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    char word[10];
    cin >> word;
    int letters = strlen(word);

    // Define the 4 possible directions as (dx, dy)
    int directions[4][2] = {
            {0, 1},  // Left to right
            {0, -1}, // Right to left
            {1, 0},  // Top to bottom
            {-1, 0}  // Bottom to top
    };

    int startI = -1, startJ = -1, endI = -1, endJ = -1;

    // Iterate through the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == word[0]) { // Start matching only if the first letter matches
                for (int d = 0; d < 4; ++d) { // Check all 4 directions
                    int dx = directions[d][0];
                    int dy = directions[d][1];

                    if (isWordPresent(a, n, i, j, dx, dy, word, letters)) {
                        startI = i;
                        startJ = j;
                        endI = i + (letters - 1) * dx;
                        endJ = j + (letters - 1) * dy;
                        goto found; // Exit all loops once the first occurrence is found
                    }
                }
            }
        }
    }

    found:
    if (startI != -1 && startJ != -1) {
        cout << startI << ", " << startJ << " -> " << endI << ", " << endJ << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
