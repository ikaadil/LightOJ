#include<bits/stdc++.h>
using namespace std;
long long int ara[20];
int main()
{
    ara[0]=1;
    ara[1]=1;
    for(long long int i=2;i<=20;i++)
    {
        ara[i]=ara[i-1]*i;
    }
//     for(int i=1;i<=20;i++)
//    {
//        cout<<ara[i]<<" ";
//    }
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        long long n,fact[20],k=0;
        cin>>n;
        for(int i=19;i>=0&&n>=0;i--)
        {
           if(ara[i]<=n)
           {
               n-=ara[i];
               fact[k++]=i;
           }
        }
        if(n!=0)
        {
            cout<<"Case"<<" "<<i<<":"<<" "<<"impossible";
        }
        else
        {
            cout<<"Case"<<" "<<i<<":"<<" ";
            cout<<fact[k-1]<<"!";

            for(int i=k-2;i>=0;i--)
            {
                cout<<"+"<<fact[i]<<"!";
            }
        }
        cout<<endl;

    }
}
