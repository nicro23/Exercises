#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // incorrect way but no diff for some reason
            //  int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)
            //  / 3);
            // correct way
            double avg =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double originalBlue = image[i][j].rgbtBlue;
            double originalGreen = image[i][j].rgbtGreen;
            double originalRed = image[i][j].rgbtRed;
            int Red = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int Green = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int Blue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (Red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = Red;
            }
            if (Green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = Green;
            }
            if (Blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = Blue;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp;

            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;

            // lol noob(alt bad design)
            //  int temp = '\0';
            //  BYTE temp = '\0';
            //  temp = image[i][width - j + 1].rgbtBlue;
            //  image[i][width - j + 1].rgbtBlue = image[i][j].rgbtBlue;
            //  image[i][j].rgbtBlue = temp;

            //  temp = image[i][width - j + 1].rgbtGreen;
            //  image[i][width - j + 1].rgbtGreen = image[i][j].rgbtGreen;
            //  image[i][j].rgbtGreen = temp;

            //  temp = image[i][width - j + 1].rgbtRed;
            //  image[i][width - j + 1].rgbtRed = image[i][j].rgbtRed;
            //  image[i][j].rgbtRed = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy image go brrrr
    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double avgr = 0.0;
            double avgg = 0.0;
            double avgb = 0.0;
            int ct = 0;
            for (int i2 = i - 1; i2 <= (i + 1); i2++)
            {
                for (int j2 = j - 1; j2 <= (j + 1); j2++)
                {
                    if ((i2 >= 0 && i2 < height) && (j2 >= 0 && j2 < width))
                    {
                        avgr += image_copy[i2][j2].rgbtRed;
                        avgg += image_copy[i2][j2].rgbtGreen;
                        avgb += image_copy[i2][j2].rgbtBlue;
                        ct++;
                    }
                }
            }
            avgr = avgr / ct;
            avgg = avgg / ct;
            avgb = avgb / ct;
            image[i][j].rgbtBlue = round(avgb);
            image[i][j].rgbtGreen = round(avgg);
            image[i][j].rgbtRed = round(avgr);
        }
    }
    return;
}
