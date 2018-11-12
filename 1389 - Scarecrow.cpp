#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,cnt=0;
        cin>>n;
//        vector<int>v(n);
//        for(int i=0;i<n;i++)
//            cin>>v[i];
        string v;
        cin>>v;
        for(int i=0; i<n; i++)
        {
            if(v[i]=='.')
            {
                cnt++;
                i+=2;
            }
        }
        cout<<"Case "<<cs++<<": "<<cnt<<"\n";

    }
}
