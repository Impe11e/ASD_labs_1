// Задано матрицю дійсних чисел A[m,n]. У кожному рядку матриці визначити присутність
// заданого дійсного числа X і його місцезнаходження (координати).
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int rows, int columns, int matrix[rows][columns]) {
    printf("The matrix has the form:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int rows, columns, input;
    int x, y, element;
    char answer;
    int found = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);

    int matrix[rows][columns];

    //заповнення матриці рандомними числами
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = rand() % 21; //рандомні числа до 20
        }
    }

    // вивід матриці
    print_matrix(rows, columns, matrix);

    printf("Do you want to change some elements? (Y/N): ");
    scanf(" %c", &answer);

    if (answer == 'Y') {
        while (1) {
            printf("What element do you want to change? Write in form 'x y element': ");
            scanf("%d %d %d", &x, &y, &element);

            if (x == -1 && y == -1 && element == -1) {
                break; 
            }

            if (x < 0 || x >= rows || y < 0 || y >= columns) {
                printf("Invalid coordinates! Please enter valid coordinates.\n");
                continue;
            }

            matrix[x][y] = element;
            printf("Matrix element [%d][%d] updated to %d\n", x, y, element);
            print_matrix(rows, columns, matrix);

        }
    }

        printf("Enter the number you are looking for: ");
    scanf("%d", &input);

    // пошук заданого елемента в кожному рядку
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] == input) {
                printf("Found number '%d' on the poistion [%d][%d]\n", input, i, j);
                found = 1;
                break; //знаходимо тільки перше входження, бо це лінійний пошук
            }
        }
    }   
    if (!found) {
        printf("Number '%d' not found in the matrix.\n", input);
        return -1;
    }

    return 0;

}