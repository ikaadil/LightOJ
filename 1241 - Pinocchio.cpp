#include<bits/stdc++.h>
using namespace std;
int main()
{
//    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,cnt=0;
        scanf("%d",&n);
        int ara[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);
            if(i==0)
            {
                if(ara[i]>2)
                    cnt+=(ara[i]+4-2)/5;

            }
            else
                cnt+=(ara[i]-ara[i-1]+4)/5;
        }
        printf("Case %d: %d\n",cs++,cnt);
    }
}
