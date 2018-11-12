#include <bits/stdc++.h>

#define pii             pair <int,int>
#define sc              scanf
#define pf              printf
#define Pi              2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)           push_back(a)
#define MP              make_pair
#define db              double
#define ll              long long
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define D(x)            cout<<#x " = "<<(x)<<endl
#define VI              vector <int>
#define DBG             pf("Hi\n")
#define MOD             100007
#define MAX             10000
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d: ",z)
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long


using namespace std;

const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};

char graph[201][201];
int dj[201][201];
int df[201][201];
bool visit[201][201];

int r,c;
vector<pii>fdata;
pii pointj;

bool testf(pii tmp)
{
    if(tmp.ff<0 || tmp.ff>=r || tmp.ss<0 || tmp.ss>=c || visit[tmp.ff][tmp.ss] || graph[tmp.ff][tmp.ss]!='.')
        return 0;
    return 1;
}

bool testj(pii tmp)
{
    if(tmp.ff<0 || tmp.ff>=r || tmp.ss<0 || tmp.ss>=c || visit[tmp.ff][tmp.ss] || graph[tmp.ff][tmp.ss]!='.')
        return 0;
    return 1;
}

void bfsf()
{
    loop(i,r+1) loop(j,c+1)
    {visit[i][j]=0;df[i][j]=inf;}

    queue<pii>Q;
    pii u,v;
    for(int i=0;i<SZ(fdata);i++)
    {
        u=fdata[i];
        df[u.ff][u.ss]=0;
        Q.push(u);
        visit[u.ff][u.ss]=1;
    }
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        loop(i,4)
        {
            v.ff=u.ff+fx[i];
            v.ss=u.ss+fy[i];
            if(testf(v))
            {
                visit[v.ff][v.ss]=1;
                df[v.ff][v.ss]=df[u.ff][u.ss]+1;
                Q.push(v);
            }
        }
    }
}

int bfsj(pii src)
{
    loop(i,r+1) loop(j,c+1)
       {
         visit[i][j]=0;
         dj[i][j]=inf;
       }
    visit[src.ff][src.ss]=1;
    pii u,v;
    dj[src.ff][src.ss]=0;

    queue<pii>Q;
    Q.push(src);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        if(u.ff==0 || u.ff==r-1 || u.ss==0 || u.ss==c-1)
            return dj[u.ff][u.ss];
        loop(i,4)
        {
            v.ff=u.ff+fx[i];
            v.ss=u.ss+fy[i];
            if(testj(v) && (df[v.ff][v.ss] > dj[u.ff][u.ss]+1))
            {
                visit[v.ff][v.ss]=1;
                dj[v.ff][v.ss]=dj[u.ff][u.ss]+1;
                Q.push(v);
            }
        }
    }
    return -1;
}


int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {
        sff(r,c);
        loop(i,r) loop(j,c)
        {
            cin>>graph[i][j];
            if(graph[i][j]=='J')
                pointj.ff=i,pointj.ss=j;
            else if(graph[i][j]=='F')
                fdata.pb(MP(i,j));
        }

        bfsf();
        int ans=bfsj(pointj);
        PRINT_CASE;
        if(ans==-1)
            pf("IMPOSSIBLE\n");
        else
            pf("%d\n",ans+1);
        fdata.clear();
    }
    return 0;
}
