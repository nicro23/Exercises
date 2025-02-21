#include<bits/stdc++.h>
using namespace std;

int main()
{
    char x, y[3];
    int n, a, b;
    scanf("%i\n", &n);
    while(n--){
        scanf("%c", &x);
        if(x == 'P')
        {
            scanf("%3c\n", &y[0]);
            printf("skipped\n");
        }
        else{
            a = x - '0';
            scanf("%c", &x);
            while(x != '+'){
                a = a * 10 + (x - '0');
                scanf("%c", &x);
            }
            scanf("%c", &x);
            b = x - '0';
            scanf("%c", &x);
            while(x != '\n')
            {
                b = b * 10 + (x - '0');
                scanf("%c", &x);
            }
            printf("%i\n", a + b);
        }
    }
}