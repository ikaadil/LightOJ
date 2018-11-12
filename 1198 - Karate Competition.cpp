#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        bool flag=0;
        int n,p;
        cin>>n;
        memset(dp,0,sizeof(dp));
        int a[n],b[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        int j=0,cnt=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i-1]>b[j-1])
                    p=2;
                else if(a[i-1]==b[j-1])
                    p=1;
                dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+p));

            }
        }
        cout<<"Case "<<cs++<<": "<<dp[n][n]<<"\n";
    }
}
