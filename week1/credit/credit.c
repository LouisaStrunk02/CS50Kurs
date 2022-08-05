#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long cnumber = get_long("Number: ");
    long a = cnumber;
    int r = 0;
    bool even = false;
    int summe = 0;
    int length = 0;
    int n = 0;

    while (a > 0)
    {
        length = length + 1;
        r = a % 10;
        if (even)
        {
            n = r * 2;
            if (n > 9)
            {
                int r1 = n / 10;
                int r2 = n % 10;
                summe = summe + r1;
                summe = summe + r2;
            }
            else
            {
                summe = summe + n;
            }
        }
        else
        {
            summe = summe + r;
        }
        even = !even;
        a = (a - r) / 10;
    }

    if (summe % 10 == 0)
    {
        // AMEX numbers
        if (length == 15)
        {
            int atest = cnumber / pow(10, 13);
            if (atest == 34 || atest == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // MASTERCARD numbers or VISA numbers
        else if (length == 16)
        {
            int mtest = cnumber / pow(10, 14);
            int vtest = cnumber / pow(10, 15);
            if (mtest == 51 || mtest == 52 || mtest == 53 || mtest == 54 || mtest == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (vtest == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // VISA numbers
        else if (length == 13)
        {
            int vtest = cnumber / pow(10, 12);
            if (vtest == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
