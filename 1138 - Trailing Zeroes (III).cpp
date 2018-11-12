#include<bits/stdc++.h>
using namespace std;
int n;
int check(int n)
{
    int rt=0;
    while(n>0)
    {
        rt+=n/5;
        n/=5;
    }
    return rt;
}
int ans(int low,int high)
{
    while(low!=high)
    {
        int mid=(low+high)/2;
        if(check(mid)==n)
        {
            while(check(mid)==n)
                mid--;
            return ++mid;
        }
        else if(check(mid)>n)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}


int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
//        int n;
        cin>>n;

        cout<<"Case "<<cs++<<": ";
        if(ans(0,INT_MAX)==-1)
            cout<<"impossible\n";
        else
            cout << ans(0,INT_MAX) <<"\n";
    }
    return 0;
}
