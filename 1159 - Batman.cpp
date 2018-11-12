#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3;
int ara[52][52][52],a1,a2,a3;
void solve()
{
    a1=s1.size();
    a2=s2.size();
    a3=s3.size();
    for(int i=0; i<=a1; i++)
    {
        for(int j=0; j<=a2; j++)
        {
            for(int k=0; k<=a3; k++)
            {
                if(i==0||j==0||k==0)
                    ara[i][j][k]=0;
                else if(s1[i-1]==s2[j-1]&&s1[i-1]==s3[k-1])
                {
//                    cout<<"amsi\n";
                    ara[i][j][k]=ara[i-1][j-1][k-1]+1;
                }
                else
                    ara[i][j][k]=max(ara[i-1][j][k],max(ara[i][j-1][k],ara[i][j][k-1]));
            }
        }
    }
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2>>s3;
        solve();
        cout<<"Case "<<cs++<<": "<<ara[a1][a2][a3]<<"\n";
    }
}
