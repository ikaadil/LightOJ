#include<bits/stdc++.h>
using namespace std;
bool l[123],r[123];
int lft,rgt;
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
        lft=rgt=0;
        int n;
        cin>>n;
        while(n--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if(!l[a]&&!r[b])
            {
                lft+=c;
                l[a]=1;
                r[b]=1;

            }
            else
            {
                r[a]=l[b]=1;
                rgt+=c;
            }
        }

        cout<<"Case "<<cs++<<": "<<min(lft,rgt)<<"\n";

    }
    return 0;
}
