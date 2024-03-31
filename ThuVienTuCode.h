#pragma once
#include "ThuVien.h"
//Thư viện mà nhóm em tự code: 
void inputRowCol(int& row, int& col);
void runningGame(int &row, int &col);

//=================== Hàm vẽ tiêu đề game ===================
void drawingTitle() {
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
}

//========Hàm tạo hộp =======
void playingBox(char**& box, int col, int row) {
    int n = row;
    int m = col;
    int colChar = (m - 1) / 8;
    int rowChar = (n - 1) / 4;
    int iChar = 0;
    int randRow = 0;
    int randCol = 0;
    int size = colChar * rowChar;
    char* temparray = new char[size];
    box = new char* [n];
    for (int i = 0; i < n; i++) {
        box[i] = new char[m];
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
    /*Dòng code này dùng để tạo ra bảng và đồng thời gán chữ vào mỗi ô trong bảng */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i % 4 == 0) && (j % 8 != 0)) {
                box[i][j] = '-';
            }
            else if ((j % 8 == 0) && (i % 4 != 0)) {
                box[i][j] = '|';
            }
            else if ((i % 2 == 0) && (j % 4 == 0) && (i % 4 != 0) && (j % 8 != 0)) {
                box[i][j] = temparray[iChar];
                iChar++;
            }
            else 
                box[i][j] = ' ';
        }
    }
    delete[] temparray;
}
//======= Hàm giải phóng hộp =================
void freeBox(char** box, int row) {
    for (int i = 0; i < row; i++) {
        delete[] box[i];
    }
    delete[] box;
}
//=======Hàm xuất hộp ra màn hình ========
void coutBox(char**& box, int col, int row) {
    int n = row;
    int m = col;
    int x = 30;
    int y = 5;
    for (int i = 0; i < n; i++) {
        gotoXY(x, y);
        for (int j = 0; j < m; j++) {
            cout << box[i][j];
        }
        y++;
        //cout << endl;
    }
    y = 5;
}
//=========Hàm vẽ ra ô trắng===========
void drawBox(char**& box, int index, int jdex) {
    for (int i = index; i < index + 3; i++) {
        for (int j = jdex; j < jdex + 7; j++) {
            if (isalpha(box[i][j])) {
                continue;
            }
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
}/*
//=========Hàm xóa ô trong hộp theo I Matching ======
void deleteBoxIMatchinglineX(char**& box, int index, int jdex, int tempindex, int tempjdex, int col, int row) {
    int minindex = min(index, tempindex);
    int maxindex = max(index, tempindex);
    int minjdex = min(jdex, tempjdex);
    int maxjdex = max(jdex, tempjdex);
//=========== Check Left Up Board ==================
    if (minindex == 1 && minjdex == 1) {
        for (int i = minindex - 1; i < maxindex + 4; i++) {
            for (int j = minjdex - 1; j < maxjdex + 7; j++) {
                box[i][j] = ' ';
            }
        }
        return;
    }
//============ Check Right Up Board ==================
    if (minindex == 1 && minjdex == col) {
        for (int i = minindex - 1; i < maxindex + 4; i++) {
            for (int j = minjdex; j < maxjdex + 8; j++) {
                box[i][j] = ' ';
            }
        }
        return;
    }
//============= Check Up Board ====================
    if (minindex == 1 && minindex != 1 && minjdex != 1) {
        for (int i = minindex - 1; i < maxindex + 4; i++) {
            for (int j = minjdex; j < maxjdex + 7; j++) {
                box[i][j] = ' ';
            }
        }
        return;
    }
//============== Check Left Down Board =================
    if (minindex == row && minjdex == 1) {
        for (int i = minindex; i < maxindex + 5; i++) {
            for (int j = minjdex - 1; j < maxjdex + 7; j++) {
                box[i][j] = ' ';
            }
        }
        return;
    }
//============= Check Right Down Board =================
    if (minindex == row && minjdex == col) {
        for (int i = minindex; i < maxindex + 5; i++) {
            for (int j = minjdex; j < maxjdex + 8; j++) {
                box[i][j] = ' ';
            }
        }
        return;
    }
//================== Check Down Board ======================
}*/
/*void selectBox(char** box, int& index, int& jdex, int row, int col, int x, int y, int key) {
    if (key == 13) {

    }
}*/

//=========Hàm xóa ô trong hộp======
void deleteBox(char**& box, int index, int jdex) {
    for (int i = index - 1; i < index + 4; i++) {
        for (int j = jdex - 1; j < jdex + 8; j++) {
            box[i][j] = ' ';
        }
    }
}

//================ Hàm kiểm tra I Matching ===========================
bool checklineX(char** box, int index, int jdex, int tempjdex) {
    int jdexChar = jdex + 3;
    int indexChar = index + 1;
    int tempjdexChar = tempjdex + 3;
    int minlinex = min(jdexChar, tempjdexChar);
    int maxlinex = max(jdexChar, tempjdexChar);
    if (minlinex == (maxlinex - 8)) {
        return true;
    }
    for (int i = minlinex + 8; i <= maxlinex-8; i+=8) {
        if (isalpha(box[indexChar][i])) {
            return false;
        }
    }
    return true;
}
bool checklineY(char** box, int index, int jdex, int tempindex) {
    int jdexChar = jdex + 3;
    int indexChar = index + 1;
    int tempindexChar = tempindex + 1;
    int minliney = min(indexChar, tempindexChar);
    int maxliney = max(indexChar, tempindexChar);
    if (minliney == (maxliney - 4)) {
        return true;
    }
    for (int i = minliney; i <= maxliney-4; i+=4) {
        if (isalpha(box[i][jdexChar])) {
            return false;
        }
    }
    return true;
}
//================= Hàm kiểm tra Z Matching ================
int checkRectX(char** box, int index, int jdex, int tempindex, int tempjdex) {
    int jdexChar = jdex;
    int indexChar = index;
    int tempindexChar = tempindex;
    int tempjdexChar = tempjdex;
    int minjdex = min(jdexChar, tempjdexChar);
    int maxjdex = max(jdexChar, tempjdexChar);
    int minindex = min(indexChar, tempindexChar);
    int maxindex = max(indexChar, tempindexChar);
    for (int i = minjdex; i <= maxjdex; i += 8) {
        if (checklineX(box, minindex, minjdex, i)
            && checklineY(box, minindex, i, maxindex)
            && checklineX(box, maxindex, i, maxjdex)) {
            return i;
        }
    }
    return -1;
}
int checkRectY(char** box, int index, int jdex, int tempindex, int tempjdex) {
    int jdexChar = jdex;
    int indexChar = index;
    int tempindexChar = tempindex;
    int tempjdexChar = tempjdex;
    int minjdex = min(jdexChar, tempjdexChar);
    int maxjdex = max(jdexChar, tempjdexChar);
    int minindex = min(indexChar, tempindexChar);
    int maxindex = max(indexChar, tempindexChar);
    for (int i = minindex; i <= maxindex; i+=4) {
        if (checklineY(box, minindex, minjdex, i)
            && checklineX(box, i, minjdex, maxjdex)
            && checklineY(box, maxindex, maxjdex, i)) {
            return i;
        }
    }
    return -1;
}
//================= Hàm kiểm tra U Matching ================
int checkMoreLineX(char** box, int index, int jdex, int tempindex, int tempjdex, int type, int col) {
    int minindex = min(index, tempindex);
    int maxindex = max(index, tempindex);
    int minjdex = min(jdex, tempjdex);
    int maxjdex = max(jdex, tempjdex);
    // find line and y begin
    int y = col + 8;
    if (type == -8) {
        y = -7;
    }
    // check more
    if (checklineX(box, index, jdex, y)) {
        if (checklineX(box, tempindex, tempjdex, y)) {
            return y;
        }
    }
    return -1;
}
int checkMoreLineY(char** box, int index, int jdex, int tempindex, int tempjdex, int type, int row) {
    int minindex = min(index, tempindex);
    int maxindex = max(index, tempindex);
    int minjdex = min(jdex, tempjdex);
    int maxjdex = max(jdex, tempjdex);
    // find line and y begin
    int x = row + 4;
    int rowMin = minindex;
    int rowMax = maxindex;
    if (type == -4) {
        x = -3;
    }
    // check more
    if (checklineY(box, index, jdex, x)) {
        if (checklineY(box, tempindex, tempjdex, x)) {
            return x;
        }
    }
    return -1;
}
//============ Hàm check ô trùng nhau ====================
void sameBox(char** box, int index, int jdex, int tempindex, int tempjdex, int &check, int col, int row) {
    //Check line with x
    if (index == tempindex) {
        if (checklineX(box, index, jdex, tempjdex)) {
            check = 0;
            deleteBox(box, index, jdex);
            deleteBox(box, tempindex, tempjdex);
            undrawBox(box, index, jdex);
            return;
        }
    }
    //Check line with y
    if (jdex == tempjdex) {
        if (checklineY(box, index, jdex, tempindex)) {
            check = 0;
            deleteBox(box, index, jdex);
            deleteBox(box, tempindex, tempjdex);
            undrawBox(box, index, jdex);
            return;
        }
    }

    int t = -1;

    //Check in rectangle with x
    if (t = checkRectX(box, index, jdex, tempindex, tempjdex) != -1) {
        check = 0;
        deleteBox(box, index, jdex);
        deleteBox(box, tempindex, tempjdex);
        undrawBox(box, index, jdex);
        return;
    }

    //Check in rectangle with y
    if (t = checkRectY(box, index, jdex, tempindex, tempjdex) != -1) {
        check = 0;
        deleteBox(box, index, jdex);
        deleteBox(box, tempindex, tempjdex);
        undrawBox(box, index, jdex);
        return;
    }

    //Check more right
    if (t = checkMoreLineX(box, index, jdex, tempindex, tempjdex, 8, col - 8) != -1) {
        check = 0;
        deleteBox(box, index, jdex);
        deleteBox(box, tempindex, tempjdex);
        undrawBox(box, index, jdex);
        return;
    }
    
    //Check more left
    if (t = checkMoreLineX(box, index, jdex, tempindex, tempjdex, -8, col - 8) != -1) {
        check = 0;
        deleteBox(box, index, jdex);
        deleteBox(box, tempindex, tempjdex);
        undrawBox(box, index, jdex);
        return;
    }

    //Check more down
    if (t = checkMoreLineY(box, index, jdex, tempindex, tempjdex, 4, row - 4) != -1) {
        check = 0;
        deleteBox(box, index, jdex);
        deleteBox(box, tempindex, tempjdex);
        undrawBox(box, index, jdex);
        return;
    }

    //Check more up
    if (t = checkMoreLineY(box, index, jdex, tempindex, tempjdex, -4, row - 4) != -1) {
        check = 0;
        deleteBox(box, index, jdex);
        deleteBox(box, tempindex, tempjdex);
        undrawBox(box, index, jdex);
        return;
    }
    undrawBox(box, tempindex, tempjdex);
    undrawBox(box, index, jdex);
    check = 0;
}
//========Hàm di chuyển ô trắng sang vị trí khác trong hộp=======
void movingBox(char**& box, int index, int jdex, int row, int col, int x, int y) {
    int check = 0;
    char checkChar = ' ';
    int tempindex = 0;
    int tempjdex = 0;
    while (true)
    {
        if (_kbhit()) {
            int key = _getch();
            //Nếu người dùng nhập vào bàn phím các nút w,a,s,d thì sẽ di chuyển sang ô khác
            switch (key) {
            case 13:
                if (check == 1) {
                    if ((checkChar == box[index + 1][jdex + 3]) 
                        && (!((tempindex == index) && (tempjdex == jdex)))) {
                        sameBox(box, index, jdex, tempindex, tempjdex, check, col, row);
                    }
                    else {
                        undrawBox(box, tempindex, tempjdex);
                        undrawBox(box, index, jdex);
                        check = 0;
                    }
                }
                else {
                    check = 1;
                    tempindex = index;
                    tempjdex = jdex;
                    checkChar = box[tempindex + 1][tempjdex + 3];
                    break;
                }
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
//=================== Hàm yêu cầu nhập số dòng và số cột ========================
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
//=================== Hàm chạy game ================
void runningGame(int &row, int &col) {
    int index = 1;
    int jdex = 1;
    int x, y;
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
