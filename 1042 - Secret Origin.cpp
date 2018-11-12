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
        while(n)
        {
            if(n%2)
                cnt++;
            n=n/2;
        }
        cout<<cnt<<endl;
    }
}
