#include<bits/stdc++.h>
using namespace std;
int a[21][21];
char ch[21][21];
int cnt;
int w,h;
int bfs(int i,int j)
{
    if(i+1<h&&!a[i+1][j]&&ch[i+1][j]=='.')
    {
        a[i+1][j]=1;
        cnt++;
        bfs(i+1,j);
    }
     if(i-1>=0&&!a[i-1][j]&&ch[i-1][j]=='.')
    {
        a[i-1][j]=1;
        cnt++;
        bfs(i-1,j);
    }
    if(j+1<w&&!a[i][j+1]&&ch[i][j+1]=='.')
    {
        a[i][j+1]=1;
        cnt++;
        bfs(i,j+1);
    }
    if(j-1>=0&&!a[i][j-1]&&ch[i][j-1]=='.')
    {
        a[i][j-1]=1;
        cnt++;
        bfs(i,j-1);
    }
    return cnt;
}
int main()
{
    int cs=1,t;
    cin>>t;
    while(t--)
    {
//        int w,h;
        cin>>w>>h;
        int p,q;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]=='@')
                {
                    cnt=1;
                    p=i;
                    q=j;
                }
            }
        }
        memset(a, 0, sizeof(a));
        a[p][q]=1;

        cout<<"Case "<<cs++<<": "<<bfs(p,q)<<"\n";

    }
    return 0;
}
