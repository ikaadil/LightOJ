#include<bits/stdc++.h>
using namespace std;
#define N 1000000
int ara[N];
int tree[4*N];
void built(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=ara[b];
        return ;
    }
    int mid=(b+e)/2;
    built(2*node,b,mid);
    built(2*node+1,mid+1,e);
    tree[node]=tree[2*node]+tree[2*node+1];
}
int query(int node,int b,int e,int i,int j)
{
    if(b>j||e<i) return 0;
    if(b>=i&&e<=j) return tree[node];
    if(b > e)return 0;
    else
    {
        int mid=(b+e)/2;
        return query(2*node,b,mid,i,j)+query(2*node+1,mid+1,e,i,j);
    }
}
void update(int node,int b,int e,int idx,int val)
{
    if(b==e)
    {
        ara[idx]+=val;
        tree[node]+=val;
    }
    else
    {
        int mid=(b+e)/2;
        if(b<=idx&&idx<=mid)
        {
            update(2*node,b,mid,idx,val);
        }
        else
            update(2*node+1,mid+1,e,idx,val);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        memset(ara,0,sizeof(ara));
        memset(tree,0,sizeof(tree));
        for(int i=1; i<=n; i++)
            scanf("%d",&ara[i]);
        built(1,1,n);
        printf("Case %d:\n",cs++);
        while(q--)
        {
            int a;
            scanf("%d",&a);
            if(a==1)
            {
                int b;
                scanf("%d",&b);
                b++;
                printf("%d\n",ara[b]);
                update(1,1,n,b,-ara[b]);
            }
            else if(a==2)
            {
                int b,c;
                scanf("%d %d",&b,&c);
                b++;
                update(1,1,n,b,c);
            }
            else
            {
                int b,c;
                scanf("%d %d",&b,&c);
                b++,c++;

                printf("%d\n",query(1,1,n,b,c));
            }
        }
    }

}
