#include<bits/stdc++.h>
using namespace std;
long long int  bigmod ( long long a, int p, int m )
{
    if ( p == 0 )return 1;

    if ( p % 2 )
    {
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m;
    }
    else
    {
        long long c = bigmod ( a, p / 2, m );
        return ( (c%m) * (c%m) ) % m;
    }
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        long long int n,k,m,g=1;
        cin>>n>>k>>m;
        long long sum=0;
        for(int i=0; i<n; i++)
        {
           long long  int x;
            cin>>x;
            sum+=x;
            sum=sum%m;
        }

        long long a=((bigmod(n,k-1,m)%m)*(k%m))%m;
        long long ans=((a%m)*(sum%m))%m;

        cout<<"Case "<<cs++<<": "<<ans<<"\n";
    }
}
