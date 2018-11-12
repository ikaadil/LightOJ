#include<bits/stdc++.h>
using namespace std;
#define n 1000001
double ara[n];
int main()
{
   for(int i=1;i<=n;i++)
   {
       ara[i]=ara[i-1]+log(i+0.0);
   }
   int t,cs=1;
   scanf("%d",&t);
   while(t--)
   {
       int ne,m;
       scanf("%d %d",&ne,&m);
       double k=(floor)(ara[ne]/log(m+0.0))+1;
       printf("Case %d: %.0f\n",cs++,k);
   }
}
