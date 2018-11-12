#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        long long n,ans=0;
        scanf("%lld",&n);
        vector<int>v;
        while(n)
        {
            v.push_back(n%2+0);
             n>>=1;
        }
        v.push_back(0);
        int cnt=0;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]==1)
                cnt++;
            if(v[i]==1&&v[i+1]==0)
            {
                swap(v[i],v[i+1]);
                cnt--;
                for(int j=0; j<i&&cnt; j++)
                {

                    v[j]=1;
                    cnt--;
                }
                break;
            }
            else
                v[i]=0;
        }
        long long x=1;
        for(int i=0; i<v.size(); i--)
        {
            cout<<v[i]<<" ";
            ans+=v[i]*x;
              x<<=1;

        }
        cout<<ans<<"\n";
    }
}
