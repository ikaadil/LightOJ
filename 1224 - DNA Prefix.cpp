#include <bits/stdc++.h>

using namespace std;
#define inf             0x3f3f3f3f
#define INF             2e18
#define eps             1e-9

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
#define fRead           freopen("input.txt","r",stdin)
#define fWrite          freopen("output.txt","w",stdout)

#define LL              long long
#define ull            unsigned long long
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
const int N=50001;

LL last,ans;
struct node
{
    int next[4];
    int cnt;
}tree[2500109];
int dx(char c)
{
    if(c=='A')
        return 0;
    else if(c=='C')
        return 1;
    else if(c=='G')
        return 2;
    else return 3;
}
void f(string s)
{
    int cur=0;
    for(int i=0; i<s.size(); i++)
    {
        int id=dx(s[i]);
        if(tree[cur].next[id]==-1)
        {
            tree[cur].next[id]=last;
            for(int i=0; i<4; i++)
                tree[last].next[i]=-1;
            tree[last].cnt=1;
            last++;
            cur=tree[cur].next[id];
        }
        else
        {
            tree[cur].cnt++;
            ans=max(ans,(LL)(i+1)*tree[cur].cnt);
            cur=tree[cur].next[id];
        }
    }
    ans=max(ans,(LL)s.size());
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<4; i++)
            tree[0].next[i]=-1;
        tree[0].cnt=1;
        last=1;
        ans=0;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            f(s);
        }
        cout<<"Case "<<cs++<<": "<<ans<<"\n";
    }

}
