// check50 cs50/problems/2024/x/mario/less
// style50 mario.c

// check50 cs50/problems/2024/x/mario/more
// style50 mario.c

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

/*
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int z = 0; z <= i; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
*/

/*
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    for (int x = 0; x < height; x++)
    {
        for (int y = 1; y < height; y++)
        {
            printf(" ");
        }
        for (int z = 0; z <= x; z++)
        {
            printf("#");
        }
        printf("\n");
    }

            for (int y = 1; y < 2; y++)
        {
        printf("  ");
        }
}
*/

