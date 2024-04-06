/*Source code này lấy từ https://paste.ubuntu.com/p/tqr239C4df/ được làm ra bởi https://www.youtube.com/@thientamnguyen.94
	và từ video: https://www.youtube.com/watch?v=jdpBqzf-jNQ&list=PLimFJKGsbn1m_z8pjCh5TdjyM5s5NlxU_&index=1 (Phút thứ 4:27 đến phút 6:32)
*/
#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include <iostream>
#include <cctype>
#include <stdio.h>
#include <conio.h>
#include <ctime> /* thư viện hỗ trợ về thời gian thực */
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <fstream>
#include <algorithm>
#include <mmsystem.h> // Include header file
#pragma comment(lib, "winmm.lib") // Link with Winmm.lib (if your compiler supports pragma comments)
//=============Thư viện hỗ trợ tăng heap memory ================
#include <stddef.h>
#define SIZEOF_HEAP  0x200
char _REL_sysheap[SIZEOF_HEAP];
size_t _REL_sizeof_sysheap = SIZEOF_HEAP;

#pragma comment(lib, "user32")

#define BLACK 0
#define AQUA 3
#define RED 4
#define WHITE 7
#define GRAY 8
#define GREEN 10
#define YELLOW 14

using namespace std;
char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char** box = NULL;

//======= lấy tọa độ x của con trỏ hiện tại =============
#define KEY_NONE -1
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
// Set console color
void SetColorBox(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
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
//============= Hàm chỉnh màn hình rộng . Source code: https://stackoverflow.com/questions/71731641/how-to-make-console-automatically-zoom-to-full-screen-when-running-in-c
void maxsc()
{
	HWND Hwnd = GetForegroundWindow();
	ShowWindow(Hwnd, SW_MAXIMIZE);
}
