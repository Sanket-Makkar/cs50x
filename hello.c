#include <cs50.h>
#include <stdio.h>
int main(){
char name[100];
printf("Enter your name: \n");
scanf("%s", name);
printf("Hello %s\n", name);
}