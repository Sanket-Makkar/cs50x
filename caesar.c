#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, string argv[]){

    if (isalpha(*argv[1])){
        printf("try putting a number instead...\n");
        return 1;
    }
    if (!isdigit(*argv[1])){
        printf("please try and add another value after the caesar command\n");
        return 1;
    }
    if (argc != 2){
        printf("please put in a key number after caesar command");
        return 1;
    }

    int n;
    n = atoi (argv[1]);

    string line = get_string("text: ");

    
    if (argc == 2){
    if (!isalpha(*argv[1])){
    if (isdigit(*argv[1])){
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
}
}
}