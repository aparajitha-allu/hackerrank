#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	
     int a, b;
    float c, d;

    scanf("%d %d", &a, &b);    // Read two integers
    scanf("%f %f", &c, &d);    // Read two floats

    printf("%d %d\n", a + b, a - b);           // int sum and difference
    printf("%.1f %.1f", c + d, c - d);         // float sum and difference (1 decimal)

    return 0;
}
