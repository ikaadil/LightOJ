#include<bits/stdc++.h>
using namespace std;
string s[105][105],s1,s2;
int n;
 void solve()
 {
      n=max(s1.size(),s2.size());
     if(n!=s1.size())
     {
         for(int i=s1.size();i<s2.size();i++)
            s1+='1';
     }
     else
     {
         for(int i=s2.size();i<s1.size();i++)
            s2+='1';
     }

     for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=n;j++)
         {
             if(i==0||j==0)
                s[i][j]="";
             else if(s1[i-1]==s2[j-1])
             {
                 s[i][j]=s[i-1][j-1]+s1[i-1];
             }
             else if(s[i-1][j].size()!=s[i][j-1].size())
                s[i][j]=max(s[i-1][j],s[i][j-1]);
             else if(s[i-1][j].size()==s[i][j-1].size())
             s[i][j]=min(s[i-1][j],s[i][j-1]);
             else
                s[i][j]=s[i][j-1];

         }
     }
 }
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
            s[i][j].clear();
        solve();
        if(s[n][n].size()!=0)
        cout<<"Case "<<cs++<<": "<<s[n][n]<<"\n";
        else
            cout<<"Case "<<cs++<<": :("<<"\n";
    }
}
