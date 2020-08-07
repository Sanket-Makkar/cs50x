#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void){
double x;
do{
   x = get_double("Change: ");
} while (x <= 0);
    
int y = round (x * 100);
    
int c = 0;
while (y >= 25){
    y = y - 25;
    c++;
}
while(y >= 10){
    y = y - 10;
    c++;
}
while(y >= 5){
    y = y - 5;
    c++;
}
while(y >= 1){
    y = y - 1;
    c++;
}
    printf("%d\n", c);
}