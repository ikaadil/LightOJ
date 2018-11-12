#include<bits/stdc++.h>
using namespace std;
int d1[300010];
int d2[300010];
bool b[300010];
vector<int>ve[30010];
vector<int>cost[30010];
int x,p;
void bfs1(int k)
{

    queue<int>q;
    q.push(k);
    b[k]=1;
    d1[k]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(d1[u]>x)
        {
            x=d1[u];
            p=u;
        }
        for(int i=0; i<ve[u].size(); i++)
        {
            if(d1[ve[u][i]]==-1)
            {
                d1[ve[u][i]]=d1[u]+cost[u][i];
                q.push(ve[u][i]);
                b[ve[u][i]]=1;
            }
        }
    }
}
void bfs2(int k)
{

    queue<int>q;
    q.push(k);
    b[k]=1;
    d2[k]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<ve[u].size(); i++)
        {
            if(d2[ve[u][i]]==-1)
            {
                d2[ve[u][i]]=d2[u]+cost[u][i];
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
            d2[i]=-1;
            d1[i]=-1;
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
        bfs1(0);
//        cout<<"Case "<<cs++<<": "<<d[p]<<" "<<p<<"\n";
        for(int i=0; i<=n; i++)
            d1[i]=-1;
        x=-1;
        bfs1(p);

//        cout<<endl;

        for(int i=0; i<=n; i++)
        {

            b[i]=0;

        }
        x=-1;
        bfs2(p);
        cout<<"Case "<<cs++<<":\n";

        for(int i=0; i<n; i++)
        {
            cout<<d1[i]<<" "<<d2[i]<<"\n";


        }


    }
}

