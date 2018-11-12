#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,a,n,sum;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        sum=0;
        while(n--)
        {
            cin>>a;
            if(a>0)
            sum+=a;
        }
        cout<<"Case"<<" "<<i<<":"<<" "<<sum<<endl;
    }
    return 0;
}
