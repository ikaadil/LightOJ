#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(0);cin.tie();
int fac(int a,int b)
{
    int ans=0;
    while(a>0)
    {
        ans+=a/b;
        a=a/b;
    }
    return ans;
}
int p_r(int a,int b)
{
    int cnt=0;
    while(a>0&&a%b==0)
    {
        cnt++;
        a=a/b;
    }
    return cnt;
}
int cal(int n,int r,int p,int q)
{
    int cnt_2=fac(n,2)-fac(n-r,2)-fac(r,2)+(p_r(p,2))*q;
    int cnt_5=fac(n,5)-fac(n-r,5)-fac(r,5)+(p_r(p,5))*q;
    return min(cnt_2,cnt_5);

}
int main()
{
    FastRead ;
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,r,p,q;
        cin>>n>>r>>p>>q;
        int ans=cal(n,r,p,q);
        cout<<"Case "<<cs++<<": "<<ans<<"\n";
    }
}
