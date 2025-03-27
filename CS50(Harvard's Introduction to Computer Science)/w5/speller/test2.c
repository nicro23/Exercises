#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a = 'a';
    char b = 'a';
    char c;
    for(int i = 0; i < 26; i++)
    {
        b = 'a';
        for(int j = 0; j < 26; j++)
        {
            c = 'a';
            for(int k = 0; k < 26; k++)
            {
                int curr = (a - 'a' + 1) * 26 + (b - 'a' + 1) * 26 * 26 + (c - 'a' + 1);
                printf("%i: %c%c%c\n", curr, a, b, c);
                c++;
            }
            b++;
        }
        a++;
    }                                                                   
}
