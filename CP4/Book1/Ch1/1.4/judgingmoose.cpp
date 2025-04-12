#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l, r;
    scanf("%i %i", &l, &r);
    if (l == 0 && r == 0){
        printf("Not a moose");
    }
    else if(l != r){
        printf("Odd "); 
        (l > r) ? printf("%i", l*2) : printf("%i", r*2);
    }
    else
    {
        printf("Even %i", l*2);
    }
}