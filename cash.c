#include <cs50.h>
#include <stdio.h>

int main(void){
    printf("Change: ");
    float x; 
    int c = 0;
    scanf("%f", &x);
    
    while (x != 0){
        if (x >= .25){
            x = x - .25;
            c++;
        }
        else if (x >= .1){
            x = x - .1;
            c++;
        }
        else if (x >= .05){
            x = x - .05;
            c++;
        }
        else if (x >= .01){
            x = x - .01;
            c++;
        }
    }
    if (x == 0){
        printf("%d", c);
    }
}