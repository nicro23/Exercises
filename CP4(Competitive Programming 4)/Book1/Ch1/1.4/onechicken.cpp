#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%i %i", &n, &m);
    if(n > m){
        (n - m > 1) ? printf("Dr. Chaz needs %i more pieces of chicken!", n - m) : printf("Dr. Chaz needs 1 more piece of chicken!");
    }
    else{
        (m - n > 1) ? printf("Dr. Chaz will have %i pieces of chicken left over!", m - n) : printf("Dr. Chaz will have 1 piece of chicken left over!");
    }
}