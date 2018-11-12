#include<bits/stdc++.h>
using namespace std;
int cost[21][21];
char ch[21][21];
bool visited[21][21];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void bfs(int x,int y,int r,int c)
{
    int ux,uy,vx,vy;
    queue<int>q;
    visited[x][y]=true;
    cost[x][y]=0;
    q.push(x);
    q.push(y);
    while(!q.empty())
    {
        ux=q.front();
        q.pop();
        uy=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            vx=ux+dx[i];
            vy=uy+dy[i];

//                    cout<<"vx:"<<vx<<" vy:"<<vy<<endl;
            if(vx>=0&&vx<r&&vy>=0&&vy<c&&ch[vx][vy]!='#'&&ch[vx][vy]!='m')
            {
                if(!visited[vx][vy])
                {
                    cost[vx][vy]=cost[ux][uy]+1;
                    visited[vx][vy]=true;
                    q.push(vx);
                    q.push(vy);
                }

            }
        }

    }


}
int main()
{
    int cs=1,t;
    cin>>t;
    while(t--){
        int r,c,ax,ay,bx,by,cx,cy,hx,hy;
        memset(cost,0,sizeof cost);
        memset(visited,0,sizeof visited);

        cin>>r>>c;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]=='a')
                {
                    ax=i;
                    ay=j;
                }
                else  if(ch[i][j]=='b')
                {
                    bx=i;
                    by=j;
                }
                else  if(ch[i][j]=='c')
                {
                    cx=i;
                    cy=j;
                }
                else  if(ch[i][j]=='h')
                {
                    hx=i;
                    hy=j;
                }
            }
        }
        bfs(hx,hy,r,c);
//        for(int i=0;i<21;i++)
//        {
//            cout<<endl;
//            for(int j=0;j<21;j++)
//                cout<<cost[i][j]<<" ";
//        }
        int maxi=0;
        maxi=max(maxi,cost[ax][ay]);
//        cout<<"a:"<<maxi<<endl;
        maxi=max(maxi,cost[bx][by]);
//        cout<<"b:"<<maxi<<endl;
        maxi=max(maxi,cost[cx][cy]);
//        cout<<"c:"<<maxi<<endl;
       cout<<"Case "<<cs++<<": "<<maxi<<"\n";


    }
    return 0;
}
