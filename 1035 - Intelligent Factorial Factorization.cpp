#include<bits/stdc++.h>
using namespace std;
#define n 101
int ara[n+1];
int prime[n+1];
int k=0;
int a[101][101];
void sieve()
{
    int i,j;
    ara[0]=1;
    ara[1]=1;
    for(i=4; i<=n; i+=2)
        ara[i]=1;
    for(i=3; i*i<=n; i++)
    {
        if(ara[i]==0)
        {
            for(j=i*i; j<=n; j+=2*i)
                ara[j]=1;
        }
    }
    for(i=0; i<=n; i++)
    {
        if(ara[i]==0)
            prime[k++]=i;
    }

}
int main()
{
    sieve();
//    for(int i=0;i<=10;i++)
//        cout<<prime[i]<<" ";
    for(int i=2;  i<=100; i++)
    {
        for(int j=0; prime[j]<=i; j++)
        {
            int cnt=0;
            int num=i;
            if(num%prime[j]==0)
            {
                while(num%prime[j]==0)
                {
                    cnt++;
                    num/=prime[j];
                }
//                if(num>1)
//                    a[i][num]++;
                a[i][prime[j]]+=cnt;
                cnt=0;
            }
        }

    }
    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=100; j++)
            a[i][j]+=a[i-1][j];
    }
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int number,flag=0;
        cin>>number;
        cout<<"Case "<<cs++<<": "<<number<<" = ";
        for(int i=0; i<=number; i++)
        {
            if(a[number][i])
            {
                if(flag==1)
                    cout<<" * ";
                cout<<""<<i<<" ("<<a[number][i]<<")";
                flag=1;

            }
        }
        cout<<endl;
    }
    return 0;
}



