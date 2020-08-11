#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// whats left to do: adjust for capital letters, and loop z to a
int main(int argc, string argv[]){

string line = get_string("text: ");

    if (argc != 2){
        printf("Usage is: ./caesar k\n");
        return 1;
    }
    int n;
    n = atoi (argv[1]);
    if ((n >= 0) && (n <= 10000)){
    for(int a = 0; a < strlen(line); a++){
        if(isalpha(line[a])){
            if(islower(line[a])){
                line[a] = ((line[a] + n - 97 ) %26 )+ 97;
            }
            if(isupper(line[a])){
                line[a] = ((line[a] + n - 65) %26 ) + 65;
            }
        }
    }
printf("ciphertext: %s\n", line);
}
}