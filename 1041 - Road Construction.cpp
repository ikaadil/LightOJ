#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
map<string,string> ::iterator itr;
int c;
struct edge
{
    string s1;
    string s2;
    int w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
} e[55];
//vector<edge>e;
set<string>s;
set<string>::iterator it;
string  fin(string r )
{
    return (mp[r]==r)? r : fin(mp[r]);
}
int mst(int n)
{
//    cout<<n<<endl;
    sort(e,e+n);
    for( it=s.begin(); it!=s.end(); it++)
    {
        string g=*it;
        mp[g]=g;
    }

    int  sum = 0;
    for (int i = 0; i < n; i++)
    {
        string u = fin(e[i].s1);
        string v = fin(e[i].s2);
        if (u != v)
        {
            mp[u] = v;
            c++;
            sum += e[i].w;
            if (c == s.size()-1)
                return sum;

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
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            string s1,s2;
            int w;
            cin>>s1>>s2>>w;
          s.insert(s1);
           s.insert(s2);
           e[i].s1=s1;
           e[i].s2=s2;
           e[i].w=w;
        }
        c=0;
        int ans=mst(n);
//        bool flag=0;
//        itr=mp.begin();
//        string check=itr->second;
//        for(itr=mp.begin(); itr!=mp.end(); itr++)
//        {
//            cout<<itr->first<<endl;
//            if(itr->second!=check)
//            {
//                flag=1;
////                break;
//            }
//        }
//        cout<<c<<endl;
//        cout<<s.size()<<endl;
        if(ans!=-1)
            cout<<"Case "<<cs++<<": "<<ans<<"\n";
        else
            cout<<"Case "<<cs++<<": "<<"Impossible\n";
//        for(int i=0;i<(int)e.size();i++)
//        {
//            e[i].clear();
//        }
        mp.clear();
        s.clear();

    }
}
