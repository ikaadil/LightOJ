#include<bits/stdc++.h>
using namespace std;
#define n 1000010
//#define FastRead ios_base::sync_with_stdio(0);cin.tie();
int ara[n];
vector<int>prime;
void sieve()
{
    ara[0]=ara[1]=1;
    for(int i=2; i<n; i++)
    {
        if(ara[i]==0)
        {
            for(int j=i*2; j<n; j+=i)ara[j]=1;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(ara[i]==0)prime.push_back(i);
    }
}
int divisor(long long num)
{

    long long int ans=1,cnt=0;
    for(int i=0;i<prime.size()&&prime[i]*prime[i]<=num;i++)
    {
        if(num%prime[i]==0)
        {
            cnt=0;
            while(num%prime[i]==0)
            {
                num/=prime[i];
                cnt++;
            }
            ans*=(cnt+1);
        }
    }
    if(num!=1)
        ans=ans*2;
    return ans;
}
int main()
{

    sieve();
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        long long nu;
        scanf("%lld",&nu);
        printf("Case %d: %lld\n",cs++,divisor(nu)-1);
    }
}

