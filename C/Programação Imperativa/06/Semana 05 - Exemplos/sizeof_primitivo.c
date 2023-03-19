#include <stdio.h>

// "sizeof(var)" mostra tamanho em bytes da variável

int main() {
    int x = 10;
    printf("int: %lu\n", sizeof(x)); // 4

    unsigned int y = 10;
    printf("unsigned int: %lu\n", sizeof(y)); // 4

    short int z = 10;
    printf("short int: %lu\n", sizeof(z)); // 2

    long int w = 10;
    printf("long int: %lu\n", sizeof(w)); // 4

    float f = 10;
    printf("float: %lu\n", sizeof(f)); // 4

    double d = 10;
    printf("double: %lu\n", sizeof(d)); // 8

    char c = 'T';
    printf("char: %lu\n", sizeof(c)); // 1

    return 0;
}
