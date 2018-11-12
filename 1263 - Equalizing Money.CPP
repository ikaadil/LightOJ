#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vs[1001];
int ara[1001];
int total,ppl;
void dfs(int u)
{
    vs[u]=1;
    total+=ara[u];
    ppl++;
    for(int i=0; i<adj[u].size(); i++)
    {
        if(vs[adj[u][i]]==0)
            dfs(adj[u][i]);
    }
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int avg=0,sum=0;
        for(int i=0; i<1001; i++)
        {
            adj[i].clear();
            vs[i]=0;
        }
        for(int i=0; i<n; i++)
        {
            cin>>ara[i];
            sum+=ara[i];
        }
        avg=sum/n;
        for(int i=0; i<m; i++)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool flag=0;
        for(int i=0; i<n; i++)
        {
            if(vs[i]==0)
            {
                total=0;
                ppl=0;
                dfs(i);
                if(total%ppl!=0)
                {
                    flag=1;
                    break;
                }
                else if(total/ppl!=avg)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
            cout<<"Case "<<cs++<<": No\n";
        else
            cout<<"Case "<<cs++<<": Yes\n";

    }
}
