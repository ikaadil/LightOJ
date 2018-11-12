#include<bits/stdc++.h>
using namespace std;
int a[220][220];
int dp[220][220];
int n;
void solve()
{
    dp[0][0]=a[0][0];
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
        }
    }
    for(int i=n; i<2*n-1; i++)
    {
        for(int j=0; j<2*n-1-i; j++)
        {
            dp[i][j]+=max(dp[i-1][j+1],dp[i-1][j])+a[i][j];

        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        for(int i=0; i<201; i++)
        {
            for(int j=0; j<201; j++)
            {
                a[i][j]=0;
                dp[i][j]=0;
            }
        }

        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=n; i<2*n-1; i++)
        {
            for(int j=0; j<2*n-1-i; j++)
            {
                cin>>a[i][j];
            }
        }
        solve();
        cout<<"Case "<<cs++<<": "<<dp[2*n-2][0]<<"\n";
//          for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<=i; j++)
//            {
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
//        for(int i=n; i<2*n-1; i++)
//        {
//            for(int j=0; j<2*n-1-i; j++)
//            {
//                 cout<<dp[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
    }
}
