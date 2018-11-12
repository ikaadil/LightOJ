#include<bits/stdc++.h>
using namespace std;
int n,m;
int ara[101],c[101];
int dp[100001];
int check[100001];
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
            cin>>ara[i];
        for(int i=0; i<n; i++)
            cin>>c[i];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(dp[j])
                    check[j]=0;
                else
                    check[j]=12345678;
            }
            for(int j=0; j<=m-ara[i]; j++)
            {
                int p=j+ara[i];
                if(!dp[p]&&dp[j]&&check[j]<c[i])
                {
                    dp[p]=1;
                    check[p]=check[j]+1;
                }
            }
        }
        int cnt=0;
        for(int i=1; i<=m; i++)
        {
            if(dp[i])
                cnt++;
        }

        cout<<"Case "<<cs++<<": "<<cnt<<"\n";

    }
}
