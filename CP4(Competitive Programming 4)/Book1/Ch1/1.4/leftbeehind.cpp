#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    scanf("%i %i", &x, &y);
    while(x != 0 || y != 0)
    {
        if(x + y == 13){
            printf("Never speak again.\n");
        }
        else{
            if(x == y){
                printf("Undecided.\n");
            }
            else{
                (x > y) ? printf("To the convention.\n") : printf("Left beehind.\n");
            }
        }
        scanf("%i %i", &x, &y);
    }
}