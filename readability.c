#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//find letters per 100 words
//find sentences per 100 words
int main(void)
{
    string text = get_string("text: ");
    int sentencecount = 0;
    int wordcount = 1;
    int lettercount = 0;
    
    for (int a = 0; a < strlen(text); a++)
    {
        if ((text[a] >= 'a' && text[a] <= 'z') || (text[a] >= 'A' && text[a] <= 'Z'))
        {
            lettercount++;
        }
        
        if (text[a] == ' ')
        {
            wordcount++;
        }
        if (text[a] == '.' || text[a] == '?' || text[a] == '!')
        {
            sentencecount++;
        }
    }

    float lpw = ((float)lettercount/(float)wordcount) * 100;
    float spw = ((float)sentencecount/(float)wordcount) * 100;
    
    float index = round(0.0588 * lpw - 0.296 * spw - 15.8);
    int w = index;
    
    if(w < 0){
        printf("Before Grade 1...\n");
    }
    else if (w > 16){
        printf("Grade 16+\n");
    }
    else printf("Grade: %d\n", w);

}