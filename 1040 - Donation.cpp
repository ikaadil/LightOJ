#include<bits/stdc++.h>
using namespace std;
int k,n;
struct edge
{
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
} e[2501];
int pr[101];
int find(int r)
{
    return (pr[r] == r) ? r : find(pr[r]);
}
int mst()
{
    sort(e,e+k);
    for (int i = 0; i <= n; i++)
        pr[i] = i;

    int count = 0, s = 0;
    for (int i = 0; i < k; i++)
    {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v)
        {
            pr[u] = v;
            count++;
            s += e[i].w;
            if (count == n - 1)
                return s;

        }
    }
    return -1;
}
int main()
{
//    freopen("output.txt","w",stdout);
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int sum=0,w;
        k=0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>w;
                sum+=w;
                if(i!=j&&w)
                {
                    e[k].u=i;
                    e[k].v=j;
                    e[k].w=w;
                    k++;
                }
            }
        }
        cout<<"Case "<<cs++<<": ";
        int ans=mst();
        if(n==1)
            cout<<sum<<"\n";
        else if(ans==-1)
            cout<<ans<<"\n";
        else
            cout<<sum-ans<<"\n";
    }
}
