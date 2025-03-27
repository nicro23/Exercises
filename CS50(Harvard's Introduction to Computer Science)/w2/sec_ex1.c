#include<cs50.h>
#include<stdio.h>
//doubling up
int main(void)
{
    int n = 5;
    int arr[5];
    arr[0] = 1;
    for(int i = 1; i<n;i++)
    {
        arr[i] = arr[i-1]*2;
    }
    for(int i = 0;i<n;i++)
    {
        printf("%i\n", arr[i]);
    }
}
