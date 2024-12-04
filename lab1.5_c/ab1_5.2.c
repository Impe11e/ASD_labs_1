#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для вывода матрицы
void print_matrix(int rows, int columns, int matrix[rows][columns]) {
    printf("The matrix has the form:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d ", matrix[i][j]); // %4d для целых чисел
        }
        printf("\n");
    }
}

int main() {
    int rows;
    int columns;
    int input;
    int found = 0;
    int x, y, element;
    char answer;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);

    int matrix[rows][columns];

    // Заполнение матрицы случайными числами
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = rand() % 21; // Случайные числа от 0 до 20
        }
    }

    // Вывод матрицы
    print_matrix(rows, columns, matrix);

    printf("Do you want to change some elements? (Y/N): ");
    scanf(" %c", &answer);

    if (answer == 'Y') {
        while (1) {
            printf("What element do you want to change? Write in form: [x y element]: ");
            scanf("%d %d %d", &x, &y, &element);
            if (x < 0 || x >= rows || y < 0 || y >= columns) {
                printf("Invalid coordinates! Please enter valid coordinates.\n");
                continue;
            }

            if (element == -1) {
                break; 
            }
            matrix[x][y] = element;
            printf("Matrix element [%d][%d] updated to %d\n", x, y, element);
            print_matrix(rows, columns, matrix); // Вывод матрицы после изменения
        }
    }

    printf("Enter the number you are looking for: ");
    scanf("%d", &input);

    // Поиск заданного элемента в каждом ряду
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] == input) {
                printf("Found number '%d' on the position [%d][%d]\n", input, i, j);
                found = 1;
                break; // Выход из внутреннего цикла при нахождении
            }
        }
    }   

    if (!found) {
        printf("Number '%d' not found in the matrix.\n", input);
        return -1;
    }

    return 0;
}
