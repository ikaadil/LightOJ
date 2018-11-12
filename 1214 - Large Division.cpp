#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       string a;
       cin>>a;
       long int b;
       cin>>b;
       int j;
       if(a[0]=='-')j=1;
       else j=0;
       int l;
       long long int d=0,r=0;
       l=a.length();
       for(j;j<l;j++)
       {
           d+=(a[j]-'0');
           r=d%b;
           d=r*10;
       }
       if(d)cout<<"Case"<<" "<<i<<":"<<" "<<"not divisible"<<endl;
       else cout<<"Case"<<" "<<i<<":"<<" "<<"divisible"<<endl;

    }
    return 0;
}
