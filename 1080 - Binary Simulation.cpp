#include<bits/stdc++.h>
using namespace std;
#define N 100001
char s[N];
int lazy[N*4];
void update(int node,int l,int r,int a,int b)
{
    if(r<a||l>b) return;
    if(l>=a&&l<=b)
    {
        lazy[node]++;
        return;
    }
    int mid=(l+r)/2;
    update(2*node,l,mid,a,b);
    update(2*node+1,mid+1,r,a,b);
}
void query(int node,int l,int r,int p)
{
    if(lazy[node])
    {
        if(l!=r)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
            lazy[node]=0;
        }
    }
    if(p>r||p<l) return;
    if(l==r)
    {
        if(lazy[node]%2)
        {
            if(s[l]=='1')s[l]='0';
            else
                s[l]='1';
        }
        lazy[node]=0;
        return;
    }
    int mid=(l+r)/2;
    query(2*node,l,mid,p);
    query(2*node+1,mid+1,r,p);
}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s",s);
        int n=strlen(s);
        int q;
        printf("Case :%d\n",cs++);
        scanf(" %d",&q);
        while(q--)
        {
            char c;
            scanf(" %c",&c);

            if(c=='I')
            {
                int a,b;
                scanf(" %d %d",&a,&b);
                update(1,0,n-1,a-1,b-1);
            }
            else
            {
                int p;
                scanf(" %d",&p);
                query(1,0,n-1,p-1);
                printf("%c\n",s[p-1]);
            }
        }
    }
}
