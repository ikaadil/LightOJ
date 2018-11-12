#include<bits/stdc++.h>
using namespace std;
#define n 10000001
bool ara[n];
vector<int>v;
void sieve()
{
    ara[0]=ara[1]=1;
    for(long long i=4; i<n; i+=2)ara[i]=1;
    for(long long i=3; i<n; i++)
    {
        if(ara[i]==0)
        {
            for(long long int j=i*i; j<n; j+=2*i)ara[j]=1;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(ara[i]==0)v.push_back(i);
    }
}
int main()
{
     ios::sync_with_stdio(false);
    sieve();
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int nu,cnt=0;
        cin>>nu;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>nu-v[i])
                break;
            if(ara[nu-v[i]]==0)
                cnt++;
        }
        cout<<"Case "<<cs++<<": "<<cnt<<"\n";

    }
}
