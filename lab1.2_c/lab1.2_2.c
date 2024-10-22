//динамічне програмування
#include <stdio.h>
#include <math.h>

int main() {
    
    int n;
    double sum = 0.0;
    double product = 1.0;
    double degree = 1.0;
    int counter = 0;

    printf("Enter value of 'n': ");
    scanf("%d", &n);

    counter += 1;
    for (int i = 1; i <= n; i++) {
        degree *= 4;
        product *= (i + cos(i));
        sum += (degree - i) / product;
        counter += 10;
    }

    printf("Result: sum = %.7f, operations count = %d", sum, counter);
    return 0;
}