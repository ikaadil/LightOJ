#include <bits/stdc++.h>

#define pii pair <int,int>
#define sc scanf
#define pf printf
#define Pi 2*acos(0.0)
#define ms(a,b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define MP make_pair
#define oo 1<<29
#define dd double
#define ll long long
#define EPS 10E-10
#define ff first
#define ss second
#define MAX 10000
#define SZ(a) (int)a.size()
#define getint(a) scanf("%d",&a)
#define loop(i,n) for(int i=0;i<n;i++)
#define TEST_CASE(t) for(int z=1;z<=t;z++)
#define PRINT_CASE printf("Case %d: ",z)
#define all(a) a.begin(),a.end()
#define intlim 2147483648
#define inf 1000000
#define rtintlim 46340
#define llim 9223372036854775808
#define rtllim 3037000499
#define ull unsigned long long
#define I int

using namespace std;
int ara[30050];
int n;
ll histogram()
{
    stack<int>st;
    ll ans=0;
    int i=0;
    while(i<n)
    {
        if(st.empty() || ara[st.top()]<=ara[i])
           {
              cout<<"if "<<i<<"\n";
            st.push(i++);
           }
        else
        {
            int top=st.top();
            st.pop();
            cout<<i<<" "<<top<<endl;
            ll top_area=ara[top]*(st.empty()?i:i-st.top()-1);
            ans=max(ans,top_area);
        }
        cout<<"bahire"<<i<<endl;
    }
    while(!st.empty())
    {
        int top=st.top();
        st.pop();
        ll top_area=ara[top]*(st.empty()?i:i-st.top()-1);
        ans=max(ans,top_area);
    }
    return ans;
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    getint(t);
    TEST_CASE(t)
    {

        getint(n);
        loop(i,n)
        sc("%d",&ara[i]);
        PRINT_CASE;
        pf("%lld\n",histogram());
    }
    return 0;
}
