#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        bool flag=0;
        printf("Case %d: ",cs++);
        for(int i=9;i>=0;i--)
        {
            if((n-i)%9==0)
            {
                if(flag)
                    printf(" ");
                flag=1;
                printf("%llu",(unsigned long long) n+(n-i)/9);

            }
        }
        printf("\n");
    }
}
