#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    float x,y,z;
    scanf("%i", &n);
    while(n--)
    {
        scanf("%f %f", &x, &y);
        z += x * y;
    }
    printf("%.3f", z);
}