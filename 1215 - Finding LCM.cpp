#include<bits/stdc++.h>
using namespace std;
#define n 10000000
bool ara[n];
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
int main()
{
    sieve();
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b,l,s;
        scanf("%lld %lld %lld",&a,&b,&l);
        if(l%a||l%b)
        {
                printf("Case %d: impossible\n",cs++);
        }
        else
        {
           long long ans=1;
           for(int i=0;i<prime.size()&&(l>1||a>1||b>1);i++)
           {
               int cnt=0,cnt1=0,cnt2=0;
               while(l%prime[i]==0)
               {
                   cnt++;
                   l/=prime[i];
               }
               while(a%prime[i]==0)
               {
                   cnt1++;
                   a/=prime[i];
               }
               while(b%prime[i]==0)
               {
                   cnt2++;
                   b/=prime[i];
               }
//               cout<<prime[i]<<" "<<cnt<<" "<<cnt1<<" "<<cnt2<<"\n";
//               cout<<l<<" "<<a<<" "<<b<<"\n";
               if(cnt>max(cnt1,cnt2))
               {
                   for(int j=0;j<cnt;j++)
                    ans*=prime[i];
               }
           }
           if(l>1)
            ans*=l;
           printf("Case %d: %lld\n",cs++,ans);
        }
    }
}
