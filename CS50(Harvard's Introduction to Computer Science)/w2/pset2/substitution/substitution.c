#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //check key is correct
    if (argc != 2)
    {
        printf("fail\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("fail\n");
        return 1;
    }
    int alpha[26] = {0};
    int l = strlen(argv[1]);
    for (int i = 0; i < l ;i++)
    {
        // printf("%c",argv[1][i]);
        // way to check for anything not alphabetic
        //  if ( !( isalpha(argv[1][i]) ) )
        //  {
        //      printf("fail\n");
        //      return 1;
        //  }

        if ( islower(argv[1][i]) )
        {
            alpha[ argv[1][i] - 'a']++;
        }
        else if ( isupper(argv[1][i]) )
        {
            alpha[ argv[1][i] - 'A']++;
        }
        else
        {
            printf("fail\n");
            return 1;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] != 1)
        {
            printf("fail\n");
            return 1;
        }
        // printf("%i ", alpha[i]);
    }

    //cyphering text using key
    string plain = get_string("plaintext:");
    int l2 = strlen(plain);
    for (int i = 0; i < l2 ;i++)
    {
        if ( islower(plain[i]) )
        {
            plain[i] = tolower(argv[1][ plain[i] - 'a']);
        }
        else if ( isupper(plain[i]) )
        {
            plain[i] = toupper(argv[1][ plain[i] - 'A']);
        }
    }
    printf("ciphertext:%s",plain);
    printf("\n");
    return 0;

}
