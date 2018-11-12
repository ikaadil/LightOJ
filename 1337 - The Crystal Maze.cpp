#include<bits/stdc++.h>
using namespace std;
#define FastRead        ios_base::sync_with_stdio(0);cin.tie();
int a[501][501];
char ch[501][501];
int cost[501][501];
int cnt;
int w,h,x;
int bfs(int i,int j)
{
    if(i+1<=w&&!a[i+1][j]&&ch[i+1][j]!='#')
    {
        a[i+1][j]=1;
        if(ch[i+1][j]=='C')
            cnt++;
        bfs(i+1,j);
    }
    if(i-1>=1&&!a[i-1][j]&&ch[i-1][j]!='#')
    {
        a[i-1][j]=1;
        if(ch[i-1][j]=='C')
            cnt++;
        bfs(i-1,j);
    }
    if(j+1<=h&&!a[i][j+1]&&ch[i][j+1]!='#')
    {
        a[i][j+1]=1;
        if(ch[i][j+1]=='C')
            cnt++;
        bfs(i,j+1);
    }
    if(j-1>=1&&!a[i][j-1]&&ch[i][j-1]!='#')
    {
        a[i][j-1]=1;
        if(ch[i][j-1]=='C')
            cnt++;
        bfs(i,j-1);
    }
    return cnt;
}
int main()
{
//    ios::sync_with_stdio(false);
    FastRead;
    int cs=1,t;
    cin>>t;
    while(t--)
    {
//        int w,h;
        cin>>w>>h>>x;
//        int p,q;
        for(int i=1; i<=w; i++)
        {
            for(int j=1; j<=h; j++)
            {
                cin>>ch[i][j];
//                if(ch[i][j]=='@')
//                {
//                    cnt=1;
//                    p=i;
//                    q=j;
//                }
            }
        }
        for(int i=1; i<=w; i++)
        {
            for(int j=1; j<=h; j++)
            {
                cost[i][j]=-1;
            }
        }
        cout<<"Case "<<cs++<<":\n";
        while(x--)
        {
            int p,q;
            cin>>p>>q;

            //            for(int i=1; i<=w; i++)
//            {
//                for(int j=1; j<=h; j++)
//                {
//                    a[i][j]=0;
//                }
//            }
            if(cost[p][q]==-1)
            {
                for(int i=1; i<=w; i++)
                {
                    for(int j=1; j<=h; j++)
                    {
                        a[i][j]=0;
                    }
                }
                a[p][q]=1;
                cnt=0;

                cout<<bfs(p,q)<<"\n";
                for(int i=1; i<=w; i++)
                {
                    for(int j=1; j<=h; j++)
                    {
                        if(a[i][j])
                        {
                            cost[i][j]=cnt;
                        }
                    }
                }
            }
            else cout<<cost[p][q]<<"\n";

        }
    }
    return 0;
}

