#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first<b.first)
        return 1;
    else if(a.first>b.first)
        return 0;
    else if(a.second>b.second)
        return 1;
    else if(a.second<b.second)
        return 0;

}
int main()
{
    ios::sync_with_stdio(false);
    vector< pair<int,int> >a(1001);
    for(int i=1; i<1001; i++)
    {
        a[i].second=i;
        a[i].first=0;
    }
    for(int i=1; i<1001; i++)
    {
        for(int j=i; j<1001; j+=i)
            a[j].first++;
    }
    sort(a.begin(),a.end(),cmp);
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<"Case "<<cs++<<": "<<a[n].second<<"\n";
    }
}
