/*Source code này lấy từ https https://paste.ubuntu.com/p/tqr239C4df/ được làm ra bởi https://www.youtube.com/@thientamnguyen.94
	và từ video: https://www.youtube.com/watch?v=jdpBqzf-jNQ&list=PLimFJKGsbn1m_z8pjCh5TdjyM5s5NlxU_&index=1 (Phút thứ 4:27 đến phút 6:32)
*/
#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include <cctype>
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" 
#include <time.h>
#include <stdlib.h>
using namespace std;
char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char** box = NULL;

//======= lấy tọa độ x của con trỏ hiện tại =============
#define KEY_NONE	-1
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= đặt màu cho chữ =========
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= trả về mã phím người dùng bấm =========
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}
//Thư viện mà nhóm em tự code: 

//========Hàm tạo hộp =======
void playingBox(char** &box, int col, int row) {
    int n = row;
    int m = col;
    int colChar = (m - 1) / 4;
    int rowChar = (n - 1) / 8;
    int iChar = 0;
    int jChar = 0;
    int randRow = 0;
    int randCol = 0;
    char temp;
    box = new char* [n];
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
}
//=======Hàm xuất hộp ra màn hình ========
void coutBox(char** &box, int col, int row) {
    int n = row;
    int m = col;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << box[i][j];
        }
        cout << endl;
    }
}
//=========Hàm vẽ ra ô trắng===========
void drawBox(char** &box, int index, int jdex) {
    for (int i = index; i < index + 3; i++) {
        for (int j = jdex; j < jdex + 7; j++) {
            if (isalpha(box[i][j]))
                continue;
            box[i][j] = char(219);
        }
    }
}
//========Hàm xóa ô trắng==========
void undrawBox(char**& box, int index, int jdex) {
    for (int i = index; i < index + 3; i++) {
        for (int j = jdex; j < jdex + 7; j++) {
            if (box[i][j] == char(219))
                box[i][j] = ' ';
        }
    }
}
//========Hàm xóa hộp=============
void xoadulieuCu(int row, int col, int x, int y) {
    gotoXY(x, y);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << ' ';
        }
        cout << endl;
    }
}
//=========Hàm xóa ô trong hộp======
void deleteBox(char**& box, int index, int jdex) {
    for (int i = index - 1; i < index + 4; i++) {
        for (int j = jdex - 1; j < jdex + 8; j++) {
            box[i][j] = ' ';
        }
    }
}
/*void selectBox(char** box, int& index, int& jdex, int row, int col, int x, int y, int key) {
    if (key == 13) {

    }
}*/
//========Hàm di chuyển ô trắng sang vị trí khác trong hộp=======
void movingBox(char** &box, int index, int jdex, int row, int col, int x, int y) {
    int check = 0;
    char checkChar = ' ';
    int tempindex;
    int tempjdex;
    while (true)
    {
        if (_kbhit()) {
            int key = _getch();
            //Nếu người dùng nhập vào bàn phím các nút w,a,s,d thì sẽ di chuyển sang ô khác
            switch (key) {
            case 13:
                if (check == 1) {
                    if (checkChar == box[index+1][jdex+3]) {
                        deleteBox(box, index, jdex);
                        deleteBox(box, tempindex, tempjdex);
                        undrawBox(box, index, jdex);
                    }
                    check = 0;
                    undrawBox(box, tempindex, tempjdex);
                }
                check = 1;
                tempindex = index;
                tempjdex = jdex;
                checkChar = box[tempindex+1][tempjdex+3];
                break;
            case 'w':
                undrawBox(box, index, jdex);
                index -= 4;
                //Hàm if này kiểm tra giá trị của ô trắng đó có vượt qua dòng đầu tiên trong hộp không, nếu có trả về giá trị dòng ban đầu
                if (index < 0)
                    index = 1;
                if (check == 1) {
                    drawBox(box, tempindex, tempjdex);
                }
                drawBox(box, index, jdex);
                break;
            case 's':
                undrawBox(box, index, jdex);
                index += 4;
                //Hàm if này kiểm tra giá trị của ô trắng đó có vượt qua dòng cuối cùng trong hộp không, nếu có trả về giá trị dòng cuối cùng
                if (index > row - 4 + 1)
                    index = row - 4;
                if (check == 1) {
                    drawBox(box, tempindex, tempjdex);
                }
                drawBox(box, index, jdex);
                break;
            case 'a':
                undrawBox(box, index, jdex);
                jdex -= 8;
                if (jdex < 0)
                    jdex = 1;
                if (check == 1) {
                    drawBox(box, tempindex, tempjdex);
                }
                drawBox(box, index, jdex);
                break;
            case 'd':
                undrawBox(box, index, jdex);
                jdex += 8;
                if (jdex > col - 8 + 1)
                    jdex = col - 8;
                if (check == 1) {
                    drawBox(box, tempindex, tempjdex);
                }
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
}
