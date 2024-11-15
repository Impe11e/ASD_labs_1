#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

int main() {
    int columns, rows;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hout, &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    COORD Pos;
    Pos.X = columns - 1;
    Pos.Y = rows - 1;
    int cycles = (columns < rows ? columns : rows) / 2;
    int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
    int delay = 1000;
    for (int p = 0; p < cycles; p++) {
        //вліво
        for (int x = right; x >= left; x--) {
            Pos.X = x;
            Pos.Y = bottom;
            SetConsoleCursorPosition(hout, Pos);
            printf("/");
            usleep(delay);
        }

        bottom--;

        //вгору
        for (int y = bottom; y >= top; y--) {
            Pos.X = left;
            Pos.Y = y;
            SetConsoleCursorPosition(hout, Pos);
            printf("/");
            usleep(delay);
        }

        left++;

        //вправр
        for (int x = left; x <= right ; x++) {
            Pos.X = x;
            Pos.Y = top;
            SetConsoleCursorPosition(hout, Pos);
            printf("/");
            usleep(delay);
        }

        top++;

        //вниз
        for (int y = top; y <= bottom; y++) {
            Pos.X = right;
            Pos.Y = y;
            SetConsoleCursorPosition(hout, Pos);
            printf("/");
            usleep(delay);
        }

        right--;

    }
    COORD Pos2;
    Pos2.X = left;
    Pos2.Y = rows;
    SetConsoleCursorPosition(hout, Pos2);

    return 0;
}
