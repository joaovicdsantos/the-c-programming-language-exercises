#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_NUMBER 20

int main()
{
    char c, state;
    int word_i = -1, max_height = 0, word_size[MAX_WORD_NUMBER] = {0};

    state = OUT;
    while ((c = getchar()) != EOF && word_i < MAX_WORD_NUMBER)
    {
        if (state == IN)
        {
            word_size[word_i]++;
            max_height = word_size[word_i] > max_height ? word_size[word_i] : max_height;
        }

        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            word_i++;
        }
    }

    putchar('\n');

    int word_size_copy[MAX_WORD_NUMBER] = {0};
    for (int i = 0; i < MAX_WORD_NUMBER; i++)
        word_size_copy[i] = word_size[i];

    // Vertical Histogram == Brazilian Gambiarra
    for (short j = max_height; j > 0; j--)
    {
        putchar(' ');
        for (short i = 0; i < MAX_WORD_NUMBER; i++)
        {
            if (word_size_copy[i] == j)
            {
                word_size_copy[i]--;
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

    for (short i = 0; i < MAX_WORD_NUMBER; i++)
        printf("%2d  ", word_size[i]); // there is no word greater than 99, right??
    putchar('\n');

    return 0;
}
