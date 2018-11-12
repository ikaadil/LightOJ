#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        double a,b,c,m;
        cin>>a>>b>>c>>m;
//        cout<<"Case"<<" "<<i<<":"<<" "<<a*sqrt(m/(m+1))<<endl;
        printf("Case %d: %f\n",i,a*sqrt(m/(m+1)));
    }
    return 0;
}
