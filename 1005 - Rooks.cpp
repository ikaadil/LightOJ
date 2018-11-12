#include<bits/stdc++.h>
using namespace std;
#define N 31
long long int dp[N][N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<N;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=i;j++)
            dp[i][j]=dp[i-1][j-1]*i*i/j;
    }
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cout<<"Case "<<cs++<<": "<<dp[n][k]<<"\n";
    }
}
