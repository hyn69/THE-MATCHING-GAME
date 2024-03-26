#pragma once
#include "ThuVien.h"
//Thư viện mà nhóm em tự code: 






void runningGame();

//========Hàm tạo hộp =======
void playingBox(char**& box, int col, int row) {
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
void coutBox(char**& box, int col, int row) {
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
void drawBox(char**& box, int index, int jdex) {
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
void movingBox(char**& box, int index, int jdex, int row, int col, int x, int y) {
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
                    if (checkChar == box[index + 1][jdex + 3]) {
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
                checkChar = box[tempindex + 1][tempjdex + 3];
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
void loadingScreen() {
    maxsc();
    system("COLOR 0e");
    system("cls");
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
        Sleep(20);
    }
    system("cls");
}
void introGame() {
    int x = 30;
    int y = 0;
    //============= The Begining Line ============
    SetColor(6);
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
        if (_kbhit() == true)
        {
            c = _getch();
            if (c == 'w') {
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
                    runningGame();
                    break;
                }
                else if (choose == 2) {
                    system("cls");
                    SetColor(15);
                    cout << "\n\n\nCreator: Pham Huy Thien Phuc\n";
                    cout << "\nDate: 24/01/2022\n";
                    SetColor(8);
                    cout << " \n\n\t\t==========================  Story  ==========================\n\n";
                    cout << "\t\t\t\tYou are a mother snake in the small garden.\n\t\t\t\tYour son is a strong snake who can puff fire.\n";
                    cout << "\t\t\t\tThe main mission of this game is to make the villagers around you happy.\n\t\t\t\tNow, it have just completed round 1.\n\n";
                    cout << "\t\t\t\t\t\t\t\t\tEnjoy the game,\n";
                    cout << "\t\t\t\t\t\t\t\t\tPham Huy Thien Phuc.\n";
                    Sleep(8500);
                    system("cls");
                    break;
                }
                else if (choose == 3)
                {
                    system("cls");
                    Sleep(8000);
                    break;
                }
            }
        }
    }
}
//=================== Hàm chạy game ================
void runningGame() {
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
    movingBox(box, index, jdex, row, col, x, y);
}