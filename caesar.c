#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// whats left to do: adjust for capital letters, and loop z to a
int main(int argc, string argv[]){

string line = get_string("text: ");

    int n;
    n = atoi (argv[1]);
    for(int a = 0; a < strlen(line); a++){
        if(isalpha(line[a])){
            line[a] = line[a] + n;
        }
    }
    printf("%s", line);
}