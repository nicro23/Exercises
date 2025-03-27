#include<bits/stdc++.h>
using namespace std;

int main(){
    int x1, x2, y1, y2, a1, a2;
    while(scanf("%i %i %i %i\n", &x1, &x2, &y1, &y2)){
        if(x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0){
            break;
        }
        if((x1 == y1 && x2 == y2) || (x1 == y2 && x2 == y1)){
            printf("Tie.\n");
        }
        else if((x1 == 1 && x2 == 2) || (x1 == 2 && x2 == 1))
        {
            printf("Player 1 wins.\n");
        }
        else if ((y1 == 1 && y2 == 2) || (y1 == 2 && y2 == 1)){
            printf("Player 2 wins.\n");
        }
        else if(x1 == x2 || y1 == y2)
        {
            if(x1 == x2 && y1 == y2){
                    (x1 > y1) ? printf("Player 1 wins.\n") :  printf("Player 2 wins.\n");
            }
            else
            {
                (x1 == x2) ? printf("Player 1 wins.\n") :  printf("Player 2 wins.\n");
            }
        }
        else{
            (x1 > x2) ? a1 = x1*10 + x2 : a1 = x2*10 + x1;
            (y1 > y2) ? a2 = y1*10 + y2 : a2 = y2*10 + y1;
            (a1 > a2) ? printf("Player 1 wins.\n") :  printf("Player 2 wins.\n");
        }
    }
}