#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ara[n];
        for(int i=0; i<n; i++)
            cin>>ara[i];
        int mx[n-k+1],mn[n-k+1];
        deque<int>q,d;
        for(int i=0; i<k; i++)
        {
            while(!q.empty()&&ara[i]>=ara[q.back()])
                q.pop_back();
            q.push_back(i);
            while(!d.empty()&&ara[i]<=ara[d.back()])
                d.pop_back();
            d.push_back(i);

        }
        for(int i=k; i<n; i++)
        {
            mx[i-k]=ara[q.front()];
            mn[i-k]=ara[d.front()];
            while(!q.empty()&&ara[i]>=ara[q.back()])
                q.pop_back();
            while(!d.empty()&&ara[i]<=ara[d.back()])
                d.pop_back();
            while(!q.empty()&&q.front()<=i-k)
                q.pop_front();
            while(!d.empty()&&d.front()<=i-k)
                d.pop_front();
            d.push_back(i);
            q.push_back(i);

        }
        mx[n-k]=ara[q.front()];
        mn[n-k]=ara[d.front()];
//        for(int i=0; i<=n-k; i++)
//            cout<<mx[i]<<" ";
//        cout<<endl;
//        for(int i=0; i<=n-k; i++)
//            cout<<mn[i]<<" ";
//        cout<<endl;
        int ans=-1;
        for(int i=0; i<=n-k; i++)
        {
            ans=max(ans,mx[i]-mn[i]);
        }
        cout<<"Case "<<cs++<<": "<<ans<<"\n";
    }
}
