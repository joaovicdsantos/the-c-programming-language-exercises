#include <stdio.h>

int main(void)
{
    int c, lc;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' || (c == ' ' && lc != ' '))
            putchar(c);
        lc = c;
    }
    return 0;
}
