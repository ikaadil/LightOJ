#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int ara[N];
int main()
{
  int t,cs=1;
  cin>>t;
  while(t--)
  {
      long long  n,i;
      cin>>n;
      long long  a=sqrt(n);
      long long sum=0;
      for( i=1;i<=a;i++)
      {
          if(n/i!=i)
          sum+=(n/i)+((n/i)-(n/(i+1)))*i;
          else
            sum+=i;
      }
//      if(a==n/i)
//      sum-=a;
      cout<<"Case "<<cs++<<": "<<sum<<"\n";
  }
}
