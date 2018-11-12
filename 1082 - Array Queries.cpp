

#include<bits/stdc++.h>
using namespace std;
int n,q;
int ara[1000005];
int tree[1000005];
void built(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=ara[b];
        return;
    }
    int mid=(b+e)>>1;
    int lt=node<<1;
    int rt=lt|1;
    built(lt,b,mid);
    built(rt,mid+1,e);
    tree[node]=min(tree[lt],tree[rt]);
}
//int query(int node,int b,int e,int i,int j)
//{
//    if(b>j||e<i) return 1234567;
//    if(b>=i&&e<=j)return tree[node];
//    int mid=(b+e)>>1;
//    int lt=node<<1;
//    int rt=lt|1;
//    return min(query(lt,b,mid,i,j),query(rt,mid+1,e,i,j));
//}
int main()
{

    int t,cs=1;
    cin>>t;
    while(t--)
    {

//        memset(ara,0,sizeof(ara));
//        memset(tree,0,sizeof(tree));
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
         scanf("%d",&ara[i]);
        printf("Case %d: ",cs++);
        built(1,1,n);
        cout<<tree[1]<<"\n";
//        for(int i=1; i<=n; i++)
//            cout<<tree[i]<<" ";

//        while(q--)
//        {
//            int x,y;
//            scanf("%d %d",&x,&y);
//            printf("%d\n",query(1,1,n,x,y));
//        }
    }

}

