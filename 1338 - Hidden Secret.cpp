#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    scanf("%d\n",&t);
    while(t--)
    {
        string s,s1;
        char c;
        string a="",b="";
//        cin>>c;
        getline(cin,s);


//        cout<<s<<"\n";
        getline(cin,s1);

//        cout<<s1<<"\n";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!=32)
                a+=tolower(s[i]);
        }
        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i]!=32)
                b+=tolower(s1[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
//        cout<<a<<" "<<b<<"\n";
        if(a==b)
            cout<<"Case "<<cs++<<": "<<"Yes\n";
        else
            cout<<"Case "<<cs++<<": "<<"No\n";
    }
}
