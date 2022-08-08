#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long cardnumber = get_long("Number: ");
    long usedcardnumber = cardnumber;
    int remainder = 0;
    bool evenposition = false;
    int summe = 0;
    int length = 0;
    int multipliedremainder = 0;

    while (usedcardnumber > 0)
    {
        length = length + 1;
        remainder = usedcardnumber % 10;

        if (evenposition)
        {
            multipliedremainder = remainder * 2;

            if (multipliedremainder > 9)
            {
                int remainder1 = multipliedremainder / 10;
                int remainder2 = multipliedremainder % 10;
                summe = summe + remainder1;
                summe = summe + remainder2;
            }
            else
            {
                summe = summe + multipliedremainder;
            }
        }
        else
        {
            summe = summe + remainder;
        }

        evenposition = !evenposition;
        usedcardnumber = (usedcardnumber - remainder) / 10;
    }

    if (summe % 10 == 0)
    {
        // AMEX numbers
        if (length == 15)
        {
            int atest = cardnumber / pow(10, 13);

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
            int mtest = cardnumber / pow(10, 14);
            int vtest = cardnumber / pow(10, 15);

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
            int vtest = cardnumber / pow(10, 12);
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
