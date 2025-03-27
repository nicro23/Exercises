#include<cs50.h>
#include<stdio.h>
#include<string.h>
int main(int argc,string argv[])
{
    for(int i = 0;i < argc;i++)
    {
        int l = strlen(argv[i]);
         printf("%s", argv[i]);
        // for(int j = 0;j<l;j++)
        // {

        // }
        printf("\n");
    }
}
