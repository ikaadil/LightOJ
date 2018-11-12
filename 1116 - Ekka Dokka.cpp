#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,even,w;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>w;
        if(w%2)
            cout<<"Case"<<" "<<i<<":"<<" "<<"Impossible"<<endl;
        else
        {
            even=1;
            while(w%2==0)
            {
                even*=2;
                w/=2;
            }
            cout<<"Case"<<" "<<i<<":"<<" "<<w<<" "<<even<<endl;
        }
    }
    return 0;
}
