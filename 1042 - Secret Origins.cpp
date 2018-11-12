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
LL f(vector<bool>v)
{
    LL a=0;
    LL p=1;
    for(int i=0; i<v.size(); i++)
    {
//        cout<<v[i];
        a=a+v[i]*p;
        p*=2;
    }
//    cout<<endl;
    return a;
}

int main()
{
    FastRead;
//    fWrite;
    int n;
    int t;
    cin>>t;
    int cs=1;
    while(t--)
    {
        cin>>n;
        int p=n;
        cout<<"Case "<<cs++<<": ";
        vector<bool>v;
        while(n)
        {
            v.pb(n%2);
            n=n/2;
        }
        int cnt=0;
        for(int i=v.size()-1; i>=0; i--)
        {
//            cout<<v[i];
            if(v[i]==1)
                cnt++;
        }
        if(cnt==1)
        {
            reverse(all(v));
            v.pb(0);
            reverse(all(v));
            cout<<f(v);
        }
        else if(cnt==v.size())
        {
            v.pb(0);
            swap(v[v.size()-1],v[v.size()-2]);
//            for(int i=v.size()-1; i>=0; i--)
//                cout<<v[i];
            cout<<f(v);
        }
        else
        {
            int g=0;
            int i;
            int c=0;
//            for(int i=v.size()-1; i>=0; i--)cout<<v[i];
//                cout<<endl;
            for( i=0; i<v.size()-1; i++)
            {
                if(v[i]==1&&v[i+1]==0)
                {
                    swap(v[i],v[i+1]);
                    g=1;
                    break;

                }
                if(v[i]==1)
                    c++;
            }

            if(g)
            {
//                cout<<c<<"  ekhane\n";
//
//                for(int i=v.size()-1; i>=0; i--)cout<<v[i];
//                cout<<endl;
                for(int j=0; j<i; j++)
                {
                    if(v[j]==0&&c)
                    {
                        v[j]=1;
                        c--;
                    }
                    else if(v[j]==1&&c)
                        c--;
                    else if(c==0&&v[j]==1)
                    {
                        v[j]=0;
                    }
                }
                cout<<f(v);
            }
            else
            {
//                for(int i=0; i<v.size(); i++)
//                {
//                    if(v[i]==1)
//                    {
//                        v[i]=0;
//                        break;
//                    }
//                }
                reverse(all(v));
                v.pb(0);
                reverse(all(v));
//                v.pb(0);
                int c=0;

//                for(int i=v.size()-1; i>=0; i--)cout<<v[i];
//                cout<<endl;

                for(int i=v.size()-2; i>=0; i--)
                {
                    if(v[i]==1)
                        c++;
                }
//                cout<<"..."<<c<<endl;
                for(int j=0; j<v.size()-1; j++)
                {
                    if(v[j]==0&&c)
                    {
                        v[j]=1;
                        c--;
                    }
                    else if(v[i]==1&&c)
                        c--;
                    else if(c==0&&v[j]==1)
                    {
                        v[j]=0;
                    }
                }
//
//                for(int i=v.size()-1; i>=0; i--)cout<<v[i];
//                cout<<endl;

                cout<<f(v);
//                if(f(v)==511)
//                    cout<<endl<<p<<"........\n";
            }
        }
        cout<<"\n";


    }
}
