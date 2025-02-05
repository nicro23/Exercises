#include<bits/stdc++.h>
using namespace std;

string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int main()
{
    struct tm old_time;
    time_t curr_times, old_times;
    int n;
    cin>>old_time.tm_mday>>n;
    old_time.tm_mon = n - 1;
    cin>>n;
    old_time.tm_year = n - 1900;
    old_time.tm_hour = 0;
    old_time.tm_min = 0;
    old_time.tm_sec = 0;
    old_time.tm_isdst = -1;
    old_times = mktime(&old_time);
    cout<<days[old_time.tm_wday]<<endl;
    time(&curr_times);
    int diff = difftime(curr_times, old_times)/ 86400; 
    cout<<diff;
}