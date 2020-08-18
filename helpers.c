#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height - 1; h++)
    {
        for (int w = 0; w < width - 1; w++)
        {
            int avgpxl = ((image[h][w].rgbtRed + image[h][w].rgbtBlue + image[h][w].rgbtGreen)/3);
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
            if ((image[h][w].rgbtRed >= 200) && (image[h][w].rgbtBlue >= 200) && (image[h][w].rgbtGreen >= 200))
            {
                image[h][w].rgbtRed = image[h][w].rgbtRed;
                image[h][w].rgbtBlue = image[h][w].rgbtBlue;
                image[h][w].rgbtGreen = image[h][w].rgbtGreen;
            }
            
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
