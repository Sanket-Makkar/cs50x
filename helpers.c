#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float avgpxl;
            RGBTRIPLE a = image[height][width];
            avgpxl = round(((a.rgbtRed + a.rgbtBlue + a.rgbtGreen)/3.00));
            image[h][w].rgbtRed = avgpxl;
            image[h][w].rgbtBlue = avgpxl;
            image[h][w].rgbtGreen = avgpxl;
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
