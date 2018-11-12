#include<bits/stdc++.h>
using namespace std;
long long int n=1e8+1;
int  ara[1000000000/32];
vector<long long>v;
unsigned dp[5761455+3];
bool c(long long int n,long long int pos)
{
    return (bool)(n&(1<<pos));
}
long long int s(long long int n,long long int pos)
{
    return n=n | (1<<pos);
}
int sieve()
{
    for(long long int i=3; i*i<=n; i+=2)
    {
        if(c(ara[i/32],i%32)==0)
        {
            for(long long int j=i*i; j<=n; j+=2*i)
            {
                ara[j/32]=s(ara[j/32],j%32);
            }
        }
    }
    v.push_back(2);
    for(long long int i=3; i<n; i+=2)
    {
        if(c(ara[i/32],i%32)==0)
            v.push_back(i);

    }
}
long long solve(long long  n)
{
    long long ans=1;
    long long  n1=n;
    for(int i=0;v[i]*v[i]<=n1;i++)
    {
       if(n1%v[i]==0)
       {
           n1=n1/v[i];
           while(n1%v[i]==0)
           {
               ans*=v[i];
               n1/=v[i];
           }
       }
    }
    long long p;
    p = upper_bound(v.begin(),v.end(),n);
}
int main()
{
    sieve();
//    cout<<v.size();
    dp[0]=2;
    for(int i=1; i<v.size(); i++)
        dp[i]=dp[i-1]*v[i];
//    cout<<dp[v.size()-1];
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        cout<<"Case "<<cs++<<": "<<solve(n)<<"\n";
    }

}
