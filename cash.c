#include <stdio.h>
#include <cs50.h>
#include <math.h>
    int c = 0;
int main(void){
    printf("change in dollars: ");
    double x;
    scanf("%lf", &x);
    while (x >= .25){
        x = x - .25;
        c = c + 1;
    }
    while (x >= .1){
        x = x - .1;
        c = c + 1;
    }
    while (x >= .05){
        x = x - .05;
        c = c + 1;
    }
    while (x >= .01){
        x = x - .01;;
        c = c + 1;
    }
    printf("%d", c);
}
