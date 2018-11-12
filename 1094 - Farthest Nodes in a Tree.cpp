#include<bits/stdc++.h>
using namespace std;
int d[300010];
bool b[300010];
vector<int>ve[30010];
vector<int>cost[30010];
int x,p;
void bfs(int k)
{

    queue<int>q;
    q.push(k);
    b[k]=1;
    d[k]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(d[u]>=x)
        {
            x=d[u];
            p=u;
        }
        for(int i=0; i<ve[u].size(); i++)
        {
            if(d[ve[u][i]]<d[u]+cost[u][i]&&b[ve[u][i]]==0)
            {
                d[ve[u][i]]=d[u]+cost[u][i];
                q.push(ve[u][i]);
                b[ve[u][i]]=1;
            }
        }
    }
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<=n; i++)
        {
            d[i]=0;
            b[i]=0;
            ve[i].clear();
            cost[i].clear();
        }
        for(int i=1; i<n; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            ve[u].push_back(v);
            ve[v].push_back(u);
            cost[v].push_back(w);
            cost[u].push_back(w);
        }
        x=-1;
        bfs(0);
       // cout<<"Case "<<cs++<<": "<<d[p]<<" "<<p<<"\n";

        for(int i=0; i<=n; i++)
        {
            d[i]=0;
            b[i]=0;

        }
        x=-1;
        bfs(p);
        cout<<"Case "<<cs++<<": "<<d[p]<<"\n";

//        for(int i=0; i<n-1; i++)
//            cout<<d[i]<<"\n";
//            cout<<x<<"\n";

    }
}
