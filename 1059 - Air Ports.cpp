#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> > v[10001];
int vs[10001];
long long int ans;
#define pii pair<int,int>
void mst(int b)
{
//    vs[1]=1;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    q.push(make_pair(0,b));
    while(!q.empty())
    {
        int x;
        x=q.top().second;
        if(vs[x]==1)
        {
            q.pop();
            continue;
        }
        vs[x]=1;
        ans+=q.top().first;
        q.pop();
        for(int i=0; i<v[x].size(); i++)
        {
            int y=v[x][i].second;
            if(vs[y]==0)
            {
//                vs[y]=1;
                q.push(v[x][i]);
//                ans+=v[x][i].first;
            }
        }
    }
}
int main()
{
//    freopen("output.txt","w",stdout);
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m>>ans;
        for(int i=0;i<=n;i++)
        {
            v[i].clear();
            vs[i]=0;
        }
        while(m--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back(make_pair(c,b));
            v[b].push_back(make_pair(c,a));
        }
        for(int i=1; i<=n; i++)
        {
            if(vs[i]==0)
            {
              mst(i);
            }
        }
        cout<<ans<<endl;

    }
}

