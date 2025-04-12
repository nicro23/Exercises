#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int n, num;
    cin>>n;
    while(n--)
    {
        cin>>num;
        s.insert(num);
    }
    for(auto x: s)
    {cout<<x<<" ";}
}