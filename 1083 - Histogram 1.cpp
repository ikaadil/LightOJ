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
        int ara[n],ans=0,area;
        for(int i=0; i<n; i++)
            cin>>ara[i];
        stack<int>s;
        int i=0;
        while(i<n)
        {
            if(s.empty())
                s.push(i);
            else if(ara[i]>=ara[s.top()])
                s.push(i++);
            else
            {
                int top=s.top();
                s.pop();
                if(s.empty())
                    area=ara[top]*i;
                else
                    area=ara[top]*(i-s.top()-1);
                ans=max(area,ans);
            }
        }
        while(!s.empty())
        {
            int top=s.top();
            s.pop();
            if(s.empty())
                area=ara[top]*i;
            else
                area=ara[top]*(i-s.top()-1);
            ans=max(area,ans);
        }
        cout<<"Case "<<cs++<<": "<<ans<<"\n";
    }
}
