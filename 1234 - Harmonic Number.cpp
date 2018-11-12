#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
double ara[N/50+1];
int main()
{
    double x=1.0;
    for(int i=2; i<=N; i++)
    {
        x+=1.0/i;
        if(i%50==0)
            ara[i/50]=x;
    }
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int p=n/50;
        double ans=ara[p];
        for(int i=p*50+1;i<=n;i++)
            ans+=(double)1.0/i;
        printf("Case %d: %.10f\n",cs++,ans);
    }
    return 0;
}
