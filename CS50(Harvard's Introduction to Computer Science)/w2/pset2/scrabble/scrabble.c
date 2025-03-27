#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int compute_score(string word)
{
    int s = 0, l = strlen(word);
    for(int i = 0; i < l;i++)
    {
        word[i] = toupper(word[i]);
        if(word[i] >= 'A' && word[i] <= 'Z')
        {
            s++;
            if(word[i] == 'D' || word[i] == 'G')
            {
                s++;
            }
            if(word[i] == 'B' || word[i] == 'C' || word[i] == 'P' || word[i] == 'M')
            {
                s+=2;
            }
            if(word[i] == 'F' || word[i] == 'H' || word[i] == 'V' || word[i] == 'W' || word[i] == 'Y')
            {
                s+=3;
            }
            if(word[i] == 'K')
            {
                s+=4;
            }
            if(word[i] == 'J' || word[i] == 'X')
            {
                s+=7;
            }
            if(word[i] == 'Q' || word[i] == 'Z')
            {
                s+=9;
            }

        }
    }
    return s;
}
int main(void)
{
    string p1 = get_string("p1: "),p2 = get_string("p2: ");
    int l1 = strlen(p1), l2 = strlen(p2);
    int s1 = compute_score(p1), s2 = compute_score(p2);

    if(s1 > s2)
    {
        printf("Player 1 wins!\n");
    }
    else if(s2 > s1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
