#include<bits/stdc++.h>
using namespace std;
#define m  100000007
int n,k;
int a[1005];
long long int dp[101][10001];

int call(int i,int s)
{
//    cout<<k<<endl;
//    cout<<i<<" "<<s<<"\n";
    if(s==k)
        return 1;
//        cout<<"jfdh\n";
    if(i==n)
        return 0;
    if(dp[i][s]!=-1)
        return dp[i][s];
    int ans=0;
    for(int j=0;j<=k&&(s+j*a[i])<=k;j++)
        ans+=call(i+1,s+j*a[i])%m;
//        cout<<i<<" "<<s<<" "<<ans<<"\n";

    return dp[i][s]=ans%m;

}
int main()
{
//     freopen("output.txt","w",stdout);
    int t,cs=1;
    cin>>t;
    while(t--)
    {
//       int n,k;
       cin>>n>>k;
//       cout<<k<<endl;
       for(int i=0;i<n;i++)
            cin>>a[i];
//        for(int i=0;i<n;i++)
//            cin>>c[i];
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<cs++<<": "<<call(0,0)<<"\n";
    }
}
