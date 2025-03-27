#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if( argc != 2)
    {
        printf("lol go learn math\n");
        return 1;
    }
    FILE *input = fopen( argv[1], "r");
    if(input == NULL)
    {
        printf("lol go make folder\n");
        return 1;
    }
    BYTE c[512];
    // c[0]c[1]..c[511]
    int ct = 0,ct2 = 0;
    //fread(c,sizeof(BYTE),512,input);
    char* s = malloc(8);
    FILE *output = NULL;
    while(fread(c, sizeof(c), 1, input) != 0)
    {
        //check if this block is start of photo
        // printf("%i\n", c[0]);

        if(c[0] == 0xff && c[1] == 0xd8 && c[2] == 0xff && (c[3] >= 0xe0 && c[3] <= 0xef))
        {
            // printf("%i\n", ct2);
            if(ct > 0)
            {
                // fclose(output);
            }

            sprintf(s, "%03i.jpg", ct);
            output = fopen( s , "w");
            if (output == NULL) //extra
            {
                free(s);
                fclose(input);
                printf("lol folder make not go\n");
                return 1;
            }
            ct++;
        }
        // else
        // {
        //     ct2++;
        // }

        // find start of photos
        // read till end

        //write photo
        if(output != NULL)
        {
            fwrite(c,sizeof(c),1,output);
        }
    }
    // for(int i = 0; i < 22; i++)
    // {
    //     fread(c,sizeof(c),1,input);
    //     fwrite(c,sizeof(c),1,output);
    // }
    // printf("%i\n%i\n", ct, ct2);
    fclose(input);
    free(s);
    if(output != NULL)
    {
        fclose(output);
    }

}
