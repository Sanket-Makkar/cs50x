#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtRed = image[h][w].rgbtRed + 0;
            image[h][w].rgbtBlue = image[h][w].rgbtRed;
            image[h][w].rgbtGreen = image[h][w].rgbtRed; 
        }
    }
    return;
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
