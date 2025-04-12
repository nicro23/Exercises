#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a, b; 
    scanf("%lf %lf", &a, &b);
    if(b == 1)
    {
        (a == 0) ? printf("ALL GOOD") : printf("IMPOSSIBLE");
    }
    else
    {
        printf("%f", -(a/(b - 1)));
    }
}