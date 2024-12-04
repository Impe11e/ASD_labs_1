#include <stdlib.h>
#include <stdio.h>

int main() {
    int rows = 7; 
    int cols = 10;
    float input_num;

    float matrix[7][10] = {
        {100, 56.78, 30, 11, 11, 3.5, 0, -1, -1, -1},
        {11, 11, 4, 2.3, 2.2, 0, -3, -4, -5.6, -10},
        {30, 23.7, 23.1, 11, 11, 11, 4, 3.5, 0, -1},
        {3, 0, 0, 0, 0, -4, -5.6, -10, -10, -12},
        {6, 4.4, 3, 3, 1, -5.6, -5.6, -10, -11.4, -12},
        {56.78, 56.78, 32, 23.1, 11, 0, 0, -1, -5.6, -11.4},
        {-11.4, -11.4, -11.45, -12, -13, -15.67, -16, -16.12, -25, -30}
    };

    printf("Matrix has the form:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%7.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("What number do you want to find?\n");
    scanf("%f", &input_num);

    for (int i = 0; i < rows; i++) {
        int L = 0, R = cols - 1;
        int found = 0;
        while (L <= R) {
            int cur_num = (L + R) / 2;
            if (input_num == matrix[i][cur_num]) {
                printf("Found target '%.2f' on the position [%d][%d].\n", input_num, i, cur_num);
                found = 1;
                break;
            } 
            else if (input_num > matrix[i][cur_num]) {
                R = cur_num - 1;
            }
            else {
                L = cur_num + 1;
            }
        }
        if (!found) {
            printf("Target '%.2f' is not found in the row %d.\n", input_num, i);
        }
    }

    return 0;
}