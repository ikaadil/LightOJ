#include<bits/stdc++.h>
using namespace std;
char s[12][12];
bool  vs[12][12];
int d[12][12];
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
int n,m;
#define  pii pair<int,int>
map<char,pii >mp;
int cnt=0;
int bfs(pii sor,pii dis)
{
    queue<pii>q;
    q.push(sor);
   for(int i=0;i<12;i++)
   {
       for(int j=0;j<12;j++)
       {
           d[i][j]=0;
           vs[i][j]=0;
       }
   }
    vs[sor.first][sor.second]=1;
    while(!q.empty())
    {
        pii u=q.front();
        q.pop();
        if(u==dis)
            return d[u.first][u.second];
        for(int i=0; i<4; i++)
        {
            int x=u.first+dx[i];
            int y=u.second+dy[i];
            if(x>n||y>m||x<1||y<1||vs[x][y]==1||s[x][y]=='#'||s[x][y]>s[dis.first][dis.second]&&s[x][y]!='.')
                continue;
            else
            {
                vs[x][y]=1;
                d[x][y]=d[u.first][u.second]+1;
                q.push(make_pair(x,y));
            }
        }

    }
    return -1;

}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        m=n;
        mp.clear();
        bool flag=0;
        int ans=0,cnt=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>s[i][j];
                if(s[i][j]>='A'&&s[i][j]<='Z')
                {
                    cnt++;
                    mp[s[i][j]]=make_pair(i,j);
                }

            }
        }
        for(int i=0; i<cnt-1; i++)
        {
            int dis=bfs(mp['A'+i],mp['A'+1+i]);
            if(dis==-1)
            {
                flag=1;
//                cout<<(char)'A'+i<<endl;
                break;
            }
            else
                ans+=dis;
        }
        if(flag)
            cout<<"Case "<<cs++<<": Impossible\n";
        else
            cout<<"Case "<<cs++<<": "<<ans<<"\n";
    }

}
