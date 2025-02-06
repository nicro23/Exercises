#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int v, n;
    while(scanf("%lld %lld", &v, &n) != EOF)
    {
        printf("%lld\n", abs(v-n));
    }
}