#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    float y;
    printf("Enter number: ");
    scanf("%f", &x);

    if ((x >= -49 && x < -10) || (x > 0 && x <= 10))
    {
        y = 10 * (x * x * x) + 7 * x / 5 + 2;
        printf("y = %f\n", y);
    }
    else
    {
        if (x > 20)
            {
                y = -x + 9;
                printf("y = %f\n", y);
            }
            else 
            {
                printf("There is no function for the given x\n");
            }
    }

    return 0;
}