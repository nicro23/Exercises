#include<bits/stdc++.h>
using namespace std;

void find(int val, vector<int> &v, int &mid, int i)
{
    if( val == v[mid])
    {
        cout<<"found"<<endl;
        cout<< i;
        return;
    }
    if( mid == 0 || mid + 1 == v.size())
    {
        cout<<"not found"<<endl;
        cout<< ++i;
        return;
    }
    int left = mid / 2;
    int right = mid + left;
    (val > mid)? mid = right: mid = left;
    find(val, v, mid,++i);
}
int main()
{
    vector<int> v;
    int n, mid, num, val, left, right;
    cin>>n;
    mid = n/2;
    while(n--)
    {
        cin>>num;
        v.push_back(num);
    }
    cin>>val;
    find(val, v, mid, 0);
}