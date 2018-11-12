#include<bits/stdc++.h>
using namespace std;
vector<int>ara[100001];
int vs[100001];
int ans;
void bfs()
{
    for(int i=0;i<100001;i++)
        vs[i]=0;
    for(int i=0; i<100001; i++)
    {
        if(ara[i].size()>0&&vs[i]==0)
        {
            int h=1,l=0;
            queue<int>q;
            q.push(i);
            vs[i]=1;
            int u=i;
            while(!q.empty())
            {
                for(int i=0; i<ara[u].size(); i++)
                {
                    int v=ara[u][i];
                    if(vs[v]==0)
                    {
                        vs[v]=vs[u]+1;
                        q.push(v);
                    }
                    else
                        continue;
                    if(vs[v]%2==0)l++;
                    else h++;
                }
                q.pop();
                u=q.front();
            }

                if(h>l)
                    ans+=h;
                else
                    ans+=l;


        }
    }
//    return ans;
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int u,v;
            cin>>u>>v;
            ara[u].push_back(v);
            ara[v].push_back(u);
        }
            bfs();
            cout<<"Case "<<cs++<<": "<<ans<<"\n";
            ans=0;

        for(int i=0; i<100001; i++)
            ara[i].clear();

    }


}
