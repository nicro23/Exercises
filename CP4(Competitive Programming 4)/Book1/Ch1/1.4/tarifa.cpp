#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, n, p, t;
    t = 0;
    scanf("%i\n %i", &x, &n);
    while(n--)
    {
        scanf("%i", &p);
        t += x - p;
    }
    printf("%i", t + x);
}