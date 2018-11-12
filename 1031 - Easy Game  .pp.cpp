#include<bits/stdc++.h>
using namespace std;
int n;
int ara[101];
int dp[101][101];
int ans;
int solve(int i,int j)
{
    if(i>j)
        return  0;
    if(i==j)
        return ara[i];
    if(dp[i][j]!=-1)
        return dp[i][j];
    int best=-12345678;
    for(int k=i; k<j; k++)
        best=max(best,solve(k,j));
    for(int k=j; k>=i; k--)
        best=max(best,solve(i,k));
    ans=max(ans,best);
    return dp[i][j]=best;
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>ara[i];
        memset(dp,-1,sizeof(dp));
        solve(0,n-1);
        cout<<ans<<endl;
    }
}
