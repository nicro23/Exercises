#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, min, ct, res, x;
    min = INT_MAX;
    ct = 0;
    scanf("%i\n", &n);
    while(n--){
        scanf("%i", &x);
        if(x < min){
            min = x;
            res = ct;
        }
        ct++;
    }
    printf("%i", res);
}