#include <iostream>
#include <iomanip> // setw(), 
#include "Win10.h"
#include<time.h>
using namespace std;

/*
  cout << "+---+---+---+";
  cout << "|   |   |   |";
  cout << "+---+---+---+";
  cout << "|   |   |   |";
  cout << "+---+---+---+";
  cout << "|   |   |   |";
  cout << "+---+---+---+";
*/
// Глобальная область
// Глобальные переменные
// коорд. меню на экране
int menuRow = 4, menuCol = 6;
// Цвета активного пункта меню
int colSelectFon = _COLOR::GREEN;
int colSelectSym = _COLOR::WHITE;
// Цвета неактивного пунктов меню
int colUnselFon = BLACK; // _COLOR::BLUE
int colUnselSym = LIGHT_YELLOW; // _COLOR::LIGHT_YELLOW
// Индекс активного пункта меню
int Select = 0; // Active

// Сетка игры, игра
int gridRow = 5;
int gridCol = 8;
//кто выйграл Х или О
int Win = 0;
int scoreX = 0;
int scoreO = 0;
int scoreDraw = 0;
// Функция игры
void StartGame() {
    system("cls"); // очистить экран cls - Clear Screen
    // прорисовка сетки XO
    SetPos(gridRow, gridCol);     cout << "+---+---+---+";
    SetPos(gridRow + 1, gridCol); cout << "|   |   |   |";
    SetPos(gridRow + 2, gridCol); cout << "+---+---+---+";
    SetPos(gridRow + 3, gridCol); cout << "|   |   |   |";
    SetPos(gridRow + 4, gridCol); cout << "+---+---+---+";
    SetPos(gridRow + 5, gridCol); cout << "|   |   |   |";
    SetPos(gridRow + 6, gridCol); cout << "+---+---+---+";
    CursorHide(1, 30); // показать курсор консоли, 100%

    // Стартовая позиция курсора
    int curRow = gridRow + 1;
    int curCol = gridCol + 2;
    // внутрение индексы ячеек сетки игры
    int row = 0, col = 0;
    // Двумерный массив 3 на 3 элемента
    int Cell[3][3];
    // поэлементная очистка двумерного массива
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Cell[i][j] = 0;
        }
    }
    // первыми ходят X
    //  true - ходят X
    //  false - ходят O
    bool isStepX = true;
    // сигнал об окончании игры
    bool isGameOver = false;
    // Цикл игры
    clock_t startGame = clock();
    while (!isGameOver) { // while(isGameOver == false)
        SetPos(curRow, curCol);
        system("color 0e");
        //
        int key = _getch();
        switch (key)
        {
        case _KEY::UP: case 'w': case 'W': // вверх
            if (row > 0) { row--; curRow -= 2; }
            break;

        case _KEY::DOWN: case 's': case 'S': // вниз
            if (row < 2) { row++; curRow += 2; }
            break;

        case _KEY::LEFT: case 'a': case 'A': // влево
            if (col > 0) { col--; curCol -= 4; }
            break;

        case _KEY::RIGHT: case 'd': case 'D': // вправо
            if (col < 2) { col++; curCol += 4; }
            break;

        case _KEY::ENTER: case 'z': case 'Z':
            if (Cell[row][col] == 0) {
                // ячейка свободна
                if (isStepX) {
                    cout << 'X';
                    Cell[row][col] = 1; // 1 - для X
                    isStepX = false;
                }
                else {
                    cout << 'O';
                    Cell[row][col] = 2; // 2 - для O
                    isStepX = true;
                }
                //isStepX = !isStepX; // передача хода
            }
            //горизонталь
            if (Cell[0][0] == Cell[0][1] && Cell[0][0] == Cell[0][2]) { Win = Cell[0][0]; }
            else if (Cell[1][0] == Cell[1][1] && Cell[1][0] == Cell[1][2]) { Win = Cell[1][0]; }
            else if (Cell[2][0] == Cell[2][1] && Cell[2][0] == Cell[2][2]) { Win = Cell[2][0]; }
            //вертикаль
            else if (Cell[0][0] == Cell[1][0] && Cell[0][0] == Cell[2][0]) { Win = Cell[0][0]; }
            else if (Cell[0][1] == Cell[1][1] && Cell[0][1] == Cell[2][1]) { Win = Cell[0][1]; }
            else if (Cell[0][2] == Cell[1][2] && Cell[0][2] == Cell[2][2]) { Win = Cell[0][2]; }
            //диагональ
            else if (Cell[0][0] == Cell[1][1] && Cell[0][0] == Cell[2][2]) { Win = Cell[0][0]; }
            else if (Cell[2][0] == Cell[1][1] && Cell[2][0] == Cell[0][2]) { Win = Cell[2][0]; }
            else if ((Cell[0][0] && Cell[0][1] && Cell[0][2]) && (Cell[1][0] && Cell[1][1] && Cell[1][2]) && (Cell[2][0] && Cell[2][1] && Cell[2][2])) { Win = 3; }
            if (Win) {

                SetPos(gridRow + 8, gridCol);
                switch (Win) {
                case 1:CursorHide();
                    system("color 01"); cout << "К                   \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 02"); cout << "Кр                  \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 03"); cout << "Кре                 \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 04"); cout << "Крес                \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 05"); cout << "Крест               \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 06"); cout << "Крести              \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 07"); cout << "Крестик             \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 08"); cout << "Крестики            \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 09"); cout << "Крестики            \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0a"); cout << "Крестики В          \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0b"); cout << "Крестики Вы         \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0c"); cout << "Крестики Вый        \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0d"); cout << "Крестики Выйг       \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0f"); cout << "Крестики Выйгр      \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 01"); cout << "Крестики Выйгра     \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 02"); cout << "Крестики Выйграл    \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 03"); cout << "Крестики Выйграли   \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 04"); cout << "Крестики Выйграли!  \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 05"); cout << "Крестики Выйграли!! \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 06"); cout << "Крестики Выйграли!!!\r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0e");
                    scoreX += 1; break;
                case 2:CursorHide();
                    system("color 01"); cout << "Н                 \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 02"); cout << "Но                \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 03"); cout << "Нол               \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 04"); cout << "Ноли              \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 05"); cout << "Нолик             \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 06"); cout << "Нолики            \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 07"); cout << "Нолики            \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 08"); cout << "Нолики В          \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 09"); cout << "Нолики Вы         \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0a"); cout << "Нолики Вый        \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0b"); cout << "Нолики Выйг       \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0c"); cout << "Нолики Выйгр      \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0d"); cout << "Нолики Выйгра     \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0f"); cout << "Нолики Выйграл    \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 01"); cout << "Нолики Выйграли   \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 02"); cout << "Нолики Выйграли!  \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 03"); cout << "Нолики Выйграли!! \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 04"); cout << "Нолики Выйграли!!!\r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0e");
                    scoreO += 1; break;
                case 3:CursorHide();
                    system("color 01"); cout << "Н       \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 02"); cout << "Ни      \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 03"); cout << "Нич     \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 04"); cout << "Ничь    \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 05"); cout << "Ничья   \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 06"); cout << "Ничья!  \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0b"); cout << "Ничья!! \r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0c"); cout << "Ничья!!!\r"; Sleep(30); SetPos(gridRow + 8, gridCol);
                    system("color 0e");
                    scoreDraw += 1; break;
                }
                SetPos(gridRow + 10, gridCol); cout << "Количество побед Х - " << scoreX;
                SetPos(gridRow + 11, gridCol); cout << "Количество побед O - " << scoreO;
                SetPos(gridRow + 12, gridCol); cout << "Количество ничьи   - " << scoreDraw;
                SetPos(gridRow + 13, gridCol); cout << "Нажмите Enter..." << endl;
                CursorHide(1, 30);
                while (_getch() != ENTER);
                return;



            }


            break;


        case _KEY::ESC: // выход из текущей игры
            isGameOver = true;
            break;
        }
    }


}


int main() {
    setlocale(LC_ALL, "Rus");

    // сигнал для выхода из меню
    bool isExit = false;

    // бесконечный цикл меню игры
    for (;;)
    {
        system("cls");
        CursorHide(); // скрыть курсор консоли
        // 0 - "Начать игру";
        if (Select == 0) { SetColor(colSelectFon, colSelectSym); }
        else { SetColor(colUnselFon, colUnselSym); }
        SetPos(menuRow, menuCol);
        cout << "Начать игру";

        // 1 - "Статистика игры";
        if (Select == 1) { SetColor(colSelectFon, colSelectSym); }
        else { SetColor(colUnselFon, colUnselSym); }
        SetPos(menuRow + 1, menuCol);
        cout << "Статистика игры";
        // 2 - "Об авторах";
        if (Select == 2) { SetColor(colSelectFon, colSelectSym); }
        else { SetColor(colUnselFon, colUnselSym); }
        SetPos(menuRow + 2, menuCol);
        cout << "Об авторах";
        // 3 - "Выход";
        if (Select == 3) { SetColor(colSelectFon, colSelectSym); }
        else { SetColor(colUnselFon, colUnselSym); }
        SetPos(menuRow + 3, menuCol);
        cout << "Выход";

        // Восстановление цвета консоли по умолчанию
        SetColor(BLACK, WHITE);

        // обработка нажатий клавиш
        //if ( _kbhit() ) // проверить - нажата ли какая-либо клавиша
        {
            // получить код нажатой клавиши
            int key = _getch(); // _getche()
            // расшифровка кода нажатой кнопки
            switch (key) {
            case _KEY::UP: // вверх
            case _KEY::LEFT:
                if (Select > 0) { Select--; }
                else { Select = 3; }
                break;

            case _KEY::DOWN: // вниз
            case _KEY::RIGHT:
                if (Select < 3) { Select++; }
                else { Select = 0; }
                break;

            case _KEY::ENTER:
                // выбор пункта меню
                //SetPos(menuRow + 5, menuCol);
                //cout << "Выбран " << Select << " пункт";
                // расшифровка Select
                switch (Select) {
                case 0: // "Начать игру"
                    StartGame(); // ф-ция игры XO
                    system("cls"); // очистить экран
                    break;
                case 1: // "Статистика игры"
                    system("cls");
                    system("color 0e");
                    SetPos(menuRow, menuCol);
                    cout << " Количество побед X > " << scoreX << endl;
                    SetPos(menuRow + 1, menuCol);
                    cout << " Количество побед O > " << scoreO << endl;
                    SetPos(menuRow + 2, menuCol);
                    cout << " Количество ничьи   > " << scoreDraw << endl;
                    while (_getch() != ENTER);
                    break;
                case 2: // "Об авторе"
                    system("cls");
                    system("color 0e");
                    SetPos(menuRow, menuCol);
                    cout << "By Богенбай" << endl;
                    SetPos(menuRow + 1, menuCol);
                    cout << "Centr Corporation" << endl;

                    while (_getch() != ENTER);
                    break;
                case 3: // "Выход"
                    isExit = true; // сигнал о выходе из меню
                    break;
                }
                break;

            case _KEY::ESC:// выход
                system("cls");
                SetPos(menuRow, menuCol);
                cout << "Вы дейстивтельно хотите выйти из игры???" << endl;
                while (_getch() != ENTER);
                break;
            } // switch(key)
        } // if(_kbhit())
        // проверка на сигнал о выходе из меню
        if (isExit) { break; } // выход из цикла
                               // завершение работы
                               // главного меню
    } // for(;;)
    system("cls");
    system("color 0e");
    SetPos(menuRow, menuCol);
    cout << "До свидания!!!";
    cin.get();

} // main()