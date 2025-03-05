// style50 cash.c

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float value;
    int count = 0;
    do
    {
        value = get_float("Insert value: ");
    }
    while (value < 0);

    int cents = round(value * 100);

    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
            count++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            count++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            count++;
        }
        else
        {
            cents -= 1;
            count++;
        }
    }
    printf("%i\n", count);
}
