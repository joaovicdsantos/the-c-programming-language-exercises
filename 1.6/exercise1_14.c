#include <stdio.h>

int main()
{
    short c; // ASCII 0 to 255
    int nchar[255] = {0};

    while ((c = getchar()) != EOF)
        ++nchar[c];

    int nchar_copy[255] = {0};
    int max_height = 0;
    for (int i = 0; i < 255; i++)
    {
        nchar_copy[i] = nchar[i];
        max_height = nchar[i] > max_height ? nchar[i] : max_height;
    }

    // Vertical Histogram == Brazilian Gambiarra
    for (short j = max_height; j > 0; j--)
    {
        putchar(' ');
        for (short i = 0; i < 255; i++)
        {
            if (nchar_copy[i] < 1)
                continue;
            if (nchar_copy[i] == j)
            {
                nchar_copy[i]--;
                putchar('|');
            }
            else if (j == 1)
                putchar('_');
            else
                putchar(' ');
            printf("   "); // skip 3 columns
        }
        putchar('\n');
    }

    for (short i = 0; i < 255; i++)
    {
        if (nchar[i] < 1)
            continue;
        printf("%02X  ", i); // there is no word greater than 99, right??
    }
    putchar('\n');

    return 0;
}
