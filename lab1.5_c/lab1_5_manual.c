// Задано матрицю дійсних чисел A[m,n]. У кожному рядку матриці визначити присутність
// заданого дійсного числа X і його місцезнаходження (координати).
#include <stdio.h>
#include <math.h>

#define ROWS 7
#define COLUMNS 8

int main() {

    int input;
    int found = 0;

    int matrix[ROWS][COLUMNS] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 6, 1, -8, 0, 6 ,11, 4},
        {9, 6, 11, -9, 7, 3, 5, 4},
        {0, 8, 3, 7, 1, -9, -3, 6},
        {7, 2, 4, 6, 1, 9, 0, 3},
        {3, 5, 6, 9, 1, 4, 2, 8},
        {8, 4, 7, 2, 5, 9, 1, 6},
    };

    printf("The matrix has the form:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%4d ", matrix[i][j]);
            }
        printf("\n");
    }

        printf("Enter the number you are looking for: ");
    scanf("%d", &input);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (matrix[i][j] == input) {
                printf("Found number '%d' on the poistion [%d][%d]\n", input, i, j);
                found = 1;
            }
        }

    }
    if (!found) {
        printf("Number '%d' not found in the matrix.\n", input);
        return -1;
    }

    return 0;

}
