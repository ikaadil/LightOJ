#include<bits/stdc++.h>
using namespace std;
bool ara[1000001];
#define ll long long int
#define mod 1000000007
vector<ll>v;
void sieve()
{
    ara[0]=ara[1]=1;
    for(ll i=2; i<1000001; i++)
    {
        if(ara[i]==0)
        {
            for(ll j=i*2; j<1000001; j+=i)ara[j]=1;
        }
    }
    for(ll i=0; i<1000001; i++)
    {
        if(ara[i]==0)v.push_back(i);
    }
}
ll bigmod(ll n,ll p,ll m)
{
    if(p==0)
        return 1;
    else if(p%2==0)
    {
        ll r=bigmod(n,p/2,m);
        return ((r%m)*(r%m))%m;
    }
    else
        return ((n%m)*(bigmod(n,p-1,m)%m))%m;
}
ll sod(ll N,ll M)
{
    ll sum=1,s=1;
    for(ll i=0; v[i]*v[i]<=N&&i<v.size(); i++)
    {

        if(N%v[i]==0)
        {
            int cnt=0;
            while(N%v[i]==0)
            {
                cnt++;
                N/=v[i];
            }
            ll pa=bigmod(v[i],cnt*M+1,mod)-1;
            ll q=bigmod(v[i]-1,mod-2,mod);
            ll s=(pa*q+mod)%mod;
            sum=(sum*s)%mod;

        }
    }
    if(N>1)
    {
        ll pa=bigmod(N,M+1,mod)-1;
        ll q=bigmod(N-1,mod-2,mod);
        ll s=(pa*q+mod)%mod;
        sum=(sum*s)%mod;
    }
    return sum;
}
int main()
{
    sieve();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        ll N,M;
        cin>>N>>M;
        cout<<"Case "<<cs++<<": "<<sod(N,M)<<"\n";
    }

}
