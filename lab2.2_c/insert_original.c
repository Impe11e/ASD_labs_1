#include <stdlib.h>
#include <stdio.h>

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
    int rows = 7; 
    int cols = 10;
    int first_row = 0;

    int matrix[7][10] = {
    {-3, 7, 10, -4, 6, 2, 15, -5, 1, 13},
    {1, 10, 56, -4, 0, -1, 56, 14, 3, 9},
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
    {2, 7, -3, 14, -5, -16, 17, 8, 1, 3},
    {-5, 2, -34, 1, 1, 5, -8, 13, 1, 11},
    {0, 9, 3, 6, 2, 3, 1, 0, 8, 6},
    {10, 5, -3, 7, 1, 10, -1, -8, 9, 3}
    };

    print_matrix(rows, cols, matrix);

    for (int i = 1; i < cols; i++) {
        int temp = matrix[first_row][i];
        int j = 0;
        while (j < cols && matrix[first_row][j] < temp) {
            j += 1;
        }
        for (int k = i; k > 0 && matrix[first_row][k-1] > temp; k--) {
        matrix[first_row][k] = matrix[first_row][k - 1];
        }

        matrix[first_row][j] = temp;
    }

    print_matrix(rows, cols, matrix);

    return 0;
}
