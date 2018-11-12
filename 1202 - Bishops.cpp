#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        long long int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1=abs(x1-x2);
        y1=abs(y1-y2);
        cout<<"Case"<<" "<<i<<":"<<" ";
        if(x1==y1)
        {
            cout<<1<<endl;
        }
        else if(x1%2==y1%2)
            cout<<2<<endl;
        else
            cout<<"impossible"<<endl;
    }
    return 0;
}
