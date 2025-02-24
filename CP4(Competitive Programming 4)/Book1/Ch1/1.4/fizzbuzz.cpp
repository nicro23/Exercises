#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y, n, f;
    scanf("%i %i %i", &x, &y, &n);
    for(int i = 1; i <= n; i++){
        f = 1;
        if(i % x == 0){
            printf("Fizz");
            f = 0;
        }
        if(i % y == 0){
            printf("Buzz");
            f = 0;
        }
        if(f){
            printf("%i", i);
        }
        printf("\n");
    }
}