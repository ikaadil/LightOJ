#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        string s,r;
        cin>>s;
        r=s;
        reverse(r.begin(),r.end());
        if(r!=s)
            printf("Case %d: No\n",i);
        else
            printf("Case %d: Yes\n",i);

    }
    return 0;
}
