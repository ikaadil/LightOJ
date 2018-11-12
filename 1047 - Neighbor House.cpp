#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ara[n][3];
        for(int i=0; i<n; i++)
            cin>>ara[i][0]>>ara[i][1]>>ara[i][2];
//            cout<<endl;
        for(int i=1; i<n; i++)
        {
            ara[i][0]+=min(ara[i-1][1],ara[i-1][2]);
            ara[i][1]+=min(ara[i-1][0],ara[i-1][2]);
            ara[i][2]+=min(ara[i-1][1],ara[i-1][0]);
//            cout<<ara[i][0]<<" "<<ara[i][1]<<" "<<ara[i][2]<<endl;
        }
        cout<<"Case "<<cs++<<": "<<min(ara[n-1][0],min(ara[n-1][1],ara[n-1][2]))<<"\n";
    }
}
