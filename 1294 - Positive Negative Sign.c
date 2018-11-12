#include<stdio.h>
int main()
{
    int t,i,j;
    long long int n,m,sum;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&m);
        sum=(n*m)/2;
        printf("Case %d: %llu\n",i,sum);
    }
    return 0;
}
