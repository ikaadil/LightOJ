#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int m,n;
        cin>>n>>m;
        int ara[n];
        for(int j=0; j<n; j++)
            cin>>ara[j];
        for(int j=1; j<=m; j++)
        {
            char c;
            cin>>c;
            if(c=='S')
            {
                int d;
                cin>>d;
                for(int k=0; k<n; k++)
                    ara[k]=ara[k]+d;
            }
            if(c=='M')
            {
                int d;
                cin>>d;
                for(int k=0; k<n; k++)
                    ara[k]=ara[k]*d;
            }
            if(c=='D')
            {
                int d;
                cin>>d;
                for(int k=0; k<n; k++)
                    ara[k]=ara[k]/d;
            }
            if(c=='P')
            {
                int y,z,temp;
                cin>>y>>z;
                temp=ara[y];
                ara[y]=ara[z];
                ara[z]=temp;
            }
            if(c=='R')
            {
                for (int i = 0, j = n-1; i < j; i++, j--)
                    swap(ara[i], ara[j]);
            }
        }
        cout<<"Case"<<" "<<i<<":"<<endl;
        for(int k=0; k<n; k++)
        {
            cout<<ara[k];
            if(k!=n-1) cout<<" ";
            else
            cout<<endl;
        }
    }
}
