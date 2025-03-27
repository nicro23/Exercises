#include<cs50.h>
#include<stdio.h>
//alphabetical
int main(void)
{
    int n = 5;
    char arr[5] = "abcde";
    for(int i = 0; i<n - 1;i++)
    {
        if(arr[i] > arr[i+1])
        {
            printf("not alpha\n");
            break;
        }
    }

}
