#include<bits/stdc++.h>
using namespace std;
int binary(int n)
{
    int r,i=1,binary=0;
    while(n!=0)
    {
        r=n%2;
        n=n/2;
        binary+=r*i;
        i*=10;
    }
    return binary;

}
int main()
{
    int t,i;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        int a,b,c,d,e,f,g,h;
        char m;
        cin>>a>>m>>b>>m>>c>>m>>d;
        e=binary(a);
        f=binary(b);
        g=binary(c);
        h=binary(d);
        int x,y,p,q;
           cin>>x>>m>>y>>m>>p>>m>>q;
        if(e==x&&f==y&&g==p&&h==q)
            cout<<"Case"<<" "<<i<<":"<<" "<<"Yes"<<endl;
        else
            cout<<"Case"<<" "<<i<<":"<<" "<<"No"<<endl;
    }
    return 0;
}
