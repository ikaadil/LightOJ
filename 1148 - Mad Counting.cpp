#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        int ara[n];
        int mp[n];
        for(int i=0; i<n; i++)
        {
            cin>>ara[i];
            mp[i]=0;
        }
        set<int>s;
        for(int i=0; i<n; i++)
        {
            int cnt=0;
            for(int j=0; j<n; j++)
            {
                if(ara[i]==ara[j])
                    cnt++;
            }
            mp[i]=cnt;
            s.insert(ara[i]);

        }
        set<int>::iterator i;
        for( i=s.begin(); i!=s.end(); i++)
        {
            for(int j=0; j<n; j++)
            {
                if(*i==ara[j])
                {
//                    if(ara[j]>=mp[j])
//                        ans+=ara[j]+1;
//                    else
//                        ans+=mp[j];
                    while(mp[j]>0)
                    {
                        mp[j]-=ara[j]+1;
                        ans+=ara[j]+1;
                    }
                    break;
                }
            }
        }
        cout<<"Case "<<cs++<<": "<<ans<<"\n";
    }
}
