#include <stdio.h>
#include <cs50.h>
int main(void){
    printf("Change: ");
    int c = 0;
    int a;
    scanf("%d", &a);
    
    if (a <= .25){
        c = c + 1;
        a = a - .25
    }
}