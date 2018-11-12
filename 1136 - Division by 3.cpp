#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll adu(ll x)
{
    return (x/3)*2+(x%3==2);
}
int main()
{
    ll t,i,a,b,ans=0;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b;
        ans=adu(b)-adu(a-1);
        printf("Case %I64d: %I64d\n",i,ans);
    }
    return 0;

}
