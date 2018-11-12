#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cout<<"Case"<<" "<<i<<":"<<endl;
        int n;
        cin>>n;
        int k,j,sum=0;
        for(j=1; j<=n; j++)
        {
            char s[20];
            cin>>s;
            if(s[0]=='d')
            {
                cin>>k;
                sum+=k;
            }
            else cout<<sum<<endl;
        }
    }
    return 0;
}
