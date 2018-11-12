#include<bits/stdc++.h>
using namespace std;
int adu(int a[],int l,int h,int value)
{
    int mid,ans=l-1;

    while(l<=h)
    {
        mid=(l+h)/2;
        if(a[mid]<value){
            ans=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    return ans;

}
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n,cnt=0;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)cin>>a[i];
        sort(a,a+n);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                cnt+=adu(a,j,n-1,a[i]+a[j])-j;
            }
        }
        cout<<"Case"<<" "<<i<<":"<<" "<<cnt<<endl;
    }
    return 0;
}
