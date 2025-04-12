#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a;
    scanf("%i", &n);
    while(n--)
    {
        scanf("%i", &a);
        (a%2) ? printf("%i is odd\n", a) : printf("%i is even\n", a);
    }
}