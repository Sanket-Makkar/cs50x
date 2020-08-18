#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height - 1; h++)
    {
        for (int w = 0; w < width - 1; w++)
        {
            float avgpxl = round((image[h][w].rgbtRed + image[h][w].rgbtBlue + image[h][w].rgbtGreen)/3);
            image[h][w].rgbtRed = avgpxl;
            image[h][w].rgbtGreen = avgpxl;
            image[h][w].rgbtBlue = avgpxl;
            
        }
    }
    return;
}

// Convert image to sepia
int prevent_maximum_limit(int value);
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height - 1; h++)
    {
        for (int w = 0; w < width - 1; w++)
        {
            RGBTRIPLE holder = image[h][w];
            int R = holder.rgbtRed;
            int G = holder.rgbtGreen;
            int B = holder.rgbtBlue;
            image[h][w].rgbtRed = prevent_maximum_limit(round(.393 * R + .769 * G + .189 * B));
            image[h][w].rgbtGreen = prevent_maximum_limit(round(.349 * R + .686 * G + .168 * B));
            image[h][w].rgbtBlue = prevent_maximum_limit(round(.272 * R + .534 * G + .131 * B));
        }
    }
    return;
}

int prevent_maximum_limit(int value)
{
    if (value > 255)
    {
        value = 255;
    }
    return value;
}




// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int filler_var[3];
    for (int h = 0; h < height - 1; h++)
    {
        for (int w = 0; w < width/2; w++)
        {
            filler_var[0] = image[h][w].rgbtRed;
            filler_var[1] = image[h][w].rgbtGreen;
            filler_var[2] = image[h][w].rgbtBlue;
            
            image[h][w].rgbtRed = image[h][width - 1 - w].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - 1 - w].rgbtGreen;
            image[h][w].rgbtBlue = image[h][width - 1 - w].rgbtBlue;
            
            image[h][width - 1 - w].rgbtRed = filler_var[0];
            image[h][width - 1 - w].rgbtGreen = filler_var[1];
            image[h][width - 1 - w].rgbtBlue = filler_var[2];
            
// filler = img1
// img1 = img0
// img0 = filler
        }
        return;
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
