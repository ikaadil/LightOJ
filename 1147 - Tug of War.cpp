#include<bits/stdc++.h>
using namespace std;
int n;
int ara[1001];
long long  c[100000+1];
int f(int s)
{
    for(int i=0;i<=s;i++)
        c[i]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=ara[i];j<=s;j++)
        {
             c[j]=max(c[j],c[j-ara[i]]+ara[i]);
//    cout<<c[j]<<" ";
        }
//        cout<<endl;
    }
    return c[s];
}
int main()
{
//    freopen("output.txt","w",stdout);
    int t,cs=1;
    cin>>t;
    while(t--)
    {
//        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>ara[i];
            sum+=ara[i];
        }
        int ans=f(sum/2);
       cout<<"Case "<<cs++<<": "<<min(sum-ans,ans)<<" "<<max(sum-ans,ans)<<"\n";
    }
}
