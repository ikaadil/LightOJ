#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
#define n 500
int ara[n];
vector<int>v;
vector<int>fc[1001];
int ans;
bool vs[1001];
int cnt[1001];
void sieve()
{
    ara[0]=ara[1]=1;
    for(int i=2; i<n; i++)
    {
        if(ara[i]==0)
        {
            for(int j=i*2; j<n; j+=i)ara[j]=1;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(ara[i]==0)v.push_back(i);
    }
}
void _fac()
{
    for(int i=0; i<v.size(); i++)
        for(int j=2; j*v[i]<=1000; j++)
            fc[j*v[i]].push_back(v[i]);
}
int bfs(int x,int y)
{
    for(int i=0; i<1001; i++)
    {
        vs[i]=0;
        cnt[i]=0;
    }
    cnt[x]=0;
    vs[x]=true;
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
        int u=q.front();
        if(u==y)
        {
            ans=cnt[u];
            return ans;
        }
        q.pop();
        for(int i=0; i<fc[u].size(); i++)
        {
            int v=u+fc[u][i];
            if(vs[v]==0&&v<=y)
            {
                vs[v]=1;
                cnt[v]=cnt[u]+1;

                if(v==y)
                {
//                    cout<<cnt[v]<<endl;
                    ans=cnt[v];
                    return ans;
                }
                q.push(v);
            }
        }
    }
    ans=-1;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    sieve();
    _fac();
////    for(int i=0;i<10;i++)
////    {
////        for(int j=0;j<1;j++)
//            cout<<fc[4][0]<<" ";
//        cout<<endl;
////    }
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        ans=0;
//        int g=bfs(x,y);
//        if(g)
            cout<<"Case "<<cs++<<": "<<bfs(x,y)<<"\n";
    }

}

