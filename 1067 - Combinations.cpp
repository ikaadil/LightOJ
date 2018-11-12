#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int mod=1000003;
long long bigmod(long long n,long long p,long long m)
{
    if(p==0)
        return 1;
    else if(p%2==0)
    {
        long long r=bigmod(n,p/2,m);
        return ((r%m)*(r%m))%m;
    }
    else
        return ((n%m)*(bigmod(n,p-1,m)%m))%m;
}

int main()
{
    a[1]=1;
    for(int i=2; i<1000001; i++)
        a[i]=(i*a[i-1])%mod;
//        cout<<a[1000000];
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        if(r>n)
        {
             printf("Case %d: 0\n",cs++);
        }
        else if(n==r||r==0)
        {
            printf("Case %d: 1\n",cs++);
        }
        else
        {
            long long s=(a[n-r]*a[r])%mod;
            s=bigmod(s,mod-2,mod);
            printf("Case %d: %d\n",cs++,(a[n]*s)%mod);
        }
    }

}
