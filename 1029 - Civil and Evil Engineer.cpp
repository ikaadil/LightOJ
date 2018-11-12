#include<bits/stdc++.h>
using  namespace std;
int d[101];
vector< pair<int,int> p[101];
#define pii pair<int,int>
int bfs(int x)
{
    priority_queue<pii,vector<pii>,greater<pi >q;
    q.push(x);
    d[x]=0;
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        for(int i=0; i<ve[u].size(); i++)
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
        int u,v,w;
        while(cin>>u>>v>>w)
        {
            if(u==0&&v==0&&w==0)
                break;
            ve[u].push_back(make_pair(w,v));
            ve[v].push_back(make_pair(w,u));
        }
        for(int i=0; i<=n; i++)
            d[i]=12345678;
        bfs(0);
    }
}
