#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define N 1000001
ull h[N];
ull p[N];
char s[N],s1[N];
int a,b;
//int base=1167003;
int base=1167003;
ull match;
ull seg(int x,int y)
{
    return h[y]-h[x-1]*p[y-x+1];
}
int main()
{
    p[0]=1;
    for(int i=1; i<N; i++)
        p[i]=p[i-1]*base;
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        scanf("%s %s",s+1,s1+1);
        a=strlen(s+1);
        b=strlen(s1+1);
        int cnt=0;
        for(int i=1; i<=a; i++)
            h[i]=h[i-1]*base+s[i];
        match=0;
        for(int i=1; i<=b; i++)
            match=match*base+s1[i];
//            cout<<match<<endl;
        for(int i=b; i<=a; i++)
        {
            if(seg(i-b+1,i)==match)
                cnt++;
        }
        cout<<"Case "<<cs++<<": "<<cnt<<"\n";;
    }
}
