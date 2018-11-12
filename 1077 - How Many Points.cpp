#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(0);cin.tie();
int main()
{
    FastRead;
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        long long int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<"Case "<<cs++<<": "<<__gcd(abs(x2-x1),abs(y1-y2))+1<<"\n";
    }
    return 0;

}
