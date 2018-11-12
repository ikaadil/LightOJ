#include<bits/stdc++.h>
using namespace std;
#define n 5000001
unsigned long long int phi[n];
//long long sum[n];
void euler()
{
    phi[0]=0;
    phi[1]=1;
    for(int i=2; i<n; i++)
    {
        if(phi[i]==0)
        {
            phi[i]=i-1;
            for(int j=2*i; j<n; j+=i)
            {
                if(phi[j]==0)phi[j]=j;
                phi[j]=(phi[j]/i*(i-1));

            }
        }
    }

    for(int i=2; i<n; i++)
        phi[i]=phi[i-1]+phi[i]*phi[i];
}
int main()
{
    euler();
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",cs++,phi[b]-phi[a-1]);
    }
}




