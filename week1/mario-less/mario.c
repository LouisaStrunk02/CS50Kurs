#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("height: ");
    } while (h < 1 || h > 8);

    for (int i = 0; i < h; i++)
    {
        for (int j = h - 1; j > 1; j--)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
