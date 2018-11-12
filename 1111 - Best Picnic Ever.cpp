#include<bits/stdc++.h>
using namespace std;
#define FOR(n,m) for(int i=n;i<m;i++)
int visited[40010],cnt[40010],ans,k,n,m;
vector<int>vc[40010];
int ara[40010][40010];
int  bfs(long long c )
{
    for(int i=0; i<n+1; i++)
        visited[i]=0;
    visited[1]=1;
    queue<int>q;
    q.push(1);
//    cnt[x]++;
//    if(cnt[x]==k)
//        ans++;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        FOR(0,vc[u].size())
        {
            int v=vc[u][i];
            if(!visited[v])
            {
                visited[v]=1;
                q.push(v);
//                cnt[v]++;
                long long we=ara[u][v];
                if(we>=c)
                    ans++;
                else
                    break;

            }
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {


        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            ara[i][j]=0;


        FOR(0,m)
        {
            int u,v,w;
            cin>>u>>v>>w;
            vc[u].push_back(v);
            ara[u][v]=w;
            ara[v][u]=w;
        }
        cin>>k;
        cout<<"cas:";
        while(k--)
        {
            long long c;
            cin>>c;
            bfs(c);
        }
        cout<<"\n";
        FOR(0,n+1)
        {
            vc[i].clear();
//            cnt[i]=0;
        }
    }
}
