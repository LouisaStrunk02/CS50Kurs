#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("height: ");
    } while (h < 1 || h > 8);

    // for each row
    for (int i = 0; i < h; i++)
    {
        // for each column
        for (int j = 0; j < h - i; j++)
        {
            // print nothing
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            // print a brick
            printf("#");
        }

        printf("  ");

        for (int j = 0; j <= i; j++)
        {
            // print a brick
            printf("#");
        }

        // move to next row
        printf("\n");
    }
}