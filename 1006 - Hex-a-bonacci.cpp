#include<bits/stdc++.h>
using namespace std;
long long  int ar[10001];
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        long long int a,b,c,d,e,f,n;
        cin>>a>>b>>c>>d>>e>>f>>n;
        ar[0]=a% 10000007,ar[1]=b% 10000007,ar[2]=c% 10000007,ar[3]=d% 10000007,ar[4]=e% 10000007,ar[5]=f% 10000007;
        int sum=0;
        for(int i=6; i<=n; i++)
        {
            ar[i]=(ar[i-1]+ar[i-2]+ar[i-3]+ar[i-4]+ar[i-5]+ar[i-6])% 10000007;
        }
        cout<<"Case "<<cs++<<": "<<ar[n]<<"\n";
    }
}
