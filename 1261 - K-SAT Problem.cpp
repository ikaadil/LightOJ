#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>v[32];
        int ma[32];
        for(int i=0; i<32; i++)
        {
            v[i].clear();
            ma[i]=0;
        }
        for(int j=0; j<n; j++)
        {
            for(int p=0; p<k; p++)
            {
                int x;
                cin>>x;
                v[j].push_back(x);
            }
        }
        int p;
        cin>>p;
        int b[p];
        for(int j=0; j<p; j++)
        {
            cin>>b[j];
            ma[b[j]]=1;
        }
        bool f=0,g=0;
        for(int j=0; j<n; j++)
        {
            g=0;
            for(int p=0; p<k; p++)
            {
                if(v[j][p]>0&&ma[v[j][p]]==1)
                    g=1;
                if(v[j][p]<0&&ma[-v[j][p]]==0)
                    g=1;

            }
            if(g==0)
                f=1;
        }
        if(f==1)
        {
            cout<<"Case "<<i<<": "<<"No\n";
        }
        else
            cout<<"Case "<<i<<": "<<"Yes\n";
    }

}
