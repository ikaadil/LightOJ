#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long ans=0;
        for(int i=2;i*i<=n;i++)
        {
            long long a=i,b=n/i;
            ans+=((b+1)*b)/2-(a*(a-1))/2+a*(b-a);
        }
        cout<<"Case "<<cs++<<": "<<ans<<"\n";
    }

}
