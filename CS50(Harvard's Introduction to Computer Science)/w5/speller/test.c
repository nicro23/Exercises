#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *dict = fopen("dictionaries/large", "r");
    if(dict == NULL)
    {
        return 1;
    }
    char *temp = malloc(sizeof(char));
    if(temp == NULL)
    {
        fclose(dict);
        return 1;
    }
    int ltr_ct = 0, wrd_ct = 0;
    char *wrd = malloc(46 * sizeof(char));
    while(fread(temp,1,1,dict))
    {
        if(*temp == '\n')
        {
            wrd_ct++;
            if(ltr_ct < 2)
            {
                
                int t = toupper(wrd[0])
                printf("+%i\n", wrd_ct);
            }
            ltr_ct = 0;
        }
        else
        {
            wrd[ltr_ct] = *temp;
            ltr_ct++;
        }
    }
}
