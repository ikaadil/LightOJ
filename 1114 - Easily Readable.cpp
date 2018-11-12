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
const int N=100060;
int mp[N][55];
int fre[N];
//int vs[N];
int change(char c)
{
    if(c>='a'&&c<='z')
        return c-'a';
    else
        return c-'A'+26;
}
int id;
void add(string s)
{

    int r=0;
    for(int i=0; i<s.size(); i++)
    {
        int c=change(s[i]);
        if(mp[r][c]==0)
        {
            id++;
            mp[r][c]=id;
        }
        r=mp[r][c];
    }
    fre[r]++;
    //    vs[r]=1;
}
int srch(string s)
{
    int r=0;
    for(int i=0; i<s.size(); i++)
    {
        int c=change(s[i]);

        r=mp[r][c];

    }

    return fre[r];

}
int main()
{
//  char p[10000];
//  gets(p);
//    string s;
//    s=p;
////    getline(cin,s);
//    cout<<s.size()<<endl;
//    for(int i=0;i<s.size();i++)
//    {
//        cout<<(char)tolower(s[i]);
//    }
//    fWrite;
    int t,cs=1;
    int cnt=0;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int n,m;
        cin>>n;
        memset(mp,0,sizeof(mp));
        memset(fre,0,sizeof(fre));
//        memset(vs,0,sizeof(vs));
        id=0;
        while(n--)
        {
            string s;
            cin>>s;
//            cout<<s<<endl;
            if(s.size()>2)
                sort(s.begin()+1,s.end()-1);

//            cout<<s<<endl;
//            if(k==2)
//                cout<<s<<endl;
            add(s);
        }
        cout<<"Case "<<cs++<<":\n";

        scanf("%d ",&m);
//        cin>>m;
//        getchar();
        while(m--)
        {
            char b[1000005];
            gets(b);
            string s=b;
            //              cout<<s<<endl;
            string str="";
            int ans=1;
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]==32)
                {
                    if(str.size()>2)
                    {
                        sort(str.begin()+1,str.end()-1);
//                    cout<<str<<endl;
                        ans=ans*srch(str);
                    }
                    str="";
                }
                else
                {
                    str+=s[i];
                }
            }
            if(str.size()>0)
            {
//                cout<<str<<endl;
                if(str.size()>2)
                    sort(str.begin()+1,str.end()-1);

                ans=ans*srch(str);
            }

            cout<<ans<<"\n";
//            cnt++;
//            if(cnt==90)
//                cout<<"-----------------"<<cs<<endl;
        }
    }
}
