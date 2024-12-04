#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int rows, int columns, float matrix[rows][columns]) {
    printf("The matrix has the form:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, columns;
    float input, element;
    int x, y;
    char answer;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);

    float matrix[rows][columns];

    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
             matrix[i][j] = (float)(rand() % 2001) / 100 - 10.0;; 
        }
    }

    print_matrix(rows, columns, matrix);

    printf("Do you want to change some elements? (Y/N): ");
    scanf(" %c", &answer);

    if (answer == 'Y') {
        while (1) {
            printf("What element do you want to change? Write in form 'x y element' or '-1 -1 -1' to quit: ");
            scanf("%d %d %f", &x, &y, &element);

            if (x == -1 && y == -1 && element == -1) {
                break; 
            }

            if (x < 0 || x >= rows || y < 0 || y >= columns) {
                printf("Invalid coordinates! Please enter valid coordinates.\n");
                continue;
            }

            matrix[x][y] = element;
            printf("Matrix element [%d][%d] updated to %.2f\n", x, y, element);
            print_matrix(rows, columns, matrix);
        }
    }

    printf("Enter the number you are looking for: ");
    scanf("%f", &input);

    for (int i = 0; i < rows; i++) {
        int found = 0;
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] == input) {
                printf("Found number '%.2f' at the position [%d][%d]\n", input, i, j);
                found = 1;
                break; 
            }
        }
        if (!found) {
            printf("Number '%.2f' not found in row %d.\n", input, i);
        }
    }

    return 0;
}