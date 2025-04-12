#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    string para = get_string("enter text: ");
    int len = strlen(para), letter_ct = 0, sent_ct = 0;
    float avg_ltr, avg_sen, word_ct = 1, index;
    for (int i = 0; i < len; i++)
    {
        if (para[i] == ' ')
        {
            word_ct++;
        }
        if ((para[i] >= 'a' && para[i] <= 'z') || (para[i] >= 'A' && para[i] <= 'Z'))
        {
            letter_ct++;
        }
        if (para[i] == '.' || para[i] == '!' || para[i] == '?')
        {
            sent_ct++;
        }
        // printf("%c",para[i]);
    }
    avg_ltr = letter_ct / (word_ct / 100);
    avg_sen = sent_ct / (word_ct / 100);
    // alt version
    //  avg_ltr = letter_ct/word_ct;
    //  avg_sen = sent_ct/word_ct;
    //  avg_ltr *= 100;
    //  avg_sen *= 100;

    index = (0.0588 * avg_ltr) - (0.296 * avg_sen) - 15.8;
    // debugging
    //  printf("%f %i %i %f %f %f\n", word_ct, letter_ct, sent_ct, avg_ltr, avg_sen, index);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        int ans = round(index);
        printf("Grade %i\n", ans);
        // printf("Grade %f\n", index);
    }
}
