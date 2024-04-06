#pragma once
#include "ThuVien.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h> // For keyboard input (getch())
#include <windows.h>
#include <string>
#include <string.h>
#include <math.h>
#include <time.h>
#include <fstream>
#include <io.h>    // Call _setmode
#include <fcntl.h> // _O_U16TEXT
#define _O_U16TEXT 0x20000
//Nguồn tham khảo: https://github.com/xxnithicxx/Pikachu-Game/blob/master/Source.cpp#L106

#define WORD_WIDTH_SPACING 8
#define WORD_HEIGHT_SPACING 3

#define ARROW_UP 0x48
#define ARROW_LEFT 0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN 0x50
#define ARROW_NONE 0x00
#define ESC_KEY 0x1B
#define ENTER_KEY 0x0D
#define SPACE_KEY 0x20
#define HELP 0x68

#define EASY 4   // Matrix size is 4x4
#define MEDIUM 6 // Matrix size is 6x6
#define HARD 8   // Matrix size is 8x8

//=================== Hàm vẽ tiêu đề game ===================
void drawingTitle() {
    int x = 30;
    int y = 0;
    //============= The Begining Line ============
    SetColor(7);
    gotoXY(x, y++);
    cout << "  _____ _   _ _____   __  __    _  _____ ____ _   _ ___ _   _  ____    ____    _    __  __ _____ ";
    gotoXY(x, y++);
    cout << " |_   _| | | | ____| |  \\/  |  / \\|_   _/ ___| | | |_ _| \\ | |/ ___|  / ___|  / \\  |  \\/  | ____|";
    gotoXY(x, y++);
    cout << "   | | | |_| |  _|   | |\\/| | / _ \\ | || |   | |_| || ||  \\| | |  _  | |  _  / _ \\ | |\\/| |  _|  ";
    gotoXY(x, y++);
    cout << "   | | |  _  | |___  | |  | |/ ___ \\| || |___|  _  || || |\\  | |_| | | |_| |/ ___ \\| |  | | |___ ";
    gotoXY(x, y++);
    cout << "   |_| |_| |_|_____| |_|  |_/_/   \\_\\_| \\____|_| |_|___|_| \\_|\\____|  \\____/_/   \\_\\_|  |_|_____|";
    //============= Drawing Pokemon =============
    gotoXY(x += 15, y++);
    gotoXY(x, y++);
    cout << "                                  ,',\n";
    gotoXY(x, y++);
    cout << "    _.----.        ____         ,'  _\\   ___    ___     ____\n";
    gotoXY(x, y++);
    cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n";
    gotoXY(x, y++);
    cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n";
    gotoXY(x, y++);
    cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n";
    gotoXY(x, y++);
    cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n";
    gotoXY(x, y++);
    cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n";
    gotoXY(x, y++);
    cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n";
    gotoXY(x, y++);
    cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n";
    gotoXY(x, y++);
    cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n";
    gotoXY(x, y++);
    cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n";
    gotoXY(x, y++);
    cout << "                                `'                            '-._|\n";
}

void inputRowCol(int& row, int& col) {
    drawingTitle();
    char c = 205;
    SetColor(7);
    for (int i = 50; i <= 100; i++)
    {
        gotoXY(i, 20); cout << c;
        gotoXY(i, 31); cout << c;
    }
    gotoXY(52, 22);
    cout << "Number of columns: ";
    int x_col = whereX();
    int y_col = whereY();
    gotoXY(52, 24);
    cout << "Number of rows: ";
    int x_row = whereX();
    int y_row = whereY();
    /*gotoXY(52, 26);
    cout << "Column: ";
    int x_col = whereX();
    int y_col = whereY();
    gotoXY(52, 28);
    cout << "Row: ";
    int x_row = whereX();
    int y_row = whereY();
    */
    /*for (int x = 101; x <= 118; x++)
    {
        gotoXY(x, 1); cout << c;
        gotoXY(x, 27); cout << c;
    }*/
    c = 186;
    for (int j = 21; j <= 30; j++)
    {
        gotoXY(50, j); cout << c;
    }
    for (int j = 21; j <= 30; j++)
    {
        gotoXY(100, j); cout << c;
    }
    gotoXY(x_col, y_col);
    cin >> col;
    gotoXY(x_row, y_row);
    cin >> row;
}


//============= Tham khảo từ dòng 49 đến 99 
//============= Point Variable =================
struct Point {
    int x;
    int y;
    bool isSelected;

    void swap(Point& other)
    {
        int tempX = x;
        int tempY = y;

        x = other.x;
        y = other.y;

        other.x = tempX;
        other.y = tempY;
    }


    void prepareSelected(Point& other)
    {
        // If 2 node is the same, do nothing
        if (x == other.x && y == other.y)
            return;

        // If 2 node is not the same, swap their position
        // If this.x is higher than other.x, swap their position
        if (x < other.x && y > other.y)
        {
            return;
        }

        else if (x > other.x)
        {
            swap(other);
            return;
        }
        // If this.y is lower than other.y, swap their position
        else if (y > other.y)
        {
            swap(other);
        }
    }
};

//========================= Tham khảo dòng 122 đến 128 =====================================
struct BackGround
{
    string** BG;

    void GetBG(int col, int row);
    void PrintBG(int col, int row, Point A);
};


//======================= Tham khảo từ dòng 213 đến 264 ========================================
//======================= GetArrow ==============================
unsigned char GetArrow()
{
    unsigned char ch = _getch();
    if (ch == 0x00)
    {
        // first char is a zero so lets look at the next char
        ch = _getch();
        switch (ch)
        {
        case ARROW_UP:
            return ch;
        case ARROW_LEFT:
            return ch;
        case ARROW_RIGHT:
            return ch;
        case ARROW_DOWN:
            return ch;
        default:
            return ARROW_NONE;
        }
    }
    else
    {
        // When user use wasd keys
        switch (ch)
        {
        case 'w':
            return ARROW_UP;
        case 'a':
            return ARROW_LEFT;
        case 'd':
            return ARROW_RIGHT;
        case 's':
            return ARROW_DOWN;
        case 'h':
            return HELP;
        }
    }

    // Enter key is the same as space key
    if (ch == ENTER_KEY || ch == SPACE_KEY)
    {
        return ENTER_KEY;
    }

    if (ch == ESC_KEY)
    {
        return ch;
    }

    return ch;
}

//======================= Tham khảo từ dòng 266 đến 275 ========================================
//============= Calculate The Width =============
int calculatePositionWidth(int posInMatrix, int difficulty)
{
    return (WORD_WIDTH_SPACING + 1) * posInMatrix + 8; // +8 is for the border
}

//============= Calculate The Height =============
int calculatePositionHeight(int posInMatrix, int difficulty)
{
    return (WORD_HEIGHT_SPACING + 1) * posInMatrix + 4; // +4 is for the border
}


//=========================== Tham khảo từ dòng 266 đến 275 ===============================
// Restore line
void RestoreLine(int posX, int posY, unsigned int numberOfChars)
{
    gotoXY(posX, posY);
    SetColorBox(BLACK, WHITE);
    for (int i = 0; i < numberOfChars; i++)
    {
        gotoXY(posX + i, posY);
        cout << " ";
    }
}

// Restore column
void RestoreColumn(int posX, int posY, unsigned int numberOfChars)
{
    gotoXY(posX, posY);
    SetColorBox(BLACK, WHITE);
    for (int i = 0; i < numberOfChars; i++)
    {
        gotoXY(posX, posY + i);
        cout << " ";
    }
}

//======================== Tham khảo dòng 409 đến 444 =========================================
void BackGround::GetBG(int col, int row)
{
    int sizeBG = col * row;
    BG = new string *[sizeBG];
    for (int i = 0; i < sizeBG; i++)
    {
        BG[i] = new string[4];
    }

    ifstream file;
    // Open 2.txt in Background folder
    file.open("Test.txt");
    if (file.is_open())
    {
        string temp;
        for (int i = 0; i < row; i++) // Number of row in matrix pikachu
        {
            for (int j = 0; j < 4; j++) // 4 is the width of the cube with not overlap the next cube
            {
                getline(file, temp);
                for (int k = 0; k < col; k++) // Number of column in matrix pikachu
                {
                    // Cut the string for 9 characters
                    string content = temp.substr(k * WORD_WIDTH_SPACING, 9);
                    BG[i + k * row][j] = content;
                }
            }
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    file.close();
}

//======================= Tham khảo từ dòng 446 đến 467 ========================================
void BackGround::PrintBG(int col, int row, Point A)
{
    if (A.x < 0 || A.y < 0 || A.x >= col || A.y >= row)
        return;

    SetColorBox(BLACK, WHITE);
    int position = A.y + A.x * row;
    int posY = calculatePositionHeight(A.y, row);
    int posX = calculatePositionWidth(A.x, col);

    for (int i = 0; i < 4; i++)
    {
        gotoXY(posX, posY++);
        cout << BG[position][i].c_str();
        // wcout << BG[position][i].size();
    }
    if (A.y == row - 1)
    {
        gotoXY(posX, posY++);
        cout << "         ";
    }
}

//========================== Tham khảo từ dòng 277 đến 321 =================================
void DrawBorder(int col, int row)
{
    int minX = calculatePositionWidth(-1, col) + 2;
    int maxX = calculatePositionWidth(col, col) + 5;
    int minY = calculatePositionHeight(-1, row) + 1;
    int maxY = calculatePositionHeight(row, row) + 4;

    // Draw top border
    gotoXY(minX, minY);
    SetColorBox(BLACK, WHITE);

    //cout << "┌";
    for (int i = minX + 1; i <= maxX; i++)
    {
        gotoXY(i, minY);
        cout << "-";
    }
    gotoXY(maxX + 1, minY);
    //cout << "┐";

    // Draw bottom border
    gotoXY(minX, maxY);
    //cout << "└";
    for (int i = minX + 1; i <= maxX; i++)
    {
        gotoXY(i, maxY);
        cout << "-";
    }
    gotoXY(maxX + 1, maxY);
    //cout << "┘";

    // Draw left border
    for (int i = minY + 1; i < maxY; i++)
    {
        gotoXY(minX, i);
        cout << "|";
    }

    // Draw right border
    for (int i = minY + 1; i < maxY; i++)
    {
        gotoXY(maxX + 1, i);
        cout << "|";
    }
}

//========================== Tham khảo từ dòng 348 đến 368 =================================
//========================== Hàm in bảng ===================================================
void printBoard(char** box, int col, int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int posY = calculatePositionHeight(i, row);
            int posX = calculatePositionWidth(j, col);
            gotoXY(posX, posY++);
            cout << " ------- \n";
            gotoXY(posX, posY++);
            cout << "|       |\n";
            gotoXY(posX, posY++);
            cout << "|   " << box[i][j] << "   | \n";
            gotoXY(posX, posY++);
            cout << "|       |\n";
            gotoXY(posX, posY++);
            cout << " ------- \n";
        }
    }
}

//========================== Tham khảo từ dòng 370 đến 383 =================================
//========================== Hàm vẽ hộp ====================================================
//=================== Print Box =================
void drawBox(char** box, int col, int row, Point First, int background_color, int text_color) {
    SetColorBox(background_color, text_color);
    int posY = calculatePositionHeight(First.y, row) + 1;
    int posX = calculatePositionWidth(First.x, col) + 1;
    gotoXY(posX, posY++);
    cout << "       \n";
    gotoXY(posX, posY++);
    cout << "   " << box[First.y][First.x] << "   \n";
    gotoXY(posX, posY++);
    cout << "       \n";
    SetColorBox(BLACK, WHITE);
}

//========================= Tham khảo từ dòng 385 đến 407 ================================
//=================== Delete Box =================
void DeleteCube(char** box, int col, int row, Point A)
{
    SetColorBox(BLACK, BLACK);
    int posY = calculatePositionHeight(A.y, row);
    int posX = calculatePositionWidth(A.x, col);
    gotoXY(posX, posY++);
    if ((A.y - 1) > 0 && (box[A.y - 1][A.x] == ' '))
        cout << "        \n";
    if (A.y == 0)
        cout << "        \n";
    gotoXY(posX, posY++);
    cout << "|       |\n";
    gotoXY(posX, posY++);
    cout << "|       |\n";
    gotoXY(posX, posY++);
    cout << "|       |\n";
    gotoXY(posX, posY++);
    if ((A.y + 1) < row && box[A.y + 1][A.x] == ' ')
        cout << "        \n";
    if (A.y == row - 1)
        cout << "        \n";
    SetColorBox(BLACK, WHITE);
}

//========================= Tham khảo từ dòng 469 đến 489 ================================
//======================= Draw Horizontal Line ================================
void DrawHorizonLine(Point A, Point B)
{
    if (A.x == B.x && A.y == B.y)
        return;

    A.prepareSelected(B);

    int startX = calculatePositionWidth(A.x, EASY) + 5;
    int endX = calculatePositionWidth(B.x, EASY) + 3;
    int horizonPos = calculatePositionHeight(A.y, EASY) + 2;
    gotoXY(startX, horizonPos);
    cout << "-";
    for (int i = startX + 1; i <= endX - 1; i++)
    {
        gotoXY(i, horizonPos);
        cout << "-";
    }
    gotoXY(endX, horizonPos);
    cout << "-";
    return;
}

//========================= Tham khảo từ dòng 491 đến 511 ================================
//======================= Draw Vertical Line ==================================
void DrawVerticalLine(Point A, Point B)
{
    if (A.x == B.x && A.y == B.y)
        return;

    A.prepareSelected(B);

    int startY = calculatePositionHeight(A.y, EASY) + 3;
    int endY = calculatePositionHeight(B.y, EASY) + 1;
    int verticalPos = calculatePositionWidth(A.x, EASY) + 4;
    gotoXY(verticalPos, startY);
    cout << "|";
    for (int i = startY + 1; i <= endY - 1; i++)
    {
        gotoXY(verticalPos, i);
        cout << "|";
    }
    gotoXY(verticalPos, endY);
    cout << "|";
    return;
}

//========================= Tham khảo từ dòng 514 đến 536 ================================
//======================= Check Line Vertical ================================
bool checkLineV(char** box, Point A, Point B)
{
    // Check if A and B is in the same Column
    if (A.x != B.x)
    {
        return false;
    }

    A.prepareSelected(B);

    for (int i = A.y + 1; i < B.y; i++)
    {
        if (box[i][A.x] != ' ')
            return false;
    }
    return true;
}

//========================= Tham khảo từ dòng 539 đến 561 ================================
//======================= Check Line Horizontal ==================================
bool checkLineH(char** box, Point A, Point B)
{
    // Check if A and B is in the same Row
    if (A.y != B.y)
    {
        return false;
    }

    A.prepareSelected(B);

    for (int i = A.x + 1; i < B.x; i++)
    {
        if (box[A.y][i] != ' ')
            return false;
    }
    return true;
}

//======================== Tham khảo từ dòng 563 đến 611 ==================================
//======================= Check I Shape ========================================
bool checkLine(char**& box, Point A, Point B, int col, int row, BackGround backGround)
{
    Point temp;
    if (checkLineH(box, A, B))
    {
        drawBox(box, col, row, A, GREEN, YELLOW);
        drawBox(box, col, row, B, GREEN, YELLOW);
        DrawHorizonLine(A, B);
        gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 3);
        cout << "This is I shape";

        Sleep(1000);

        box[A.y][A.x] = ' ';
        box[B.y][B.x] = ' ';

        temp.x = A.x;
        temp.y = A.y;
        for (int i = A.x; i <= B.x + 1; i++)
        {
            //DeleteCube(box, col, row, temp);
            backGround.PrintBG(col, row, temp);
            temp.x = i;
        }
        return true;
    }

    if (checkLineV(box, A, B))
    {
        drawBox(box, col, row, A, GREEN, YELLOW);
        drawBox(box, col, row, B, GREEN, YELLOW);
        DrawVerticalLine(A, B);
        gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 3);
        cout << "This is I shape";

        Sleep(1000);

        box[A.y][A.x] = ' ';
        box[B.y][B.x] = ' ';

        temp.x = A.x;
        temp.y = A.y;
        for (int i = A.y; i <= B.y + 1; i++)
        {
            //DeleteCube(box, col, row, temp);
            backGround.PrintBG(col, row, temp);
            temp.y = i;
        }
        return true;
    }

    return false;
}

//========================= Tham khảo từ dòng 613 đến 639 ======================
//======================= Check HL Shape ======================================
bool checkHLShape(char** box, Point A, Point B, Point& C, bool& mode)
{
    // Take A is the coordinate root to start scanning
    C.x = A.x;
    C.y = B.y;

    if (box[C.y][C.x] == ' ')
    {
        if (checkLineH(box, C, B) && checkLineV(box, A, C))
        {
            mode = true;
            return true;
        }
    }

    C.x = B.x;
    C.y = A.y;

    if (box[C.y][C.x] == ' ')
    {
        if (checkLineV(box, C, B) && checkLineH(box, A, C))
        {
            mode = false;
            return true;
        }
    }

    return false;
}

//=========================== Tham khảo từ dòng 641 đến 710 ========================
//======================= Check L Shape ========================================
bool checkLShape(char** box, Point A, Point B, int col, int row, BackGround backGround)
{
    Point C;
    bool mode;
    Point temp;

    A.prepareSelected(B);

    if (checkHLShape(box, A, B, C, mode))
    {
        if (mode)
        {
            drawBox(box, col, row, A, GREEN, YELLOW);
            drawBox(box, col, row, B, GREEN, YELLOW);
            DrawHorizonLine(B, C);
            DrawVerticalLine(A, C);
            gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 3);
            cout << "This is L Shape";

            Sleep(1000);

            box[A.y][A.x] = ' ';
            box[B.y][B.x] = ' ';

            temp.x = B.x;
            temp.y = B.y;
            for (temp.x; temp.x >= C.x; temp.x--)
            {
                //DeleteCube(box, col, row, temp);
                backGround.PrintBG(col, row, temp);
            }

            C.prepareSelected(A);
            temp.x = C.x;
            temp.y = C.y;
            for (temp.y; temp.y <= A.y; temp.y++)
            {
                //DeleteCube(box, col, row, temp);
                backGround.PrintBG(col, row, temp);
            }
        }
        else
        {
            drawBox(box, col, row, A, GREEN, YELLOW);
            drawBox(box, col, row, B, GREEN, YELLOW);
            DrawVerticalLine(C, B);
            DrawHorizonLine(C, A);
            gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 3);
            cout << "This is L Shape";

            Sleep(1000);

            box[A.y][A.x] = ' ';
            box[B.y][B.x] = ' ';

            temp.x = A.x;
            temp.y = A.y;
            for (temp.x; temp.x <= B.x; temp.x++)
            {
                //DeleteCube(box, col, row, temp);
                backGround.PrintBG(col, row, temp);
            }

            C.prepareSelected(B);
            temp.x = C.x;
            temp.y = C.y;
            for (temp.y; temp.y <= B.y; temp.y++)
            {
                //DeleteCube(box, col, row, temp);
                backGround.PrintBG(col, row, temp);
            }
        }
        return true;
    }
    return false;
}

//=========================== Tham khảo từ dòng 713 đến 741 ========================
//======================= Check Horizontal Rectangle ===========================
bool checkHRectangle(char** box, Point A, Point B, Point& C, Point& D) {
    // Take A is the coordinate root to start scanning
    C = A;
    D.x = A.x;
    D.y = B.y;

    int maxX = max(A.x, B.x);
    int minX = min(A.x, B.x);

    for (int i = minX; i <= maxX; i++) {
        if (box[C.y][C.x] != ' ' || box[D.y][D.x] != ' ') {
            C.x++;
            D.x++;
            continue;
        }
        if (checkLineV(box, C, D)) {
            if (checkLineH(box, A, C) && checkLineH(box, B, D)) {
                return true;
            }
        }
        C.x++;
        D.x++;
    }
    return false;
}

//=========================== Tham khảo từ dòng 743 đến 773 ========================
//======================= Check Vertical Rectangle =============================
bool checkVRectangle(char** box, Point A, Point B, Point& C, Point& D) {
    // Take A is the coordinate root to start scanning
    C = A;
    D.x = B.x;
    D.y = A.y;

    int vec = (A.y > B.y) ? -1 : 1;

    int maxY = max(A.y, B.y);
    int minY = min(A.y, B.y);

    for (int i = minY; i <= maxY; i++) {
        if (box[C.y][C.x] != ' ' || box[D.y][D.x] != ' ') {
            C.y += vec;
            D.y += vec;
            continue;
        }
        if (checkLineH(box, C, D)) {  // Removed "difficulty" parameter
            if (checkLineV(box, A, C) && checkLineV(box, B, D)) {  // Removed "difficulty" parameter
                return true;
            }
        }
        C.y += vec;
        D.y += vec;
    }
    return false;
}

//=========================== Tham khảo từ dòng 775 đến 850 ========================
//======================= Check Rectangle ======================================
bool checkRectangle(char** box, Point A, Point B, int col, int row, BackGround backGround) {
    Point temp1, temp2;
    Point temp;

    A.prepareSelected(B);

    if (checkHRectangle(box, A, B, temp1, temp2)) {
        drawBox(box, col, row, A, GREEN, YELLOW);
        drawBox(box, col, row, B, GREEN, YELLOW);
        DrawVerticalLine(temp1, temp2);
        DrawHorizonLine(A, temp1);
        DrawHorizonLine(temp2, B);
        gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, col) + 3);
        cout << "This is Z shape\n";  // wprintf replaced with cout
        Sleep(1000);

        box[A.y][A.x] = ' ';
        box[B.y][B.x] = ' ';

        temp.y = A.y;
        for (int i = A.x; i <= temp1.x; i++) {
            // DeleteCube replaced with BackGround.PrintBG
            temp.x = i;
            backGround.PrintBG(col, row, temp);
            //DeleteCube(box, col, row, temp);
        }

        temp.y = B.y;
        for (int i = temp2.x; i <= B.x; i++) {
            // DeleteCube replaced with BackGround.PrintBG
            temp.x = i;
            backGround.PrintBG(col, row, temp);
            //DeleteCube(box, col, row, temp);
        }

        temp1.prepareSelected(temp2);
        temp.x = temp1.x;
        for (int i = temp1.y; i <= temp2.y; i++) {
            // DeleteCube replaced with BackGround.PrintBG
            temp.y = i;
            backGround.PrintBG(col, row, temp);
            //DeleteCube(box, col, row, temp);
        }

        return true;
    }

    if (checkVRectangle(box, A, B, temp1, temp2)) {
        drawBox(box, col, row, A, GREEN, YELLOW);
        drawBox(box, col, row, B, GREEN, YELLOW);
        DrawHorizonLine(temp1, temp2);
        DrawVerticalLine(A, temp1);
        DrawVerticalLine(temp2, B);
        gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, col) + 3);
        cout << "This is Z shape\n";  // wprintf replaced with cout
        Sleep(1000);

        box[A.y][A.x] = ' ';
        box[B.y][B.x] = ' ';

        temp.y = temp1.y;
        for (int i = temp1.x; i <= temp2.x; i++) {
            // DeleteCube replaced with BackGround.PrintBG
            temp.x = i;
            backGround.PrintBG(col, row, temp);
            //DeleteCube(box, col, row, temp);
        }

        A.prepareSelected(temp1);
        temp.x = A.x;
        for (int i = A.y; i <= temp1.y; i++) {
            // DeleteCube replaced with BackGround.PrintBG
            temp.y = i;
            backGround.PrintBG(col, row, temp);
            //DeleteCube(box, col, row, temp);
        }


        B.prepareSelected(temp2);
        temp.x = B.x;
        for (int i = B.y; i <= temp2.y; i++) {
            // DeleteCube replaced with BackGround.PrintBG
            temp.y = i;
            backGround.PrintBG(col, row, temp);
            //DeleteCube(box, col, row, temp);
        }

        return true;
    }

    return false;
}

//============================= Tham khảo từ dòng 853 đến 912 ========================
//======================= Check horizontal U ===================================
bool checkHorizontalU(char** box, Point A, Point B, int col, Point& C, Point& D) {
    int minY = min(A.y, B.y);
    int maxY = max(A.y, B.y);

    C.x = -1;
    C.y = minY;
    D.x = -1;
    D.y = maxY;

    // Exception: if A.y is higher than B.y ("?" vector)
    if (A.y > B.y && A.x < B.x) {
        C.swap(D);
    }

    // if (box[C.y][C.x] == box[A.y][A.x] &&)
    if (checkLineH(box, A, C) && checkLineH(box, B, D)) {
        return true;
    }

    C.x = col;
    C.y = minY;
    D.x = col;
    D.y = maxY;

    // Exception: if A.y is higher than B.y ("?" vector)
    if (A.y > B.y && A.x < B.x) {
        C.swap(D);
    }

    if (checkLineH(box, A, C) && checkLineH(box, B, D)) {
        return true;
    }

    for (C.x = 1, D.x = 1; D.x < B.x && C.x < A.x; C.x++, D.x++) {
        if (checkLineV(box, C, D) && box[C.y][C.x] == ' ' && box[D.y][D.x] == ' ') {
            if (checkLineH(box, A, C) && checkLineH(box, B, D)) {
                return true;
            }
        }
    }

    for (C.x = col - 1, D.x = col - 1; D.x > B.x && C.x > A.x; C.x--, D.x--) {
        if (checkLineV(box, C, D) && box[C.y][C.x] == ' ' && box[D.y][D.x] == ' ') {
            if (checkLineH(box, A, C) && checkLineH(box, B, D)) {
                return true;
            }
        }
    }

    return false;
}

//====================== Tham khảo từ dòng 915 đến dòng 961 =========================
//======================= Check vectical U =====================================
bool checkVerticalU(char** box, Point A, Point B, int row, Point& C, Point& D) {
    int minX = min(A.x, B.x);
    int maxX = max(A.x, B.x);

    C.x = minX;
    C.y = -1;
    D.x = maxX;
    D.y = -1;

    if (checkLineV(box, A, C) && checkLineV(box, B, D)) {
        return true;
    }

    C.x = minX;
    C.y = row;
    D.x = maxX;
    D.y = row;

    if (checkLineV(box, A, C) && checkLineV(box, B, D)) {
        return true;
    }

    for (C.y = 1, D.y = 1; D.y < B.y && C.y < A.y; C.y++, D.y++) {
        if (checkLineH(box, C, D) && box[C.y][C.x] == ' ' && box[D.y][C.x] == ' ') {
            if (checkLineV(box, A, C) && checkLineV(box, B, D)) {
                return true;
            }
        }
    }

    for (C.y = row - 1, D.y = row - 1; D.y > B.y && C.y > A.y; C.y--, D.y--) {
        if (checkLineH(box, C, D) && box[C.y][C.x] == ' ' && box[D.y][C.x] == ' ') {
            if (checkLineV(box, A, C) && checkLineV(box, B, D)) {
                return true;
            }
        }
    }

    return false;
}

//============================ Tham khảo từ dòng 963 đến 1116 =======================
//======================= Check U matching =====================================
bool checkUShape(char** box, Point A, Point B, int col, int row, BackGround backGround) {
    Point C;
    Point D;
    Point temp;
    A.prepareSelected(B);

    if (checkHorizontalU(box, A, B, col, C, D)) {
        // Draw the U shape
        drawBox(box, col, row, A, GREEN, YELLOW);  // Assuming drawBox replaces DrawCube
        drawBox(box, col, row, B, GREEN, YELLOW);
        DrawHorizonLine(A, C);
        DrawHorizonLine(B, D);
        DrawVerticalLine(C, D);

        // Display message and wait
        gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 3);
        cout << "This is U shape\n";
        Sleep(1000);

        // Clear original positions of A and B
        box[A.y][A.x] = ' ';
        box[B.y][B.x] = ' ';

        // Handle edge cases for horizontal line positions (C and D)
        if (A.y > B.y && A.x < B.x) {
            C.swap(D);  // Swap C and D if A is higher and to the left of B
        }

        int minX = min(A.x, C.x);
        int maxX = max(A.x, C.x);

        temp.y = A.y;
        // Clear the horizontal line between A and B (excluding A and B)
        for (int i = minX + 1; i < maxX; i++) {
            temp.x = i;
            //DeleteCube(box, col, row, temp);
            backGround.PrintBG(col, row, temp);  // Use backGround.PrintBG for clearing
        }

        minX = min(B.x, D.x);
        maxX = max(B.x, D.x);

        temp.y = B.y;
        for (int i = minX + 1; i < maxX; i++) {
            temp.x = i;
            //DeleteCube(box, col, row, temp);
            backGround.PrintBG(col, row, temp);
        }

        // Clear A and B positions using backGround.PrintBG
        //DeleteCube(box, col, row, A);
        //DeleteCube(box, col, row, B);
        backGround.PrintBG(col, row, A);
        backGround.PrintBG(col, row, B);

        // Handle edge cases for vertical line positions (C and D)
        if (C.x == -1) {
            int posXDel = calculatePositionWidth(-1, col) + 4;
            int posYDel = calculatePositionHeight(C.y, row) + 2;
            int sizeofLine = (D.y - C.y) * (WORD_HEIGHT_SPACING + 1) + 2;
            for (int i = 0; i < 5; i++) {
                RestoreColumn(posXDel + i, posYDel, sizeofLine);
            }
        }
        else if (C.x == col) {
            int posXDel = calculatePositionWidth(row, col);
            int posYDel = calculatePositionHeight(C.y, row) + 2;
            int sizeofLine = (D.y - C.y) * (WORD_HEIGHT_SPACING + 1) + 2;
            for (int i = 0; i < 5; i++) {
                RestoreColumn(posXDel + i, posYDel, sizeofLine);
            }
        }
        else {
            temp.x = C.x;
            temp.y = C.y;
            for (temp.y; temp.y <= D.y; temp.y++) {
                //DeleteCube(box, col, row, C);
                backGround.PrintBG(col, row, temp);  // Clear the vertical line
            }
        }

        return true;
    }
    if (checkVerticalU(box, A, B, row, C, D))
    {
        drawBox(box, col, row, A, GREEN, YELLOW);
        drawBox(box, col, row, B, GREEN, YELLOW);
        DrawVerticalLine(A, C);
        DrawVerticalLine(B, D);
        DrawHorizonLine(C, D);
        gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 3);
        cout << "This is U shape\n";

        Sleep(1000);

        box[A.y][A.x] = ' ';
        box[B.y][B.x] = ' ';

        int minY = min(A.y, C.y);
        int maxY = max(A.y, C.y);

        temp.x = A.x;
        for (int i = minY + 1; i < maxY; i++)
        {
            temp.y = i;
            //DeleteCube(box, col, row, temp);
            backGround.PrintBG(col, row, temp);
        }

        minY = min(B.y, D.y);
        maxY = max(B.y, D.y);

        temp.x = B.x;
        for (int i = minY + 1; i < maxY; i++)
        {
            temp.y = i;
            //DeleteCube(box, col, row, temp);
            backGround.PrintBG(col, row, temp);
        }

        //DeleteCube(box, col, row, A);
        //DeleteCube(box, col, row, B);
        backGround.PrintBG(col, row, A);
        backGround.PrintBG(col, row, B);

        if (C.y == -1)
        {
            int posXDel = calculatePositionWidth(C.x, col) + 3;
            int posYDel = calculatePositionHeight(-1, row) + 2;
            int sizeofLine = (D.x - C.x) * (WORD_WIDTH_SPACING + 1) + 2;
            for (int i = 0; i < 2; i++)
            {
                RestoreLine(posXDel, posYDel + i, sizeofLine);
            }
        }
        else if (C.y == row)
        {
            int posXDel = calculatePositionWidth(C.x, col) + 3;
            int posYDel = calculatePositionHeight(C.y, row) + 1;
            int sizeofLine = (D.x - C.x) * (WORD_WIDTH_SPACING + 1) + 2;
            for (int i = 0; i < 2; i++)
            {
                RestoreLine(posXDel, posYDel + i, sizeofLine);
            }
        }
        else
        {
            temp.x = C.x;
            temp.y = C.y;
            for (temp.x; temp.x <= D.x; temp.x++)
            {
                //DeleteCube(box, col, row, temp);
                backGround.PrintBG(col, row, temp);
            }
        }
        return true;
    }
    return false;
}

//=========================== Tham khảo dòng 1123 đến 1136 ==================
bool isSolved(char** box, int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (box[i][j] != ' ')
            {
                return false;
            }
        }
    }
    return true;
}

//=========================== Tham khảo dòng 1139 đến 1204 ==================
//======================= Check if two box are the same ========================
bool checkNodeIdentical(char**& box, int col, int row, Point& a, Point& b, BackGround backGround)
{
    bool identical = false;

    identical = (box[a.y][a.x] == box[b.y][b.x]);

    // Check if 2 node can link with together with pattern
    if (identical)
    {
        if (checkLine(box, a, b, col, row, backGround))
        {
            a.isSelected = false;
            b.isSelected = false;
            return true;
        }
        else if (checkLShape(box, a, b, col, row, backGround))
        {
            a.isSelected = false;
            b.isSelected = false;
            return true;
        }
        else if (checkRectangle(box, a, b, col, row, backGround))
        {
            a.isSelected = false;
            b.isSelected = false;
            return true;
        }
        else if (checkUShape(box, a, b, col, row, backGround))
        {
            a.isSelected = false;
            b.isSelected = false;
            return true;
        }
        drawBox(box, col, row, a, RED, YELLOW);
        drawBox(box, col, row, b, RED, YELLOW);
        cout << char(7);
        Sleep(1000);
        //score.addError();

        drawBox(box, col, row, a, BLACK, WHITE);
        drawBox(box, col, row, b, BLACK, WHITE);
        a.isSelected = false;
        b.isSelected = false;
        return false;
    }

    // If 2 node is not the same, hightlight the 2 node with red backgound_color and delay for 1 second
    if (!identical)
    {
        // Highlight the 2 node with red backgound_color
        drawBox(box, col, row, a, RED, YELLOW);
        drawBox(box, col, row, b, RED, YELLOW);
        cout << char(7);
        Sleep(1000);
        //score.addError();

        // Delete the red background_color
        drawBox(box, col, row, a, BLACK, WHITE);
        drawBox(box, col, row, b, BLACK, WHITE);
        a.isSelected = false;
        b.isSelected = false;
    }

    return identical;
}

//=========================== Tham khảo dòng 1207 đến 1246 ==================
bool checkNodeIdenticalN(char** box, int col, int row, Point A, Point B)
{
    Point C, D;
    bool mode = 0;

    A.prepareSelected(B);

    if (checkLineH(box, A, B))
    {
        return true;
    }
    else if (checkLineV(box, A, B))
    {
        return true;
    }
    else if (checkHLShape(box, A, B, C, mode))
    {
        return true;
    }
    else if (checkHRectangle(box, A, B, C, D))
    {
        return true;
    }
    else if (checkVRectangle(box, A, B, C, D))
    {
        return true;
    }
    else if (checkHorizontalU(box, A, B, col, C, D))
    {
        return true;
    }
    else if (checkVerticalU(box, A, B, row, C, D))
    {
        return true;
    }
    else
    {
        return false;
    }
}


//=========================== Tham khảo dòng 1249 đến 1327 ==================
bool checkSolve(char**& box, int col, int row)
{
    bool isChecked = false;
    // Find pair of identical elements in the matrix, run the checkNodeIdentical function to check if the pair can link with pattern, if true, delete the pair and start again
    char** temp = NULL;
    temp = new char* [row];
    for (int i = 0; i < row; i++) {
        temp[i] = new char[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp[i][j] = box[i][j];
        }
    }

    while (!isChecked) {
        int check = 0;
        for (int i = 0; i < row; i++) // i is the y coordinate
        {
            for (int j = 0; j < col; j++) // j is the x coordinate
            {
                // If a[i][j] is space or ' ', continue
                if (temp[i][j] == ' ')
                {
                    continue;
                }

                for (int k = 0; k < row; k++) // k is the y coordinate
                {
                    for (int l = 0; l < col; l++) // l is the x coordinate
                    {
                        if (i == k && j == l)
                        {
                            continue;
                        }

                        if (temp[i][j] != temp[k][l])
                        {
                            continue;
                        }

                        // If a[i][j] is the same as a[k][l], check if the pair can link with pattern
                        Point A, B;
                        A.x = j;
                        A.y = i;
                        B.x = l;
                        B.y = k;

                        if (checkNodeIdenticalN(temp, col, row, A, B))
                        {
                            temp[i][j] = ' ';
                            temp[k][l] = ' ';
                            check = 1;
                        }
                        if (check == 1) {
                            isChecked = true;
                        }
                        else {
                            isChecked = false;
                        }
                    }
                }
            }
        }
    }
    if (isSolved(temp, col, row))
    {
        // Free temp
        for (int i = 0; i < row; i++)
        {
            delete[] temp[i];
        }
        delete[] temp;

        return true;
    }

    // Free temp
    for (int i = 0; i < row; i++)
    {
        delete[] temp[i];
    }
    delete[] temp;


    return false;
}

//=========================== Tham khảo dòng 1329 đến 1373 ==================
//======================== Help move =================================
void helpMove(char**& box, int col, int row)
{
    for (int i = 0; i < row; i++) // i is the y coordinate
    {
        for (int j = 0; j < col; j++) // j is the x coordinate
        {
            // If a[i][j] is space or ' ', continue
            if (box[i][j] == ' ')
            {
                continue;
            }

            for (int k = 0; k < row; k++) // k is the y coordinate
            {
                for (int l = 0; l < col; l++) // l is the x coordinate
                {
                    if (i == k && j == l)
                    {
                        continue;
                    }

                    if (box[i][j] != box[k][l])
                    {
                        continue;
                    }

                    // If a[i][j] is the same as a[k][l], check if the pair can link with pattern
                    Point A;
                    A.x = j;
                    A.y = i;
                    Point B;
                    B.x = l;
                    B.y = k;

                    if (checkNodeIdenticalN(box, col, row, A, B))
                    {
                        drawBox(box, col, row, A, GRAY, YELLOW);
                        drawBox(box, col, row, B, GRAY, YELLOW);
                        Sleep(1000);

                        drawBox(box, col, row, A, BLACK, WHITE);
                        drawBox(box, col, row, B, BLACK, WHITE);
                        return;
                    }
                }
            }
        }
    }
}
//============== Hàm tự code =====================
//============== Playing Box =====================
void playingBox(char**& box, int col, int row) {
    bool isShuffled = false;
    while (!isShuffled) {
        int index = 0;
        int size = col * row;
        char* temparray = new char[size];
        box = new char* [row];
        for (int i = 0; i < row; i++) {
            box[i] = new char[col];
        }

        //============= Random Matrix ====================
        for (int i = 0; i < size; i += 2) {
            char ch = 'A' + rand() % 26;
            temparray[i] = ch;
            temparray[i + 1] = ch;
        }
        for (int i = size - 1; i > 0; --i) {
            // Generate a random index between 0 and i (inclusive)
            int j = rand() % (i + 1);

            // Swap arr[i] with arr[j]
            swap(temparray[i], temparray[j]);
        }

        //============= Value in matrix ==================
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                box[i][j] = temparray[index++];
            }
        }
        delete[] temparray;
        isShuffled = checkSolve(box, col, row);
    }
}

//============================================ Tham khảo dòng 1423 đến 1433 =============================================
bool moveToPosition(char** box, int col, int row, int posX, int posY)
{
    if (posX < 0 || posX >= col || posY < 0 || posY >= row)
    {
        return true;
    }
    Point temp;
    temp.x = posX;
    temp.y = posY;
    drawBox(box, col, row, temp, WHITE, BLACK);

    return false;
}

//=========================================== Tham khảo dòng 1445 đến 1540 ===============================================
//================== Coordinate Valid =====================
Point coordinateValid(char** box, int col, int row, char move, Point location)
{
    Point temp;
    switch (move)
    {
    case 'w':
        for (int i = location.y - 1; i >= 0; i--)
        {
            for (int j = 0; j < col; j++)
            {
                if (box[i][j] != ' ')
                {
                    temp.y = i;
                    temp.x = j;
                    return temp;
                }
            }
        }

        for (int i = row - 1; i > location.y; i--)
        {
            for (int j = 0; j < col; j++)
            {
                if (box[i][j] != ' ')
                {
                    temp.y = i;
                    temp.x = j;
                    return temp;
                }
            }
        }
    case 's':
        for (int i = location.y + 1; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (box[i][j] != ' ')
                {
                    temp.y = i;
                    temp.x = j;
                    return temp;
                }
            }
        }

        for (int i = 0; i <= location.y; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (box[i][j] != ' ')
                {
                    temp.y = i;
                    temp.x = j;
                    return temp;
                }
            }
        }
    case 'a':
        for (int i = location.x - 1; i >= 0; i--)
        {
            for (int j = 0; j < row; j++)
            {
                if (box[j][i] != ' ')
                {
                    temp.x = i;
                    temp.y = j;
                    return temp;
                }
            }
        }

        for (int i = col - 1; i > location.x; i--)
        {
            for (int j = 0; j < row; j++)
            {
                if (box[j][i] != ' ')
                {
                    temp.x = i;
                    temp.y = j;
                    return temp;
                }
            }
        }
    case 'd':
        for (int i = location.x + 1; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (box[j][i] != ' ')
                {
                    temp.x = i;
                    temp.y = j;
                    return temp;
                }
            }
        }

        for (int i = 0; i < location.x; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (box[j][i] != ' ')
                {
                    temp.x = i;
                    temp.y = j;
                    return temp;
                }
            }
        }
    }
    temp.x = -1;
    temp.y = -1;
    return temp;
}

//====================================== Tham khảo dòng 1542 đến 1583 ============================================
//================== Coordinate H ==========================
int coordinateH(char** box, int row, bool up, Point move) {
    if (up == true)
    {

        for (int i = move.y - 1; i >= 0; i--)
        {
            //if (box[i][move.x] != ' ')
            //{
                return i;
            //}
        }

        for (int i = row - 1; i > move.y; i--)
        {
            //if (box[i][move.x] != ' ')
            //{
                return i;
            //}
        }

        return -1;
    }

    for (int i = move.y + 1; i < row; i++)
    {
        //if (box[i][move.x] != ' ')
        //{
            return i;
        //}
    }

    for (int i = 0; i <= move.y; i++)
    {
        //if (box[i][move.x] != ' ')
        //{
            return i;
        //}
    }

    return -1;
}

//======================================= Tham khảo dòng 1585 đến 1625 =====================================
//=============================== Coordinate V ============================
int coordinateV(char** box, int col, bool left, Point move)
{
    if (left == true)
    {
        for (int i = move.x - 1; i >= 0; i--)
        {
            //if (box[move.y][i] != ' ')
            //{
                return i;
            //}
        }

        for (int i = col - 1; i > move.x; i--)
        {
            //if (box[move.y][i] != ' ')
            //{
                return i;
            //}
        }

        return -1;
    }

    for (int i = move.x + 1; i < col; i++)
    {
        //if (box[move.y][i] != ' ')
        //{
            return i;
        //}
    }

    for (int i = 0; i < move.x; i++)
    {
        //if (box[move.y][i] != ' ')
        //{
            return i;
        //}
    }

    return -1;
}

//======================================== Tham khảo từ dòng 1727 đến 1851 ==========================================
//========Hàm di chuy?n ô tr?ng sang v? trí khác trong h?p=======
void movingBox(char**& box, int col, int row, char ch, Point& location, Point& firstNode, Point& secondNode, Point& tempNode, int& posX, int& posY, BackGround backGround) {
    Point temp;
    while ((ch = GetArrow()) != ESC_KEY)
    {
        switch (ch)
        {
        case ARROW_UP:
            PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
            temp.x = posX;
            temp.y = posY;
            posY = coordinateH(box, row, true, temp);
            if (posY == -1)
            {
                temp.y = posY;
                Point newCor = coordinateValid(box, col, row, 'w', temp);
                posX = newCor.x;
                posY = newCor.x;
            }
            break;
        case ARROW_DOWN:
            PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
            temp.x = posX;
            temp.y = posY;
            posY = coordinateH(box, row, false, temp);
            if (posY == -1)
            {
                temp.y = posY;
                Point newCor = coordinateValid(box, col, row, 's', temp);
                posX = newCor.x;
                posY = newCor.y;
            }
            break;
        case ARROW_LEFT:
            PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
            temp.x = posX;
            temp.y = posY;
            posX = coordinateV(box, col, true, temp);
            if (posX == -1)
            {
                temp.x = posX;
                Point newCor = coordinateValid(box, col, row, 'a', temp);
                posX = newCor.x;
                posY = newCor.y;
            }
            break;
        case ARROW_RIGHT:
            PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
            temp.x = posX;
            temp.y = posY;
            posX = coordinateV(box, col, false, temp);
            if (posX == -1)
            {
                temp.x = posX;
                Point newCor = coordinateValid(box, col, row, 'd', temp);
                posX = newCor.x;
                posY = newCor.y;
            }
            break;
        case HELP:
            helpMove(box, col, row);
            break;
        case ENTER_KEY:
            PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
            if (box[posY][posX] == ' ')
                break;
            if (!firstNode.isSelected)
            {
                gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 1);
                cout << "First Node Selected\n";
                firstNode.isSelected = true;
                firstNode.x = posX;
                firstNode.y = posY;
            }
            else if (!secondNode.isSelected)
            {
                if (firstNode.x == posX && firstNode.y == posY)
                {
                    gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 1);
                    cout << "You can't select the same node twice\n";
                    continue;
                }
                gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 1);
                cout << "Second Node Selected\n";
                secondNode.isSelected = true;
                secondNode.x = posX;
                secondNode.y = posY;
            }
            else
            {
                gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 3);
                cout << "You can't select more than 2 nodes\n";
            }
            break;
        default:
            break;
        }
        //================ Draw Box Back =======================
        drawBox(box, col, row, tempNode, BLACK, WHITE);
        //================ Selecting Box =========================
        if (firstNode.isSelected)
        {
            drawBox(box, col, row, firstNode, AQUA, BLACK);
        }

        if (secondNode.isSelected)
        {
            drawBox(box, col, row, firstNode, AQUA, BLACK);
            firstNode.prepareSelected(secondNode);

            // Check if 2 nodes are selected is the same character
            if (checkNodeIdentical(box, col, row, firstNode, secondNode, backGround))
            {
                PlaySound(TEXT("cute-level-up-2-189851.wav"), NULL, SND_FILENAME | SND_ASYNC);
                gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 2);
                cout << "2 nodes are identical\n";
                // Draw background at the posX and posY coordinates

                // Check local elements of the matrix if it different from ' '
                //Point newCor = checkLocalElements(matrix, difficulty, secondNode);

                //posX = newCor.posX;
                //posY = newCor.posY;
            }
            else
            {
                gotoXY(WORD_WIDTH_SPACING, calculatePositionHeight(row, row) + 2);
                cout << "2 nodes are different\n";
            }

            /*if (isSolved(matrix, difficulty))
            {
                GoTo(WORD_WIDTH_SPACING, calculatePositionHeight(difficulty, difficulty) + 3);
                wprintf(L"You win\n");
            }*/
        }

        if (moveToPosition(box, col, row, posX, posY))
        {
            break;
        }

        tempNode.x = posX;
        tempNode.y = posY;
    }
}

//===================================== Hàm chạy game =====================================
void runningGame(int col, int row) {
    Point one;
    one.x = 0;
    one.y = 0;
    //============== Point location ===============
    Point location;
    location.x = 0;
    location.y = 0;
    int posX = location.x;
    int posY = location.y;
    char ch = ENTER_KEY;
    //============== Point firstNode ==============
    Point firstNode;
    firstNode.x = -1;
    firstNode.y = -1;
    firstNode.isSelected = false;
    //============== Point secondNode =============
    Point secondNode;
    secondNode.x = -1;
    secondNode.y = -1;
    secondNode.isSelected = false;
    //============== Point tempNode ================
    Point tempNode;
    tempNode.x = 0;
    tempNode.y = 0;
    tempNode.isSelected = false;
    //============== Playing game ====================
    BackGround backGround;
    backGround.GetBG(col, row);
    playingBox(box, col, row);
    printBoard(box, col, row);
    DrawBorder(col, row);
    drawBox(box, col, row, one, WHITE, BLACK);
    movingBox(box, col, row, ch, location, firstNode, secondNode, tempNode, posX, posY, backGround);
}