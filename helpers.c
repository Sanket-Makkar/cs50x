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

// Convert image to sepia
int prevent_maximum_limit(int value);
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
