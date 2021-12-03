#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop for height and rows of the image
    float average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //sum up and average RGB
            average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue);

            // replace each pixel with grey equivelent
            image[i][j].rgbtRed = round(average / 3.0);
            image[i][j].rgbtGreen = round(average / 3.0);
            image[i][j].rgbtBlue = round(average / 3.0);

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // varibules for storing an orignal
    int originalRed = 0;
    int originalGreen = 0;
    int originalBlue = 0;

    // temp values
    float sepiaRedTemp = 0;
    float sepiaGreenTemp = 0;
    float sepiaBlueTemp = 0;

    // loop for height and row
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // store orignal
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            // red to sepia
            sepiaRedTemp = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);

            if (sepiaRedTemp >= 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRedTemp;
            }


            // green to sepia
            sepiaGreenTemp = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);

            if (sepiaGreenTemp >= 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreenTemp;
            }

            // blue to sepia
            sepiaBlueTemp = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            if (sepiaBlueTemp >= 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlueTemp;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int halfwidth = 0;
    halfwidth = round(width / 2);
    RGBTRIPLE temp;

    // loop for height and width
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < halfwidth; j++)
        {
            // store pixel in temp
            temp = image[i][j];
            // move pixel from left hand side to right hand side
            image[i][j] = image[i][width - 1 - j];
            // move pixel from temp to left hand side
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // make a copy of an image to be blurred
    RGBTRIPLE buffer[height][width];

    // loop for height and width
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // var to store sum of color channels
            int tempRed = 0;
            int tempGreen = 0;
            int tempBlue = 0;
            float count = 0;

            // [x-1][y-1]   [x][y-1]    [x+1][y-1]
            // [x-1][y]     [x][y]      [x+1][y]
            // [x-1][y+1]   [x][y+1]    [x+1][y+1]

            for (int x = i - 1; x < i + 2; x++)
            {
                for (int y = j - 1; y < j + 2; y++)
                {
                    if (x < 0 || x > height - 1 || y <  0 || y > width - 1)
                    {
                        count += 0;
                    }
                    else
                    {
                        tempRed += image[x][y].rgbtRed;
                        tempGreen += image[x][y].rgbtGreen;
                        tempBlue += image[x][y].rgbtBlue;
                        count++;
                    }
                }
            }
            buffer[i][j].rgbtRed = round(tempRed / count);
            buffer[i][j].rgbtGreen = round(tempGreen / count);
            buffer[i][j].rgbtBlue = round(tempBlue / count);
        }
    }
    for (int n = 0; n < height; n++)
    {
        for (int m = 0; m < width; m++)
        {
            image[n][m].rgbtRed = buffer[n][m].rgbtRed;
            image[n][m].rgbtGreen = buffer[n][m].rgbtGreen;
            image[n][m].rgbtBlue = buffer[n][m].rgbtBlue;
        }
    }
    return;
}
