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
        int a[n+1];
        for(int i=1; i<=n; i++)
            cin>>a[i];
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(j!=a[j])
                {
                    cnt++;
                    swap(a[j],a[a[j]]);
//                    for(int i=1; i<=n; i++)
//                        cout<<a[i]<<" ";
//                    cout<<endl;
                }

            }
        }
        cout<<"Case "<<cs++<<": "<<cnt<<"\n";;
    }
}
