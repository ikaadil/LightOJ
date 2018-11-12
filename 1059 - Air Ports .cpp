#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge
{
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
} e[100001];
int pr[ 10001];
int find(int r)
{
    return (pr[r] == r) ? r : find(pr[r]);
}
int mst(int n)
{
    sort(e, e+m);
    for (int i = 1; i <= n; i++)
        pr[i] = i;

    int count = 0, s = 0;
    for (int i = 0; i <m; i++)
    {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v)
        {
            pr[u] = v;
            count++;
            s += e[i].w;
            if (count == n - 1)
                break;
        }
    }
    return s;
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        int cnt=0;
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            e[i].u=u;
            e[i].v=v;
            if(w<k)
                e[i].w=w;
            else
            {
                e[i].w=0;
                e[i].v=u;
            }
        }
        int ans=mst(n);
        set<int>s;
        for(int i=1; i<=n; i++)
           {
//             cout<<find(pr[i])<<endl;
            s.insert(find(pr[i]));
           }
//        cout<<s.size()<<endl;
        cout<<"Case "<<cs++<<": "<<ans+(s.size())*k<<" "<<s.size()<<"\n";
    }
}
