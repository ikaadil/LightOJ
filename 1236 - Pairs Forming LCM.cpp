//pairs of LCM
#include<bits/stdc++.h>
using namespace std;
#define n 10000000
bool ara[n+1];
vector<int>v;
void sieve()
{
    ara[0]=ara[1]=1;
    for(int i=2; i<=n; i++)
    {
        if(ara[i]==0)
        {
            for(int j=i*2; j<=n; j+=i)ara[j]=1;
        }
    }
    for(int i=0; i<=n; i++)
    {
        if(ara[i]==0)v.push_back(i);
    }
}
int main()
{
    sieve();
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        long long num,ans=1;
        scanf("%lld",&num);

        for(int i=0; v[i]*v[i]<=num&&i<v.size(); i++)
        {
            if(num%v[i]==0)
            {
                int cnt=0;
                while(num%v[i]==0)
                {
                    cnt++;
                    num/=v[i];
                }

                ans*=(2*cnt+1);
            }
        }
        if(num!=1)
            ans*=3;
        ans++;

        printf("Case %d: %lld\n",cs++,ans/2);
    }
    return 0;

}

