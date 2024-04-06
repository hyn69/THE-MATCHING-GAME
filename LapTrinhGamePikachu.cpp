// LapTrinhGamePikachu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "ThuVien.h"
#include "ThuVienGameThamKhao.h"
#include "ThuVienGiaoDien.h"
#define _WIN32_WINNT 0x0501
using namespace std;


void set_color(int color) {
    // ANSI escape code to set the color
    std::cout << "\033[" << color << "m";
}

int main()
{   
    srand(time(NULL));
    Player p;
    loadingScreen();
    PlaySound(TEXT("game-start-6104.wav"), NULL, SND_FILENAME | SND_ASYNC);
    introGame(p);
    /*maxsc();
    srand(time(NULL));
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
    playingBox(box, col, row);
    drawBox(box, index, jdex);
    coutBox(box, col, row);
    x = whereX();
    y = whereY();
    y -= row;
    movingBox(box, index, jdex, row, col, x, y);*/
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
