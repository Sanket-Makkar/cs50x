#include <stdio.h>
#include <cs50.h>
int c = 0;
float x;

void cash();

int main(void){
    
printf("how much change in dollars: ");
scanf("%f", &x);
cash();
}

void cash(){
    while (x >= .25){
        x = x - .25;
        c++;
    }
    while (x >= .1){
        x = x - .1;
        c++;
    }
    while (x >= .05){
        x = x - .05;
        c++;
    }
    while (x >= .01){
        x = x - .01;
        c++;
    }
printf("%d coins needed", c);
}
