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
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
char s[25][25];
int dp[16][1 << 16];
int g;
vector<pii>v(16);
int getdis(int i,int j)
{
    return max(abs(v[i].ff-v[j].ff),abs(v[i].ss-v[j].ss));
}
int f(int p,int s)
{
    if(dp[p][s]!=-1)
        return dp[p][s];
    if(p==0&&s==(1<<g)-1)
        return 0;
    int ret=123456789;
    for(int i=0; i<g; i++)
    {
        if(check(s,i)==1)
            continue;
        ret=min(ret,f(i,Set(s,i))+getdis(p,i));
    }
    return dp[p][s]=ret;
}

int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        g=1;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>s[i][j];
                if(s[i][j]=='x')
                {
                    v[0].ff=i;
                    v[0].ss=j;
                }
                else if(s[i][j]=='g')
                {
                    v[g].ff=i;
                    v[g].ss=j;
                    g++;
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0);
        cout<<"Case "<<cs++<<": "<<ans<<"\n";
    }
}

