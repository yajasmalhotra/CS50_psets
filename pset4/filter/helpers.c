#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gray;

    for (int i = 0; i < height; i++) // iterates through each row
    {
        for (int j = 0; j < width; j++) // iterates through each pixel
        {
            if (image[i][j].rgbtRed == image[i][j].rgbtGreen && image[i][j].rgbtRed == image[i][j].rgbtBlue)
            {
                continue;
            }
            gray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00); // finds average of RGB values

            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray; 
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE reflected[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int reflect = width - j - 1;
            
            reflected[i][reflect] = image[i][j];
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = reflected[i][j];
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float sum_red, sum_green, sum_blue; 
    
    RGBTRIPLE blurred[height][width];           // creates a copy of the image
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blurred[i][j] = image[i][j];        // replicates each pixel
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sum_red = 0;
            sum_green = 0;
            sum_blue = 0;
            
            int pixels = 0;
            
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k >= 0 && j + l >= 0 && i + k <= height - 1 && j + l <= width - 1)
                    {
                        sum_red = blurred[i + k][j + l].rgbtRed + sum_red;
                        sum_green = blurred[i + k][j + l].rgbtGreen + sum_green;
                        sum_blue = blurred[i + k][j + l].rgbtBlue + sum_blue;
                        
                        pixels += 1;
                    }
                }
            }
            
            image[i][j].rgbtRed = round(sum_red / pixels);
            image[i][j].rgbtGreen = round(sum_green / pixels);
            image[i][j].rgbtBlue = round(sum_blue / pixels);
        }
        
    }
    
    return;
}
