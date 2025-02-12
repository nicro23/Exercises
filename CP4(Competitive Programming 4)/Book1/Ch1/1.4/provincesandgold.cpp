#include<bits/stdc++.h>
using namespace std;

int main()
{
    int g, s, c, tot;
    scanf("%i %i %i", &g, &s, &c);
    tot = g * 3 + s * 2 + c * 1;
    if(tot > 7)
    {
        printf("Province or ");
    }
    else if(tot > 4){
           printf("Duchy or "); 
        }
        else if(tot > 1){
            printf("Estate or ");
        }
    if(tot > 5){
        printf("Gold");
    }
    else
    {
        (tot > 2) ? printf("Silver") : printf("Copper");
    }
}