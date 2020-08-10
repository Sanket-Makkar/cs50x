#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// you need letters per 100 words
// you need

int main(void){
    //letters
    int L = 0;
    //word count
    int S = 1;
    //sentence count
    int U = 0;

    //get lines
    string lines = get_string("Text: ");

    for(int a = 0; a < strlen(lines); a++){
        //count letters
        if ((lines[a] >= 'a' && lines[a] <= 'z') || (lines[a] <= 'Z' && lines[a] >= 'A')){
            L = L + 1;
        }
        //count words 
        if (lines[a] == ' '){
            S++;
        }
        //count sentences
        if (lines[a] == '.' || lines[a] == '?' || lines[a] == '!'){
            U++;
        }
    }



//final calculation
   int i =  0.0588 * (100 * (float) L / (float) S) - 0.296 * (100 * (float) U / (float) S) - 15.8;

if((i < 16) && (i > 0)){
    printf("Grade %d\n", i);
}
else if (i > 16){
    printf("grade 16+\n");
}
else if (i < 1){
    printf("before grade 1\n");
}


}