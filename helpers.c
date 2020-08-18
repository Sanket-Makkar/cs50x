#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height - 1; h++)
    {
        for (int w = 0; w < width - 1; w++)
        {
            RGBTRIPLE holder = image[h][w];
            int avgpxl = round(((holder.rgbtRed + holder.rgbtBlue + holder.rgbtGreen)/3));
            image[h][w].rgbtRed = image[h][w].rgbtGreen = image[h][w].rgbtBlue = avgpxl;
            
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height - 1; h++)
    {
        for (int w = 0; w < width - 1; w++)
        {
            image[h][w].rgbtRed = image[h][w].rgbtRed + 30;
        }
    }
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
