#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[6];
    char *y = "hello";
    strcpy(x, y);
    printf("%s\n", x);
}
