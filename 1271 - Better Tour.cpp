#include <bits/stdc++.h>

using namespace std;
#define inf             0x3f3f3f3f
#define INF             2e18
#define eps             1e-9

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
#define fRead           freopen("input.txt","r",stdin)
#define fWrite          freopen("output.txt","w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define PI              acos(-1.0)
#define pb              push_back
#define mk              make_pair
#define pii             pair<int,int>
#define pLL             pair<LL,LL>
#define ff              first
#define ss              second
#define all(a)          a.begin(),a.end()
#define SQR(a)          ((a)*(a))
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define vi              vector <int>
#define vL              vector <LL>
#define LB(a,x)         (lower_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which does not compare less than val.
#define UB(a,x)         (upper_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which compares greater than val.
#define prec(n)         fixed << setprecision(n)

#define MEM(a,x)        memset(a,x,sizeof(a))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define IT(it,x)	    for(it=x.begin();it!=x.end();it++)
vector<int>v[50090];
bool vs[50090];
int par[50090];
int ara[50090];
void bfs()
{
    queue<int>q;
    q.push(ara[0]);
    vs[ara[0]]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<v[u].size(); i++)
        {
            int x=v[u][i];
            if(vs[x]==0)
            {
                par[x]=u;
                vs[x]=1;
                q.push(x);
            }
        }
    }


}
vector<int>ans;
void print(int x)
{
    if(par[x]==x)
        ans.pb(x);
    else
    {
        print(par[x]);
        ans.pb(x);
    }
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        ans.clear();
        for(int i=0; i<=50001; i++)
        {
            v[i].clear();
            vs[i]=0;
        }
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>ara[i];
        for(int i=0; i<n-1; i++)
        {
            v[ara[i]].pb(ara[i+1]);
            v[ara[i+1]].pb(ara[i]);
        }
        for(int i=1; i<=50001; i++)
        {
            sort(all(v[i]));
            par[i]=i;
        }
        bfs();
//        for(int i=1;i<10;i++)
//            cout<<par[i]<<" ";
//        cout<<"\n";
//        cout<<ara[n-1]<<"\n";
        print(ara[n-1]);
        cout<<"Case "<<cs++<<":\n";
        for(int i=0; i<ans.size(); i++)
        {
            if(i!=ans.size()-1)
            cout<<ans[i]<<" ";
            else
                cout<<ans[i];
        }
        cout<<"\n";
    }
}
