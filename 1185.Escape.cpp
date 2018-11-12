#include<bits/stdc++.h>
using namespace std;
vector<int>v[210];
int ara[210][3];
void dfs(int x,int y)
{
    if(y!=-1)
        ara[x][y]=1;
    int z=1;
    if(y==1)
        z=2;
    for(int i=0;i<v[x].size();i++)
    {
        if(!ara[v[x][i]][z])dfs(v[x][i],z);
    }
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        for(int i=1;i<=n;i++)
        {
            ara[i][0]=ara[i][1]=ara[i][2]=0;
            v[i].clear();
        }
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1,-1);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
//            cout<<ara[i][0]<<" "<<ara[i][1]<<" "<<ara[i][2]<<endl;
            if(ara[i][2]==1)
                cnt++;
        }
        cout<<"Case "<<cs++<<": "<<cnt<<"\n";;
    }
}
