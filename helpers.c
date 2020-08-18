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
int prevent_maximum_limit(int value);
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtRed = ensurewithin(round(0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.189 * image[h][w].rgbtBlue));
            image[h][w].rgbtGreen = ensurewithin(round(0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue));
            image[h][w].rgbtBlue = ensurewithin(round(0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue));
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
