#pragma once
#include "ThuVien.h"
#include "ThuVienGameThamKhao.h"

struct Player {
    string name;
    string password;
    int score;
};
struct highScore {
    Player highGrade;
    highScore* p_next;
    highScore() {
        p_next = NULL;
    }
};
void loadingScreen();
void drawingTitle();
void introGame(Player& p);
void loginGame(Player& p);
void addPlayerInfor(Player p, highScore*& infor);
void signUp(Player& p);
void checkPlayerInfor(Player p, highScore*& infor);
void signIn(Player& p);
void gameMode(Player& p);
//================== Ham ve loading game ================
void loadingScreen() {
    maxsc();
    system("COLOR 0e");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177;
    int bar2 = 219;
    int x = 40;
    int y = 0;
    //=================== LOGO 23CLC08 =================
    gotoXY(x, y++);
    cout << "  _______  ________  ________  ___       ________  ________  ________     ";
    gotoXY(x, y++);
    cout << " /  ___  \\|\\_____  \\|\\   ____\\|\\  \\     |\\   ____\\|\\   __  \\|\\   __  \\    ";
    gotoXY(x, y++);
    cout << "/__/|_/  /\\|____|\\ /\\ \\  \\___|\\ \\  \\    \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\|\\  \\   ";
    gotoXY(x, y++);
    cout << "|__|//  / /     \\|\\  \\ \\  \\    \\ \\  \\    \\ \\  \\    \\ \\  \\\\\\  \\ \\   __  \\  ";
    gotoXY(x, y++);
    cout << "    /  /_/__   __\\_\\  \\ \\  \\____\\ \\  \\____\\ \\  \\____\\ \\  \\\\\\  \\ \\  \\|\\  \\ ";
    gotoXY(x, y++);
    cout << "   |\\________\\|\\_______\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\";
    gotoXY(x, y++);
    cout << "    \\|_______|\\|_______|\\|_______|\\|_______|\\|_______|\\|_______|\\|_______|";
    //================== THANH LOADING ========================
    x += 15;
    y += 5;
    gotoXY(x, y++);
    cout << ".-.    .----.   .--.  .----. .-..-. .-. .---. ";
    gotoXY(x, y++);
    cout << "| |   /  {}  \\ / {} \\ | {}  \\| ||  `| |/   __}";
    gotoXY(x, y++);
    cout << "| `--.\\      //  /\\  \\|     /| || |\\  |\\  {_ }";
    gotoXY(x, y++);
    cout << "`----' `----' `-'  `-'`----' `-'`-' `-' `---' ";
    gotoXY(0, ++y);
    for (int i = 0; i < 156; i++)
        cout << (char)bar1;
    cout << "\r";
    cout << "\t\t\t\t";
    gotoXY(0, y);
    for (int i = 0; i < 156; i++) {
        cout << (char)bar2;
        Sleep(10);
    }
    system("cls");
}

//=================== Ham ve intro game ==========================
void introGame(Player& p) {
    drawingTitle();
    int x_new = 70;
    int y_new = 20;

    //============= The Selection Box 1 =============
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    int i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 2, y_new + i + 1);
        cout << "New Game";
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }

    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);

    int x1 = x_new - 2;
    int y1 = y_new + 1;
    gotoXY(x1, y1);
    cout << "->";
    y_new += 4;

    //============= The Selection Box 2 ==============
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 3, y_new + i + 1);
        cout << "Option";
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }

    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);

    int x2 = x_new - 2;
    int y2 = y_new + 1;

    y_new += 4;

    //============= The Selection Box 3 ==============
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 4, y_new + i + 1);
        cout << "Exit";
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }

    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);
    int x3 = x_new - 2;
    int y3 = y_new + 1;
    int choose = 0;
    int k = 0;
    int x_phao = 68;
    char c;
    //================== Hàm này trả về giá trị của từng ô giá trị trong bảng menu
    gotoXY(x1, y1);
    while (true)
    {
        if (_kbhit())
        {
            c = _getch();
            if (c == 'w') {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                if (x_check == (x1) && y_check == (y1)) {
                    continue;
                }
                else if (x_check == (x2) && y_check == (y2)) {
                    cout << "  ";
                    gotoXY(x1, y1);
                    cout << "->";
                    gotoXY(x1, y1);
                }
                else if (x_check == (x3) && y_check == (y3)) {
                    cout << "  ";
                    gotoXY(x2, y2);;
                    cout << "->";
                    gotoXY(x2, y2);
                }
            }
            else if (c == 's') {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                if (x_check == (x3) && y_check == (y3)) {
                    continue;
                }
                else if (x_check == (x1) && y_check == (y1)) {
                    cout << "  ";
                    gotoXY(x2, y2);
                    cout << "->";
                    gotoXY(x2, y2);
                }
                else if (x_check == (x2) && y_check == (y2)) {
                    cout << "  ";
                    gotoXY(x3, y3);;
                    cout << "->";
                    gotoXY(x3, y3);
                }
            }
            else if (c == 13) {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                //====== Hàm if dùng check ô mà con trỏ hướng tới
                if (x_check == x1 && y_check == y1) {
                    choose = 1;
                }
                else if (x_check == x2 && y_check == y2) {
                    choose = 2;
                }
                else if (x_check == x3 && y_check == y3) {
                    choose = 3;
                }
                //======= Hàm if trả về giá trị mà con trỏ hướng tới
                if (choose == 1) {
                    system("cls");
                    //runningGame();
                    loginGame(p);
                    break;
                }
                else if (choose == 2) {
                    system("cls");
                    SetColor(15);
                    cout << "\n\n\nCreator: Ton That Hoan And Hoang Nhan \n";
                    cout << "\nDate: 24/04/2024\n";
                    SetColor(8);
                    cout << " \n\n\t\t==========================  Story  ==========================\n\n";
                    cout << "\t\t\t\tYou are a mother snake in the small garden.\n\t\t\t\tYour son is a strong snake who can puff fire.\n";
                    cout << "\t\t\t\tThe main mission of this game is to make the villagers around you happy.\n\t\t\t\tNow, it have just completed round 1.\n\n";
                    cout << "\t\t\t\t\t\t\t\t\tEnjoy the game,\n";
                    Sleep(8500);
                    system("cls");
                    break;
                }
                else if (choose == 3)
                {
                    system("cls");
                    break;
                }
            }
        }
    }
}

//====================== Ham ve Login Game ====================
void loginGame(Player& p) {
    drawingTitle();
    int x_new = 70;
    int y_new = 20;

    //============= The Selection Box 1 =============
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    int i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 2, y_new + i + 1);
        cout << "Sign Up";
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }

    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);

    int x1 = x_new - 2;
    int y1 = y_new + 1;
    gotoXY(x1, y1);
    cout << "->";
    y_new += 4;

    //============= The Selection Box 2 ==============
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 3, y_new + i + 1);
        cout << "Login";
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }

    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);

    int x2 = x_new - 2;
    int y2 = y_new + 1;

    y_new += 4;

    //============= The Selection Box 3 ==============
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 4, y_new + i + 1);
        cout << "Back";
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }

    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);
    int x3 = x_new - 2;
    int y3 = y_new + 1;
    int choose = 0;
    int k = 0;
    int x_phao = 68;
    char c;
    gotoXY(x1, y1);
    while (true)
    {
        if (_kbhit())
        {
            c = _getch();
            if (c == 'w') {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                if (x_check == (x1) && y_check == (y1)) {
                    continue;
                }
                else if (x_check == (x2) && y_check == (y2)) {
                    cout << "  ";
                    gotoXY(x1, y1);
                    cout << "->";
                    gotoXY(x1, y1);
                }
                else if (x_check == (x3) && y_check == (y3)) {
                    cout << "  ";
                    gotoXY(x2, y2);;
                    cout << "->";
                    gotoXY(x2, y2);
                }
            }
            else if (c == 's') {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                if (x_check == (x3) && y_check == (y3)) {
                    continue;
                }
                else if (x_check == (x1) && y_check == (y1)) {
                    cout << "  ";
                    gotoXY(x2, y2);
                    cout << "->";
                    gotoXY(x2, y2);
                }
                else if (x_check == (x2) && y_check == (y2)) {
                    cout << "  ";
                    gotoXY(x3, y3);;
                    cout << "->";
                    gotoXY(x3, y3);
                }
            }
            else if (c == 13) {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                //====== Hàm if dùng check ô mà con trỏ hướng tới
                if (x_check == x1 && y_check == y1) {
                    choose = 1;
                }
                else if (x_check == x2 && y_check == y2) {
                    choose = 2;
                }
                else if (x_check == x3 && y_check == y3) {
                    choose = 3;
                }
                //======= Hàm if trả về giá trị mà con trỏ hướng tới
                if (choose == 1) {
                    system("cls");
                    Sleep(20);
                    signUp(p);
                    break;
                }
                else if (choose == 2) {
                    system("cls");
                    Sleep(20);
                    signIn(p);
                    break;
                }
                else if (choose == 3)
                {
                    system("cls");
                    introGame(p);
                    break;
                }
            }
        }
    }
}

//================== Ham nhan thong tin nguoi choi =====================
void addPlayerInfor(Player p, highScore*& infor) {
    highScore* newInfor = new highScore; // Allocate memory for newInfor
    newInfor->highGrade = p;
    newInfor->p_next = infor;
    infor = newInfor;

    fstream openFile("Player_infor.txt", ios::out | ios::app);
    if (!openFile.is_open()) {
        cout << "Cannot open file" << endl;
    }
    else {
        cout << "File opened successfully" << endl;
        highScore* temp = infor;
        openFile.seekg(0);
        while (temp != NULL) {
            openFile << temp->highGrade.name << " " << temp->highGrade.password << endl;
            temp = temp->p_next;
        }
        openFile.close(); // Close the file when done
    }
}

//=================== Hàm đăng ký ===================
void signUp(Player& p) {
    int row = 0;
    int col = 0;
    drawingTitle();
    char c = 205;
    SetColor(7);
    for (int i = 50; i <= 100; i++)
    {
        gotoXY(i, 20); cout << c;
        gotoXY(i, 31); cout << c;
    }
    gotoXY(52, 22);
    cout << "Please enter your name: ";
    int x_name = whereX();
    int y_name = whereY();
    gotoXY(52, 24);
    cout << "Please enter your password: ";
    int x_pass = whereX();
    int y_pass = whereY();
    //======================== Hàm in ra hộp Sign Up =====================
    int x_new = 55;
    int y_new = 27;
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    int i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }
    gotoXY(x_new + 2, y_new + 1);
    cout << "Sign up";
    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);
    c = 186;
    for (int j = 21; j <= 30; j++)
    {
        gotoXY(50, j); cout << c;
    }
    for (int j = 21; j <= 30; j++)
    {
        gotoXY(100, j); cout << c;
    }
    int xsignUp = x_new - 2;
    int ysignUp = y_new + 1;
    gotoXY(xsignUp, ysignUp);
    cout << "->";
    //======================== Hàm in ra hộp Back =====================
    x_new = 83;
    y_new = 27;
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }
    gotoXY(x_new + 2, y_new + 1);
    cout << "  Back";
    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);
    c = 186;
    for (int j = 21; j <= 30; j++)
    {
        gotoXY(50, j); cout << c;
    }
    for (int j = 21; j <= 30; j++)
    {
        gotoXY(100, j); cout << c;
    }
    int xBack = x_new - 2;
    int yBack = y_new + 1;
    //============== Hàm lấy thông tin người chơi ====================
    gotoXY(x_name, y_name);
    getline(cin, p.name);
    gotoXY(x_pass, y_pass);
    getline(cin, p.password);
    //============== Hàm điều khiển con trỏ ==================
    int choose = 0;
    gotoXY(xsignUp, ysignUp);
    while (true)
    {
        if (_kbhit())
        {
            c = _getch();
            if (c == 'a') {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                if (x_check == (xsignUp) && y_check == (ysignUp)) {
                    continue;
                }
                else if (x_check == (xBack) && y_check == (yBack)) {
                    cout << "  ";
                    gotoXY(xsignUp, ysignUp);
                    cout << "->";
                    gotoXY(xsignUp, ysignUp);
                }
            }
            else if (c == 'd') {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                if (x_check == (xBack) && y_check == (yBack)) {
                    continue;
                }
                else if (x_check == (xsignUp) && y_check == (ysignUp)) {
                    cout << "  ";
                    gotoXY(xBack, yBack);
                    cout << "->";
                    gotoXY(xBack, yBack);
                }
            }
            else if (c == 13) {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                //====== Hàm if dùng check ô mà con trỏ hướng tới
                if (x_check == xsignUp && y_check == ysignUp) {
                    choose = 1;
                }
                else if (x_check == xBack && y_check == yBack) {
                    choose = 2;
                }
                //======= Hàm if trả về giá trị mà con trỏ hướng tới
                if (choose == 1) {
                    Sleep(20);
                    highScore* list = NULL;
                    addPlayerInfor(p, list);
                    system("cls");
                    gameMode(p);
                    //inputRowCol(row, col);
                    //system("cls");
                    //runningGame(row, col);
                    break;
                }
                else if (choose == 2) {
                    system("cls");
                    Sleep(20);
                    loginGame(p);
                    break;
                }
            }
        }
    }
}

//=================== Ham kiem tra thong tin nguoi choi =========
void checkPlayerInfor(Player p, highScore*& infor) {
    drawingTitle();
    int row = 0;
    int col = 0;
    ifstream readFile("Player_infor.txt");
    if (!readFile.is_open()) {
        cout << "Cannot open file";
    }
    else {
        int x_new = 70;
        int y_new = 22;
        int check = 0;
        Player temp;
        while (!readFile.eof()) {
            readFile >> temp.name >> temp.password;
            if (temp.name == p.name && temp.password == p.password) {
                check = 1;
                break;
            }
        }
        readFile.close();
        if (check == 1) {
            system("cls");
            Sleep(100);
            gotoXY(x_new, y_new);
            putchar(218);
            for (int i = 0; i < 10; i++)
                putchar(196);
            putchar(191);

            int i = 0;
            for (; i < 2; i++)
            {
                gotoXY(x_new, y_new + i + 1);
                putchar(179);
                gotoXY(x_new + 2, y_new + i + 1);
                cout << "Correct";
                gotoXY(x_new + 10 + 1, y_new + i + 1);
                putchar(179);
            }

            gotoXY(x_new, y_new + i);
            putchar(192);
            for (i = 0; i < 10; i++)
                putchar(196);
            putchar(217);
            Sleep(1000);
            system("cls");
            //inputRowCol(row, col);
            gameMode(p);
            //system("cls");
            //runningGame(row, col);
        }
        else {
            system("cls");
            gotoXY(x_new, y_new);
            putchar(218);
            for (int i = 0; i < 10; i++)
                putchar(196);
            putchar(191);

            int i = 0;
            for (; i < 2; i++)
            {
                gotoXY(x_new, y_new + i + 1);
                putchar(179);
                gotoXY(x_new + 2, y_new + i + 1);
                cout << "Wrong";
                gotoXY(x_new + 10 + 1, y_new + i + 1);
                putchar(179);
            }

            gotoXY(x_new, y_new + i);
            putchar(192);
            for (i = 0; i < 10; i++)
                putchar(196);
            putchar(217);
            Sleep(1000);
            system("cls");
            Sleep(20);
            loginGame(p);
        }
        Sleep(8000);
    }
}

//=================== Hàm đăng nhập =============================
void signIn(Player& p) {
    int row = 0;
    int col = 0;
    drawingTitle();
    char c = 205;
    SetColor(7);
    for (int i = 50; i <= 100; i++)
    {
        gotoXY(i, 20); cout << c;
        gotoXY(i, 31); cout << c;
    }
    gotoXY(52, 22);
    cout << "Please enter your name: ";
    int x_name = whereX();
    int y_name = whereY();
    gotoXY(52, 24);
    cout << "Please enter your password: ";
    int x_pass = whereX();
    int y_pass = whereY();
    //======================== Hàm in ra hộp Sign In =====================
    int x_new = 55;
    int y_new = 27;
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    int i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }
    gotoXY(x_new + 2, y_new + 1);
    cout << "Sign in";
    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);
    c = 186;
    for (int j = 21; j <= 30; j++)
    {
        gotoXY(50, j); cout << c;
    }
    for (int j = 21; j <= 30; j++)
    {
        gotoXY(100, j); cout << c;
    }
    int xsignUp = x_new - 2;
    int ysignUp = y_new + 1;
    gotoXY(xsignUp, ysignUp);
    cout << "->";
    //======================== Hàm in ra hộp Back =====================
    x_new = 83;
    y_new = 27;
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }
    gotoXY(x_new + 2, y_new + 1);
    cout << "  Back";
    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);
    c = 186;
    for (int j = 21; j <= 30; j++)
    {
        gotoXY(50, j); cout << c;
    }
    for (int j = 21; j <= 30; j++)
    {
        gotoXY(100, j); cout << c;
    }
    int xBack = x_new - 2;
    int yBack = y_new + 1;
    //============== Hàm lấy thông tin người chơi ====================
    gotoXY(x_name, y_name);
    getline(cin, p.name);
    gotoXY(x_pass, y_pass);
    getline(cin, p.password);
    //============== Hàm điều khiển con trỏ ==================
    int choose = 0;
    gotoXY(xsignUp, ysignUp);
    while (true)
    {
        if (_kbhit())
        {
            c = _getch();
            if (c == 'a') {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                if (x_check == (xsignUp) && y_check == (ysignUp)) {
                    continue;
                }
                else if (x_check == (xBack) && y_check == (yBack)) {
                    cout << "  ";
                    gotoXY(xsignUp, ysignUp);
                    cout << "->";
                    gotoXY(xsignUp, ysignUp);
                }
            }
            else if (c == 'd') {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                if (x_check == (xBack) && y_check == (yBack)) {
                    continue;
                }
                else if (x_check == (xsignUp) && y_check == (ysignUp)) {
                    cout << "  ";
                    gotoXY(xBack, yBack);
                    cout << "->";
                    gotoXY(xBack, yBack);
                }
            }
            else if (c == 13) {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                //====== Hàm if dùng check ô mà con trỏ hướng tới
                if (x_check == xsignUp && y_check == ysignUp) {
                    choose = 1;
                }
                else if (x_check == xBack && y_check == yBack) {
                    choose = 2;
                }
                //======= Hàm if trả về giá trị mà con trỏ hướng tới
                if (choose == 1) {
                    Sleep(20);
                    highScore* list = NULL;
                    checkPlayerInfor(p, list);
                    break;
                }
                else if (choose == 2) {
                    system("cls");
                    Sleep(20);
                    loginGame(p);
                    break;
                }
                else if (choose == 3)
                {
                    system("cls");
                    introGame(p);
                    break;
                }
            }
        }
    }
    system("cls");
}

//=========================== Game mode ====================================
void gameMode(Player& p) {
    drawingTitle();
    int x_new = 70;
    int y_new = 20;

    //============= The Selection Box 1 =============
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    int i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 4, y_new + i + 1);
        cout << "Easy";
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }

    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);

    int x1 = x_new - 2;
    int y1 = y_new + 1;
    gotoXY(x1, y1);
    cout << "->";
    y_new += 4;

    //============= The Selection Box 2 ==============
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 3, y_new + i + 1);
        cout << "Medium";
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }

    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);

    int x2 = x_new - 2;
    int y2 = y_new + 1;

    y_new += 4;

    //============= The Selection Box 3 ==============
    gotoXY(x_new, y_new);
    putchar(218);
    for (int i = 0; i < 10; i++)
        putchar(196);
    putchar(191);

    i = 0;
    for (; i < 2; i++)
    {
        gotoXY(x_new, y_new + i + 1);
        putchar(179);
        gotoXY(x_new + 4, y_new + i + 1);
        cout << "Hard";
        gotoXY(x_new + 10 + 1, y_new + i + 1);
        putchar(179);
    }

    gotoXY(x_new, y_new + i);
    putchar(192);
    for (i = 0; i < 10; i++)
        putchar(196);
    putchar(217);
    int x3 = x_new - 2;
    int y3 = y_new + 1;
    int choose = 0;
    int k = 0;
    int x_phao = 68;
    char c;
    gotoXY(x1, y1);
    while (true)
    {
        if (_kbhit())
        {
            c = _getch();
            if (c == 'w') {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                if (x_check == (x1) && y_check == (y1)) {
                    continue;
                }
                else if (x_check == (x2) && y_check == (y2)) {
                    cout << "  ";
                    gotoXY(x1, y1);
                    cout << "->";
                    gotoXY(x1, y1);
                }
                else if (x_check == (x3) && y_check == (y3)) {
                    cout << "  ";
                    gotoXY(x2, y2);;
                    cout << "->";
                    gotoXY(x2, y2);
                }
            }
            else if (c == 's') {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                if (x_check == (x3) && y_check == (y3)) {
                    continue;
                }
                else if (x_check == (x1) && y_check == (y1)) {
                    cout << "  ";
                    gotoXY(x2, y2);
                    cout << "->";
                    gotoXY(x2, y2);
                }
                else if (x_check == (x2) && y_check == (y2)) {
                    cout << "  ";
                    gotoXY(x3, y3);;
                    cout << "->";
                    gotoXY(x3, y3);
                }
            }
            else if (c == 13) {
                PlaySound(TEXT("minecraft-click-cropped.wav"), NULL, SND_FILENAME | SND_ASYNC);
                int x_check = whereX();
                int y_check = whereY();
                //====== Hàm if dùng check ô mà con trỏ hướng tới
                if (x_check == x1 && y_check == y1) {
                    choose = 1;
                }
                else if (x_check == x2 && y_check == y2) {
                    choose = 2;
                }
                else if (x_check == x3 && y_check == y3) {
                    choose = 3;
                }
                //======= Hàm if trả về giá trị mà con trỏ hướng tới
                if (choose == 1) {
                    system("cls");
                    Sleep(20);
                    runningGame(6, 4);
                    break;
                }
                else if (choose == 2) {
                    system("cls");
                    Sleep(20);
                    runningGame(8, 5);
                    break;
                }
                else if (choose == 3)
                {
                    system("cls");
                    Sleep(20);
                    runningGame(8, 8);
                    break;
                }
            }
        }
    }
}
