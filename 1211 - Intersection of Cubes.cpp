#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n;
        cin>>n;
        int xlow=0,ylow=0,zlow=0,xhigh=1001,yhigh=1001,zhigh=1001;
        int x1,y1,z1,x2,y2,z2;
        for(int i=0; i<n; i++)
        {
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            xlow=max(xlow,x1);
            ylow=max(ylow,y1);
            zlow=max(zlow,z1);
            xhigh=min(xhigh,x2);
            yhigh=min(yhigh,y2);
            zhigh=min(zhigh,z2);
        }
        long long int ans=(xhigh-xlow)*(yhigh-ylow)*(zhigh-zlow);
        if(ans<0)
            ans=0;
        cout<<"Case "<<i<<":"<<" "<<ans<<endl;
    }
    return 0;
}
