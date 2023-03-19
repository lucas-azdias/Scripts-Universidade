#include <stdio.h>

int main()
{
    int v[4] = {1, 2, 3, 4};

    int* p = &v[0];
    *p = 8; // Altera v[0]
    printf("v[0] = %d\n", v[0]);

    p++;
    *p = 7; // Altera v[1]
    printf("v[1] = %d\n", v[1]);

    p++;
    *p = 6; // Altera v[2]
    printf("v[2] = %d\n", v[2]);

    p++;
    *p = 5; // Altera v[3]
    printf("v[3] = %d\n", v[3]);

    return 0;
}
