#include<bits/stdc++.h>
using namespace std;
int n;
int ara[101];
int s1[101],s2[101];
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>ara[i];
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
    for(int i=0;i<n;i++)
    {
        if(i==0)
            s1[i]=ara[i];
        else
            s1[i]=s1[i-1]+ara[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
            s2[i]=ara[i];
        else
            s2[i]=s2[i+1]+ara[i];
    }
    int mn=-12345678;
    for(int i=0;i<n;i++)
        mn=max(mn,max(s1[i],s2[i]));
        cout<<"Case "<<cs++<<": "<<mn<<endl;;
//        cout<<ans<<endl;
    }
}
