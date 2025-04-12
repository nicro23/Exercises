#include<bits/stdc++.h>
using namespace std;
string s = "14159265358979";

int main()
{
    int n;
    cin>>n;
    if(n<16 && n>0)
    {
        int i = 0;
        cout<<"3.";
        for(; i < n - 1;i++)
        {
            cout<<s[i];
        }
        (s[i + 1] >= '5')? cout<<++s[i]:cout<<s[i];
    }
}