#include<bits/stdc++.h>
using namespace std;
int ara[17][17];
int dp[17][1<<15+2];
int n;
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int f(int g,int mask)
{
    if(g>=n)
        return 0;
    if(dp[g][mask]!=-1)return dp[g][mask];
    int mx=0;
    for(int i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            int ans=ara[g][i]+f(g+1,Set(mask,i));
            mx=max(ans,mx);
        }
    }
    return dp[g][mask]=mx;
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {

        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>ara[i][j];
        }
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<cs++<<": "<<f(0,0)<<endl;
    }
}
