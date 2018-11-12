
#include <bits/stdc++.h>

using namespace std;



#define fRead           freopen("input.txt","r",stdin)
#define fWrite          freopen("output.txt","w",stdout)

#define eps             1e-9
#define inf             0x3f3f3f3f
#define INF             2e18
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
#define rall(a)         a.rbegin(),a.rend()
#define SQR(a)          ((a)*(a))
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define Iterator(a)     __typeof__(a.begin())
#define rIterator(a)    __typeof__(a.rbegin())
#define FOR(a,it)       for(Iterator(a) it = a.begin();it != a.end(); it++)
#define rFOR(a,it)      for(rIterator(a) it = a.rbegin();it != a.rend(); it++)
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
#define CasePrint       pc('C'); pc('a'); pc('s'); pc('e'); pc(' '); write(qq++,false); pc(':'); pc(' ')
#define vi              vector <int>
#define vL              vector <LL>
#define For(I,A,B)      for(int I = (A); I  < (B); ++I)
#define rFor(I,A,B)     for(int I = (A); I >= (B); --I)
#define Rep(I,N)        For(I,0,N)
#define REP(I,N)        For(I, 1, N + 1)
#define gti             int, vi, greater<int>
#define gtL             LL, vL, greater<LL>
#define Found(a, b)     a.find(b) != a.end()
#define y0              y00

const int MOD = 1e9 + 7;

int BigMod(int A,int B,int M = MOD)
{
    int ret = 1;
    while(B)
    {
        if(B & 1) ret = (ret * A) % M;
        A = (A * A) % M;
        B = B >> 1;
    }
    return ret;
}



int main()
{
    FastRead;
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        double s=k*1.0*log10(n*1.0);
        s-=floor(s);
        s=pow(10,s)*100;


        int p=BigMod(n%1000,k,1000);
//          printf("Case %d: %03d %03d\n",cs++,(int)s,BigMod(n%1000,k,1000));
        printf("Case %d: %03d %03d\n",cs++,(int)s,p);
//        cout<< "Case "<<cs++<<": "<<setw(3) << setfill('0') <<(int)s<<" "<< setw(3) << setfill('0')<<p<<"\n";
//        printf("%03d %03d\n",s,p);
    }
}
