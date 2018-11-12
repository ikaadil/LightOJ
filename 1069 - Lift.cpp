#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,a,b;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>a>>b;
        if(a>b)
            cout<<"Case"<<" "<<i<<":"<<" "<<(a-b)*4+a*4+19<<endl;
        else
            cout<<"Case"<<" "<<i<<":"<<" "<<b*4+19<<endl;
    }
    return 0;
}

