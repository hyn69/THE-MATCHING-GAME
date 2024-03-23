// LapTrinhGamePikachu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ThuVien.h"
using namespace std;
char** playingBox(int col, int row) {
    int n = row;
    int m = col;
    int colChar = (m - 1) / 4;
    int rowChar = (n - 1) / 8;
    int iChar = 0;
    int jChar = 0;
    int randRow = 0;
    int randCol = 0;
    char temp;
    char** box = new char*[n];
    for (int i = 0; i < m; i++) {
        box[i] = new char[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            box[i][j] = ' ';
        }
    }
    /*Dòng code này dùng để tạo ra bảng và đồng thời gán chữ vào mỗi ô trong bảng */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i % 4 == 0) && (j % 8 != 0)) {
                box[i][j] = '-';
                continue;
            }
            else if ((j % 8 == 0) && (i % 4 != 0)) {
                box[i][j] = '|';
                continue;
            }
            else if (i % 2 == 0 && j % 4 == 0 && i % 4 != 0 && j % 8 != 0) {
                box[i][j] = alphabet[(iChar * colChar + jChar) % colChar];
                jChar++;
            }
        }
        iChar++;
        jChar = 0;
    }
    return box;
}
void coutBox(char** box, int col, int row) {
    int n = row;
    int m = col;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << box[i][j];
        }
        cout << endl;
    }
}
void drawBox(char** &box, int index, int jdex) {
    for (int i = index; i < index + 3; i++) {
        for (int j = jdex; j < jdex + 7; j++) {
            if (isalpha(box[i][j]))
                continue;
            box[i][j] = char(219);
        }
    }
}
void undrawBox(char** &box,int index, int jdex) {
    for (int i = index; i < index + 3; i++) {
        for (int j = jdex; j < jdex + 7; j++) {
            if (box[i][j] == char(219))
                box[i][j] = ' ';
        }
    }
}

// Hàm xử lý di chuyển
void moveBox(char** &box, int& index, int& jdex) {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
        case 'w':
            undrawBox(box, index, jdex);
            index -= 4;
            drawBox(box,  index, jdex);
            break;
        case 's':
            undrawBox(box,  index, jdex);
            index += 4;
            drawBox(box, index, jdex);
            break;
        case 'a':
            undrawBox(box, index, jdex);
            jdex -= 8;
            drawBox(box,  index, jdex);
            break;
        case 'd':
            undrawBox(box,  index, jdex);
            jdex += 8;
            drawBox(box, index, jdex);
            break;
        default:
            break;
        }
    }
}
void xoadulieuCu(int row, int col, int x, int y) {
    gotoXY(x, y);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << ' ';
        }
        cout << endl;
    }
}
void set_color(int color) {
    // ANSI escape code to set the color
    std::cout << "\033[" << color << "m";
}

int main()
{   
    srand(time(NULL));
    char** box = nullptr;
    int index = 1;
    int jdex = 1;
    int col, row;
    int x, y;
    do {
        cout << "Input column: "; cin >> col;
        cout << "Input row: "; cin >> row;
    } while ((col * row) % 2 != 0);
    row = 4 * row + 1;
    col = 8 * col + 1;
    box = playingBox(col, row);
    drawBox(box, index, jdex);
    coutBox(box, col, row);
    x = whereX();
    y = whereY();
    y -= row;
    while (true)
    {
        if (_kbhit()) {
            int key = _getch();
            switch (key) {
            case 'w':
                undrawBox(box, index, jdex);
                index -= 4;
                if (index < 0)
                    index = 1;
                drawBox(box, index, jdex);
                break;
            case 's':
                undrawBox(box, index, jdex);
                index += 4;
                if (index > row - 4 + 1)
                    index = row - 4;
                drawBox(box, index, jdex);
                break;
            case 'a':
                undrawBox(box, index, jdex);
                jdex -= 8;
                if (jdex < 0)
                    jdex = 1;
                drawBox(box, index, jdex);
                break;
            case 'd':
                undrawBox(box, index, jdex);
                jdex += 8;
                if (jdex > col - 8 + 1)
                    jdex = col - 8;
                drawBox(box, index, jdex);
                break;
            default:
                break;
            }
            xoadulieuCu(row, col, x, y);
            gotoXY(x, y);
            coutBox(box, col, row);
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
