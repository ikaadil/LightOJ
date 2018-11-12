#include<bits/stdc++.h>
using namespace std;
#define n 100006
int ara[n];
int check[100000+5];
vector<long long>v;
void sieve()
{
    ara[0]=ara[1]=1;
    for(long long i=2; i<n; i++)
    {
        if(ara[i]==0)
        {
            for(long long j=i*2; j<n; j+=i)ara[j]=1;
        }
    }
    for(long long i=0; i<n; i++)
    {
        if(ara[i]==0)v.push_back(i);
    }
}
long long ans(long long a,long long b)
{
    if(b<2)
        return 0;
    if(a<2)
        a=2;
    for(long long i=0; i<=b-a+1; i++)
        check[i]=0;
    for(long long i=0;(long long) v[i]*v[i]<=b&&i<v.size(); i++)
    {
        long long j=a/v[i];
        if(a%v[i]!=0)j++;
        j*=v[i];
        if(j==v[i])j+=v[i];
        for(; j<=b; j+=v[i])
            check[j-a]=1;
    }
    long long cnt=0;
    for(long long i=0; i<b-a+1; i++)
        if(check[i]==0)cnt++;
    return cnt;
}
int main()
{
    sieve();

    long long t,cs=1;
    cin>>t;
    while(t--)
    {
      long long a,b;
        cin>>a>>b;
        cout<<"Case "<<cs++<<": "<<ans(a,b)<<"\n";
    }
}
