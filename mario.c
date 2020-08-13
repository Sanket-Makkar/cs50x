#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
int main(void)
{
    int x;
    do
    {
        x = get_int("height: ");
    }
    while (x <= 0 || x > 8);
    for (int y = 0; y < x; y = y + 1)
    {
        for (int k = 0; k < x - y - 1; k = k + 1)
        {
            printf(" ");
        }
        for (int j = 0; j <= y; j = j + 1)
        {
            printf("#");
        }
        printf("\n");
    }
}