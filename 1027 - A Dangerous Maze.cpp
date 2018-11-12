#include<bits/stdc++.h>
using namespace std;
int ara[1001];
vector<int>v;
void sieve()
{
    ara[0]=ara[1]=1;
    for(int i=2; i<1001; i++)
    {
        if(ara[i]==0)
        {
            for(int j=i*2; j<1001; j+=i)ara[j]=1;
        }
    }
    for(int i=0; i<1001; i++)
    {
        if(ara[i]==0)v.push_back(i);
    }
}
int main()
{
    sieve();
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,sum=0,cnt=0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
            if(a<0)
                cnt++;
            sum+=abs(a);
        }
        if(cnt==n)
            cout<<"Case "<<cs++<<": inf\n";
        else
        {
            cnt=n-cnt;
            for(int i=0;v[i]*v[i]<=max(sum,cnt);i++)
            {
                while(sum%v[i]==0&&cnt%v[i]==0)
                {
                   sum/=v[i] ;
                   cnt/=v[i];
                }
            }

            cout<<"Case "<<cs++<<": "<<sum<<"/"<<cnt<<"\n";
        }
    }
}
