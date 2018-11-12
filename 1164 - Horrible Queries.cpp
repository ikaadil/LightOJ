#include<bits/stdc++.h>
using namespace std;
#define N 100005
int ara[N];
long long int tree[4*N];
long long int lazy[4*N];
void range_update(int node,int b,int e,int l,int r,int val)
{
    if(e<l||b>r)
        return ;
    if(lazy[node]!=0)
    {
        tree[node]+=(e-b+1)*lazy[node];
        if(b!=e)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(b>=l&&e<=r)
    {
        tree[node]+=(e-b+1)*val;
        if(b!=e)
        {
            lazy[node*2]+=val;
            lazy[2*node+1]+=val;
        }
        return ;
    }
    int mid=(b+e)/2;
    range_update(node*2,b,mid,l,r,val);
    range_update(node*2+1,mid+1,e,l,r,val);
    tree[node]=tree[node*2]+tree[node*2+1];

}
long long int range_query(int node,int b,int e,int l,int r)
{
     if(e<l||b>r)
        return 0 ;
    if(lazy[node]!=0)
    {
        tree[node]+=(e-b+1)*lazy[node];
        if(b!=e)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(b>=l&&e<=r)
    {
        return tree[node];
    }
    int mid=(b+e)/2;
    long long int p1=range_query(node*2,b,mid,l,r);
    long long int p2=range_query(node*2+1,mid+1,e,l,r);
    return p1+p2;


}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
//    for(int i=1; i<=n; i++)
//        cin>>ara[i];
//    built(1,1,n);
        printf("Case %d:\n",cs++);
        memset(ara,0,sizeof(ara));
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        while(q--)
        {
            int a;
            cin>>a;
            if(a==0)
            {
                int x,y,v;
                scanf("%d %d %d",&x,&y,&v);
                x++;
                y++;
                range_update(1,1,n,x,y,v);
            }
            else
            {
                int x,y;
                scanf("%d %d",&x,&y);
                x++;
                y++;
                printf("%lld\n",range_query(1,1,n,x,y));
            }
        }
    }
}
