#include <stdio.h>
#include <cs50.h>
int main(void)
{
    printf("height: ");
    int x;
    scanf("%d", &x);
    if (x <= 8)
    {
        if (x >= 1)
        {
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
        else
        {
            printf("height: ");
            int x;
            scanf("%d", &x);
            if (x <= 8)
            {
                if (x >= 1)
                {
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
            }
        }
    }
}