#include<bits/stdc++.h>
using namespace std;
#define inf 12345678
int a[110][110];
int d[110];
bool v[110];
int n;
void dijktra(int i)
{
    for(int i=1;i<=n;i++)
        d[i]=a[1][i];

        for(int i=1;i<=n;i++)
        {
            int mn=inf,p;
            for(int i=1;i<=n;i++)
            {
                if(d[i]<mn&&v[i]==0)
                {
                    mn=d[i];
                    p=i;
                }
            }
            v[p]=1;
            for(int i=1;i<=n;i++)
            {
                if(d[i]>d[p]+a[p][i]&&v[i]==0)
                    d[i]=d[p]+a[p][i];
            }
        }
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<110;i++)
        {
            d[i]=0;
            v[i]=0;
            for(int j=0;j<110;j++)
            {
                if(i==j)
                    a[i][j]=0;
                else
                    a[i][j]=inf;
            }
        }
        int m,r;
        cin>>n>>m>>r;
        while(m--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            a[u][v]=min(w,a[u][v]);
            a[v][u]=min(w,a[v][u]);
        }
        dijktra(r);
        if(d[n]==inf)
        {
            cout<<"Case "<<cs++<<": Impossible\n";
        }
        else
            cout<<"Case "<<cs++<<": "<<d[n]<<"\n";
    }
}
