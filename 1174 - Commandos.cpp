#include<bits/stdc++.h>
using namespace std;
vector<int> v[101];
int d1[101],d2[101];
bool v1[101],v2[101];
void bfs1(int x)
{
    queue<int>q;
    d1[x]=0;
    q.push(x);
    v1[x]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<v[u].size(); i++)
        {
            if(v1[v[u][i]]==0)
            {
                v1[v[u][i]]=1;
                d1[v[u][i]]=d1[u]+1;
                q.push(v[u][i]);
            }
        }
    }
}
void bfs2(int x)
{
    queue<int>q;
    d2[x]=0;
    q.push(x);
     v2[x]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<v[u].size(); i++)
        {
             if(v2[v[u][i]]==0)
            {
                v2[v[u][i]]=1;
                d2[v[u][i]]=d2[u]+1;
                q.push(v[u][i]);
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
        for(int i=0; i<101; i++)
        {
            d1[i]=0;
            d2[i]=0;
            v[i].clear();
            v1[i]=0;
            v2[i]=0;
        }
        int n;
        cin>>n;
        int r;
        cin>>r;
        for(int i=0; i<r; i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int s,d;
        cin>>s>>d;
        bfs1(s);
        bfs2(d);
        int mx=0;
        for(int i=0; i<n; i++)
        {
            mx=max(mx,d1[i]+d2[i]);
//            cout<<d1[i]<<" "<<d2[i]<<endl;
        }
        cout<<"Case "<<cs++<<": "<<mx<<"\n";
    }
}
