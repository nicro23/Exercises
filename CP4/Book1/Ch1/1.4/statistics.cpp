#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, min, max, t = 1;
    while(scanf("%i", &n) != EOF)
    {
        min = INT_MAX;
        max = INT_MIN;
        n--;
        while(n--){
            scanf("%i", &x);
            if( x > max){
                max = x;
            }
            if (x < min){
                min = x;
            }
        }
        scanf("%i\n", &x);
        if( x > max){
            max = x;
        }
        if (x < min){
            min = x;
        }
        printf("Case %i: %i %i %i\n", t++, min, max, max - min);
    }
}