#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            RGBTRIPLE b = image[h][w];
            float R = b.rgbtRed;
            float G = b.rgbtGreen;
            float B = b.rgbtBlue;
            
            float a = round((R + G + B)/3);
            
            image[h][w].rgbtRed = a;
            image[h][w].rgbtGreen = a;
            image[h][w].rgbtBlue = a;
            
        }
    }
}

int ensurewithin(int value)
{
    if (value > 255)
    {
        value = 255;
    }
    return value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int sepiaRed = ensurewithin(round(0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.189 * image[h][w].rgbtBlue));
            int sepiaGreen = ensurewithin(round(0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue));
            int sepiaBlue = ensurewithin(round(0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue));
            
            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;
        }
    }
    return;
}
int filler[3];
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width/2; w++)
        {
            //temp = img1, img1 = img2, img2 = temp
            filler[0] = image[h][w].rgbtRed;
            filler[1] = image[h][w].rgbtGreen;
            filler[2] = image[h][w].rgbtBlue;
            
            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;
            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;
            
            image[h][width - w - 1].rgbtRed = filler[0];
            image[h][width - w - 1].rgbtGreen = filler[1];
            image[h][width - w - 1].rgbtBlue = filler[2];
        }
    }
}




// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{    
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtGreen = image[h][w].rgbtGreen + 30;
            image[h][w].rgbtRed = image[h][w].rgbtGreen + 30;
            image[h][w].rgbtBlue = image[h][w].rgbtGreen + 30;
        }
    }
}
