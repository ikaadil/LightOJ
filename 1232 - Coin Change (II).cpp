#include<bits/stdc++.h>
using namespace std;
#define m  100000007
int a[101];
long long int ans[10001];
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++)
            cin>>a[i];
        memset(ans,0,sizeof(ans));
        ans[0]=1;
        for(int i=0; i<n; i++)
        {
            for(int j=a[i]; j<=k; j++)
            {

                    ans[j]+=ans[j-a[i]];
                    ans[j]%=m;

            }
        }
        for(int i=0;i<=k)
        cout<<"Case "<<cs++<<": "<<ans[k]<<"\n";
    }
}
