#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,x,y;
    int t,j=1;
    cin>>t;

    while(t--)
    {
    cin>>n;
    i=ceil(sqrt(n));
    if((i*i)&1)
    {
        if(i*i-n>=i)
        {
            x=i;
            y=n-(i-1)*(i-1);
        }
        else
        {
            x=i*i-n+1;
            y=i;
        }
    }
    else
    {
        if(i*i-n>=i)
        {
            y=i;
            x=n-(i-1)*(i-1);
        }
        else
        {
            x=i;
            y=i*i-n+1;
        }
    }
    cout<<"Case"<<" "<<j++<<":"<<" "<<x<<" "<<y<<"\n";
    }
    return 0;

}
