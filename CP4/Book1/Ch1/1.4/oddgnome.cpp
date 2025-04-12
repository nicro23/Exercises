#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, g, x[1000], f;
    scanf("%i", &n);
    while(n--){
        scanf("\n%i", &g);
        f = 1;
        for(int i = 0; i < g; i++){
            scanf("%i", &x[i]);
            if(x[i] != x[i - 1] + 1 && f && i > 0){
                printf("%i\n", i + 1);
                f = 0;
            }
        }
    }
}