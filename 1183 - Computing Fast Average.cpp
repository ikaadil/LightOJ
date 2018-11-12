#include<bits/stdc++.h>
using namespace std;
#define N 100005
long long tree[4*N];
long long lazy[4*N];
void update(int node,int start,int end,int l,int r,int v)
{
    if(start>r||end<l)
        return;
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(l<=start&&end<=r)
    {
        tree[node]=(end-start+1)*v;
        if(start!=end)
        {
            lazy[2*node]=v;
            lazy[2*node+1]=v;
        }
        return;
    }
    int mid=(start+end)/2;
    update(2*node,start,mid,l,r,v);
    update(2*node+1,mid+1,end,l,r,v);
    tree[node]=tree[2*node]+tree[2*node+1];
}
long long query(int node,int start,int end,int l,int r)
{
    if(start>r||end<l)
        return 0;
    if(l<=start&&end<=r)
        return tree[node];
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    int mid=(start+end)/2;
    long long p1=query(2*node,start,mid,l,r);
    long long p2=query(2*node+1,mid+1,end,l,r);
    return p1+p2;
}
int main()
{
    int n,q;
    cin>>n>>q;
    while(q--)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int x,y,z;
            cin>>x>>y>>z;
            x++,y++;
            update(1,1,n,x,y,z);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            x++;
            y++;
            cout<<query(1,1,n,x,y)<<"\n";
        }
    }
}
