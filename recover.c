#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
typedef uint8_t BYTE; 
#define FILESIZE 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid usage. Usage: ./recover image\n");
        return 1;
    }
    FILE *filedata = fopen("card.raw", "rb");
    BYTE buffer[512];
    bool jpgfound = false;
    int filecount = 0;
    char *filename = NULL;
    filename = (char *)malloc(8 * sizeof(char));
    FILE *unrecoveredpics = NULL;
    do
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (filedata == NULL)
            {
                printf("format is ./recover card.raw");
                return 1;
            }
            if (jpgfound == true)
            {
                fclose(unrecoveredpics);
            }
            else if (jpgfound == false)
            {
                jpgfound = true;
            }
            sprintf(filename, "%03i.jpg", filecount);
            filecount++;
            unrecoveredpics = fopen(filename, "wb");    
        }
        if (filecount > 0)
        {
            fwrite(&buffer, 512, 1, unrecoveredpics);
        }
    }
    while (fread(buffer, 512, 1, filedata));
    fclose(filedata);
    fclose(unrecoveredpics);
}
