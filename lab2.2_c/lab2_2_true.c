#include <stdlib.h>
#include <stdio.h>

void print_matrix(int rows, int columns, int matrix[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 7; 
    int cols = 10;
    int first_row = 0;

    int matrix[7][10] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
    {-3, 7, 10, -4, 6, 2, 15, -5, 1, 13},
    {2, 7, -3, 14, -5, -16, 17, 8, 1, -10},
    {0, 9, 3, 3, 3, 2, 1, 0, 8, 6},
    {-5, 2, -34, 1, 1, 5, -8, 13, 1, -4},
    {10, 5, -3, 7, 1, 10, -1, -8, 9, 7}
    };

    printf("The matrix has the form:\n");
    print_matrix(rows, cols, matrix);

    for (int i = 3; i < cols; i += 2) {
        int temp = matrix[first_row][i];
        int j = 1;
        while (j < cols && matrix[first_row][j] < temp) {
            j += 2;
        }
        for (int k = i; k > 0 && matrix[first_row][k - 2] > temp; k -= 2) {
        matrix[first_row][k] = matrix[first_row][k - 2];
        }

        matrix[first_row][j] = temp;
    }

    printf("Sorted matrix has the form:\n");
    print_matrix(rows, cols, matrix);

    return 0;
}
