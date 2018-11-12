#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,ans,a;
        scanf("%d %d",&n,&m);
        if(n==1||m==1)
            ans=n*m;
        else if(n==2||m==2)
        {
            if(n==2)a=m;
            else a=n;
            if(a%4==3)ans=a+1;
            else if(a%4==2)ans=a+2;
            else if(a%4==1) ans=a+1;
            else if(a%4==0)ans=a;
        }
        else if((m*n)%2==0)ans=(n*m)/2;
        else ans=(n*m)/2+1;
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
