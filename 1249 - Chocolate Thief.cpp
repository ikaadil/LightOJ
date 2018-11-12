#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n;
        cin>>n;
        string s[n],ans,check;
        int a[n],l,w,h;
        int mini=1e9,maxi=0;
        for(int i=0; i<n; i++)
        {
            cin>>s[i]>>l>>w>>h;
            a[i]=l*w*h;
            if(mini>a[i])
            {
                mini=a[i];
                check=s[i];
            }
            if(a[i]>maxi)
            {
                maxi=a[i];
                ans=s[i];
            }
        }
        if(maxi==mini)
            cout<<"Case"<<" "<<i<<":"<<" "<<"no thief\n";
        else
            cout<<"Case"<<" "<<i<<":"<<" "<<ans<<" "<<"took chocolate from "<<check<<"\n";

    }
    return 0;
}
