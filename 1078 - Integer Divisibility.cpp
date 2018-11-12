#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        long long n,a,k,cnt=0;
        cin>>n>>a;
        k=a;
        while(k%n!=0)
        {
            cnt++;
            k=k*10+a;
            k%=n;
        }
        cout<<"Case "<<cs++<<": "<<cnt+1<<"\n";
    }
}
