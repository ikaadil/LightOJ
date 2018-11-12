#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,p,q,cnt=0,sum=0;
        cin>>n>>p>>q;
        while(n--)
        {
            int w;
            cin>>w;
            if(cnt<p&&sum+w<=q)
            {
                cnt++;
                sum+=w;
            }
        }
        cout<<"Case"<<" "<<i<<":"<<" "<<cnt<<endl;
    }
    return 0;
}
