#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// you need letters per 100 words
// you need

int main(void){
    //letter count
    int L = 0;
    //word count
    int S = 1;
    //sentence count
    int U = 0;
    // space count
    int o = 0;

    //get lines
    string lines = get_string("Text: ");

    for(int a = 0; a < strlen(lines); a++){
        //count letters
        L = L + 1;
        //count words and spaces
        if (lines[a] == ' '){
            S++;
            o++;
        }
        //count sentences
        if (lines[a] == '.' || lines[a] == '?' || lines[a] == '!'){
            U++;
        }
    }

   // letter total
    int b = L - o;

   // letters per 100 words
   int g = ((float)b/(float)S)*100;

   // sentences per 100 words
   int h = ((float)U/(float)S)*100;

//final calculation
   int i = .0588 * g - .296 * h - 15.8;


    printf("Grade %d", i);
  // L is for avg letters per 100 words
  // S is for avg sentences per 100 letters
}