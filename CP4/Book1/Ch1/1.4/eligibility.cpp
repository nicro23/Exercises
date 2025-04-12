#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, course;
    char name[31], study[11], birth[11];
    scanf("%i", &n);
    while(n--)
    {
        scanf("%s %s %s %i", name, study, birth, &course);
        printf("%s ", name);
        if((study[0] == '2' && study[1] >= '0' && study[2] > '0')
        || (birth[0] > '1' || (birth[0] == '1' && birth[1] == '9' && birth[2] == '9' && birth[3] > '0')))
        {
            printf("eligible \n");
        }
        else{
            (course > 40) ? printf("ineligible\n") : printf("coach petitions\n");
        }
    }
}